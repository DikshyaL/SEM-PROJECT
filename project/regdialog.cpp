#include "regdialog.h"
#include "ui_regdialog.h"
#include "mainwindow.h"
#include "listdialog.h"
#include <QMessageBox>

regDialog::regDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regDialog)
{
    ui->setupUi(this);
}

regDialog::~regDialog()
{
    delete ui;
}

void regDialog::on_pushbutton_reg_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Registration", "Please enter both username and password");
        return;
    }

    QSqlQuery qry;
    QSqlQuery qy;

    if (qry.exec("SELECT * FROM login WHERE username='" + username + "'")) {
        int count = 0;

        while (qry.next()) {
            count++;
        }

        if (count == 0) {

            qy.prepare("INSERT INTO login (username, password) VALUES ('" + username + "','" + password + "')");

            if (qy.exec()) {

                QSqlQuery query;
                QString queryString = "CREATE TABLE IF NOT EXISTS " + username + " ("
                                                                                 "food INTEGER DEFAULT 0, "
                                                                                 "laundry INTEGER DEFAULT 0, "
                                                                                 "entertainment INTEGER DEFAULT 0,"
                                                                                 "miscellaneous INTEGER DEFAULT 0,"
                                                                                 "total INTEGER DEFAULT 0)";

                if (query.exec(queryString)) {
                    qDebug() << "Table created successfully for user: " << username;

                    // Insert an initial row with zero values
                    QString insertRowQuery = "INSERT INTO " + username + " (food, laundry, entertainment, miscellaneous,total) "
                                                                         "VALUES (0, 0, 0, 0, 0)";

                    if (query.exec(insertRowQuery)) {
                        qDebug() << "Initial row added successfully for user: " << username;
                    } else {
                        qDebug() << "Failed to add initial row. Error:" << query.lastError().text();
                    }

                    hide();
                    listdialog = new listDialog(this, username);
                    mainwindow = new MainWindow(this, username);
                    mainwindow->show();
                } else {
                    qDebug() << "Could not create table. Error:" << query.lastError().text();
                }
            } else {
                QMessageBox::warning(this, "Registration", "Failed to register user");
            }
        } else {
            QMessageBox::information(this, "Registration", "Username already exists");
        }
    } else {
        qDebug() << "Query failed: " << qry.lastError().text();
    }
}
