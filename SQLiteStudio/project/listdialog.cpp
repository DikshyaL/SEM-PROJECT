#include "listdialog.h"
#include "ui_listdialog.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
extern QSqlDatabase mydb;

listDialog::listDialog(QWidget *parent, const QString &username, const QString &groupname)
    : QDialog(parent),
    ui(new Ui::listDialog),
    adddialog(nullptr),
    profiledialog(nullptr),
    secdialog(nullptr),
    calcdialog(nullptr),
    username(username),
    groupname(groupname)
{
    ui->setupUi(this);
    qDebug() << "Username passed to listDialog: " << username;
}

listDialog::~listDialog()
{
    delete ui;
}

QString listDialog::getCurrentUser() const
{
    return username;
}

void listDialog::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    displayCategoryValues();
}
void listDialog::displayCategoryValues()
{
    QSqlQuery query(mydb);
    QString tableName = QString("%1").arg(username);
    QString selectValuesQuery = QString("SELECT food, laundry, miscellaneous, entertainment FROM %1").arg(tableName);

    qDebug() << "Final SQL Query:" << selectValuesQuery;

    if (query.exec(selectValuesQuery)) {
        if (query.next()) {
            QSqlRecord record = query.record();


            double food = record.value("food").toDouble();
            double laundry = record.value("laundry").toDouble();
            double miscellaneous = record.value("miscellaneous").toDouble();
            double entertainment = record.value("entertainment").toDouble();
            double total = record.value("total").toDouble();

            // Update the corresponding labels with the fetched values
            ui->label_food->setText(QString::number(food));
            ui->label_laundry->setText(QString::number(laundry));
            ui->label_miscellaneous->setText(QString::number(miscellaneous));
            ui->label_entertainment->setText(QString::number(entertainment));
            ui->label_total->setText(QString::number(total));

        } else {
            qDebug() << "No records found for the query.";
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}


void listDialog::on_pushbutton_food_clicked()
{
    adddialog = new addDialog(this, this, getCurrentUser());
    adddialog->setCategory("food");
    adddialog->show();
}


void listDialog::on_pushbutton_mis_clicked()
{
    adddialog = new addDialog(this, this,getCurrentUser());
    adddialog->setCategory("miscellaneous");
    adddialog->show();
}

void listDialog::on_pushbutton_laundry_clicked()
{
    adddialog = new addDialog(this, this,getCurrentUser(),groupname);
    adddialog->setCategory("laundry");
    adddialog->show();
}

void listDialog::on_pushbutton_enter_clicked()
{
    adddialog = new addDialog(this, this,getCurrentUser(), groupname);
    adddialog->setCategory("entertainment");
    adddialog->show();
}

void listDialog::on_pushbutton_profile_clicked()
{
    hide();
    profiledialog = new profileDialog(this, username, groupname);
    profiledialog->show();
}

void listDialog::on_pushbutton_home_clicked()
{
    hide();
    secdialog = new secDialog(this, username, groupname);
    secdialog->show();
}


void listDialog::on_pushbutton_calc_clicked()
{
    hide();
    calcdialog = new calcDialog(this, username, groupname);
    calcdialog->show();
}
