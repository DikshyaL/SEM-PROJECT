#include "regdialog.h"
#include "ui_regdialog.h"
#include"mainwindow.h"
#include"QMessageBox"
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
    QString username= ui-> lineEdit->text();
    QString password= ui-> lineEdit_2->text();

    QSqlQuery qry;
    QSqlQuery qy;
    if(qry.exec("select * from login where username='"+ username +"'"))
    {
        int count;
        while(qry.next())
        {
            count++;
        }
        if(count!=1)
        {
            qy.prepare("insert into login(username, password) values('"+username+"','"+password+"')");
        }
        if (qy.exec()) {
            hide();
            mainwindow = new MainWindow(this);
            mainwindow->show();
        } else {
            QMessageBox::warning(this, "Registration", "Error executing insert query");
        }
    }
    else
    {
        QMessageBox::information(this, "Registration", "Username already exists");
    }



}
