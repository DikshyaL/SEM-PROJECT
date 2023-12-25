// adddialog.cpp
#include "adddialog.h"
#include "ui_adddialog.h"
#include "listdialog.h"
#include <QSqlQuery>
#include <QDebug>

addDialog::addDialog(QWidget *parent, listDialog *listDialogParent, const QString &username) :
    QDialog(parent),
    ui(new Ui::addDialog),
    listdialog(listDialogParent),
    username(username),
    transactionActive(false)
{
    ui->setupUi(this);
}

addDialog::~addDialog()
{
    delete ui;
}

void addDialog::setCategory(const QString &category)
{
    this->category = category;
}

void addDialog::on_pushbutton_done_clicked()
{
    int value = ui->lineEdit_2->text().toInt();

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isValid()) {
        qDebug() << "Database connection is not valid.";
        return;
    }

    QString columnName = category;
    QString tableName = username;

    if (!tableName.isEmpty()) {
        QSqlQuery query(db);

        if (!transactionActive && db.transaction()) {
            transactionActive = true;
            qDebug() << "Transaction started.";
        }

        QString queryString = "UPDATE " + tableName + " SET " + columnName + " = " + columnName + " + :value";
        qDebug() << "Executing query: " << queryString;
        qDebug() << "Value: " << value;

        query.prepare(queryString);
        query.bindValue(":value", value);

        if (query.exec()) {
            qDebug() << columnName << " value updated successfully for user: " << tableName;

            // Commit the transaction
            if (transactionActive && db.commit()) {
                transactionActive = false;
                qDebug() << "Transaction committed.";
            } else {
                qDebug() << "Transaction commit failed. Error:" << db.lastError().text();
            }
        } else {
            qDebug() << "Failed to update " << columnName << " value. Error:" << query.lastError().text();


            if (transactionActive && !db.rollback()) {
                qDebug() << "Transaction rollback failed. Error:" << db.lastError().text();
            }

            transactionActive = false;
        }
    } else {
        qDebug() << "Username is empty. Cannot execute query.";
    }

    hide();
}
