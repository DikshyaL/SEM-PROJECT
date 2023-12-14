#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   mydb=QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("C:/Users/diksh/ArthaBhaag/database.db");
   if(!mydb.open())
       ui->label->setText("failed to open");
   else
       ui->label->setText("Welcome");
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
        int count;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            hide();
            secdialog = new secDialog(this);
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
