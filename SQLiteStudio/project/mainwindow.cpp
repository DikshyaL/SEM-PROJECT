#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"listdialog.h"
#include"regdialog.h"
#include"secdialog.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent,const QString &username)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    secdialog(nullptr),
    regdialog(nullptr),
    listdialog(nullptr),
    username(username)
{
   ui->setupUi(this);

   mydb = QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("C:/Users/diksh/ArthaBhaag/database.db");

   if (!mydb.open()) {
       qDebug() << "Failed to open the database:" << mydb.lastError().text();
       ui->label->setText("Failed to open the database");

   } else {
       ui->label->setText("Welcome to ARTHABHAAG");
   }
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushbutton_login_clicked()
{
    QString username= ui-> lineEdit->text();
    QString password= ui-> lineEdit_2->text();
    if(!mydb.isOpen())
    {
        qDebug()<<"failed to oppen database";
        return;

    }
    QSqlQuery qry;
    if(qry.exec("select * from login where username='"+ username +"' and password='"+ password +"'"))
    {
        int count = 0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            hide();
            qDebug() << "Username extracted from the database: " << username;
            listdialog = new listDialog(this, username);
            secdialog = new secDialog(this,username);
            secdialog ->show();
        }
        if(count<1)
        {
             QMessageBox::warning(this, "login","username and password is not correct");
        }

    }

}
void MainWindow::on_pushbutton_reg_clicked()
{
    hide();
    regdialog = new regDialog(this);
    regdialog ->show();

}
