// calcdialog.cpp
#include "calcdialog.h"
#include "ui_calcdialog.h"
#include "profiledialog.h"
#include "listdialog.h"
#include "secdialog.h"
#include "transdialog.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

calcDialog::calcDialog(QWidget *parent, const QString &username, const QString &groupname)
    : QDialog(parent),
    ui(new Ui::calcDialog),
    username(username),
    groupname(groupname),
    profiledialog(nullptr),

    listdialog(nullptr),
    secdialog(nullptr),
    transdialog(nullptr)
{
    ui->setupUi(this);

    // Fetch and display user information from the database
    displayUserInfo();
    connect(ui->spinBox_member, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox_member_valueChanged(int)));
}

calcDialog::~calcDialog()
{
    delete ui;
}

void calcDialog::on_pushbutton_profile_clicked()
{
    hide();
    profiledialog = new profileDialog(this, username);
    profiledialog->show();
}

void calcDialog::on_pushbutton_home_clicked()
{
    hide();
    secdialog = new secDialog(this, username);
    secdialog->show();
}

void calcDialog::on_pushbutton_trans_clicked()
{
    transdialog = new transDialog(this, username, groupname);
    transdialog->show();
}


void calcDialog::on_pushbutton_list_clicked()
{
    hide();
    listdialog = new listDialog(this, username);
    listdialog->show();
}
void calcDialog::displayUserInfo()
{
    QSqlQuery query(mydb);
    QString tableName = QString("%1_groups_%2").arg(username, groupname);
    QString selectUserInfoQuery = QString("SELECT total,mean FROM %1").arg(tableName);



    qDebug() << "Final SQL Query:" << selectUserInfoQuery;

    if (query.exec(selectUserInfoQuery)) {
        if (query.next()) {
            QSqlRecord record = query.record();
            int totalIndex = record.indexOf("total");
            int meanIndex = record.indexOf("mean");
            if (meanIndex != -1) {
            double mean = query.value(meanIndex).toDouble();
            ui->label_mean->setText(QString::number(mean));
            }
            else {
            qDebug() << "Error: 'mean' column not found in the table.";
            }

            if (totalIndex != -1) {
                double total = query.value(totalIndex).toDouble();

                qDebug() << "Fetched total value:" << total;

                // Get the number of members
                int n = getNumberOfMembers(username, groupname);

                // Update UI labels with the fetched values
                ui->label_members->setText(QString::number(n));
                ui->label_total->setText(QString::number(total));
                ui->label_g->setText(groupname);

                qDebug() << "Number of Members:" << n;
                qDebug() << "Total Value:" << total;
                qDebug() << "Group Name:" << groupname;
            } else {
                qDebug() << "Error: 'total' column not found in the table.";
            }
        } else {
            qDebug() << "No records found for the query.";
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}


int calcDialog::getNumberOfMembers(const QString &username, const QString &groupname)
{
    QSqlQuery query(mydb);
    QString groupTableName = QString("%1_groups_%2").arg(username, groupname);

    QString selectGroupInfoQuery = QString("PRAGMA table_info(%1)").arg(groupTableName);

    if (query.exec(selectGroupInfoQuery)) {
        int numMembers = 0;
        while (query.next()) {
            QString columnName = query.value("name").toString();
            if (columnName != "id" && columnName != "total" && columnName != "mean" && columnName != "group_name") {
                numMembers++;
            }
        }
        return numMembers;
    }

    qDebug() << "Error fetching table information:" << query.lastError().text();
    return -1;
}

void calcDialog::on_pushbutton_g_clicked()
{
    QString newGroupname = ui->lineEdit_groupname->text();

    // Check if the groupname is not empty before creating a new dialog
    if (!newGroupname.isEmpty()) {
        // Create a new calcDialog with the updated groupname
        calcDialog *newCalcDialog = new calcDialog(this, username, newGroupname);

        // Close the current dialog
        close();

        // Show the new calcDialog
        newCalcDialog->show();
    } else {
        qDebug() << "Error: Groupname is empty.";
    }
}
void calcDialog::on_spinBox_member_valueChanged(int value)
{
    int totalMembers = getNumberOfMembers(username, groupname);

    if (value > totalMembers) {

        QMessageBox::warning(this, "Invalid Member Number", "Entered member number exceeds the total number of members in the group.");
        ui->label_pay->clear();
    } else {

        QString tableName = QString("%1_groups_%2").arg(username, groupname);
        QString columnName = QString("member%1").arg(value);
        QString selectAmountQuery = QString("SELECT %1 FROM %2 LIMIT 1 OFFSET 1").arg(columnName,tableName);

        QSqlQuery query(mydb);
        if (query.exec(selectAmountQuery))
        {
            if( query.next()) {
            double amount = query.value(0).toDouble();
            ui->label_pay->setText(QString("%1").arg(amount));
        } else {
            qDebug() << "Error fetching amount information:" << query.lastError().text();
        }
        }
        else {
        qDebug() << "Error fetching amount information:" << query.lastError().text();
        }
}
}
