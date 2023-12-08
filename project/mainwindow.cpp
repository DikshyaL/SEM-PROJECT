#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DBConnection= QSqlDatabase::addDatabase("QSQLITE");
    DBConnection.setDatabaseName(QCoreApplication::applicationDirPath()+"/database.db");
    if(DBConnection.open())
    {
        qDebug()<<"Database is connected";
    }
    else
    {
        qDebug()<<"Database is not connected";
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
    if(username =="test" && password=="test")
    {

        hide();
        secdialog = new secDialog(this);
        secdialog ->show();
    }
    else
    {
        QSqlQuery QueryGetUser(DBConnection);
        QueryGetUser.prepare("SELECT * FROM login WHERE username="+username+"AND userpassword="+password);
        if(QueryGetUser.exec())
        {
            int userfindcount = 0;
            while(QueryGetUser.next())
            {
                userfindcount = userfindcount + 1;
            }
            if(userfindcount ==1)
            {
                QMessageBox::information(this, "login","username and password is not correct");
            }
            else if(userfindcount==0);
            {
                this->hide();
                secdialog = new secDialog(this);
                secdialog ->show();
            }
        }
        else
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
