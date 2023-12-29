#include "profiledialog.h"
#include "ui_profiledialog.h"
#include"secdialog.h"
#include"listdialog.h"

profileDialog::profileDialog(QWidget *parent, const QString &username, const QString &groupname) :
    QDialog(parent),
    ui(new Ui::profileDialog),
   listdialog(nullptr),
    calcdialog(nullptr),
    secdialog(nullptr),
    username(username),
    groupname(groupname)

{
    ui->setupUi(this);
    ui->label->setText(username);
    ui->label_4->setText(username);

}

profileDialog::~profileDialog()
{
    delete ui;
}

void profileDialog::on_pushbutton_list_clicked()
{
    hide();
    listdialog = new listDialog(this,username, groupname);
    listdialog ->show();
}
void profileDialog::on_pushbutton_expenses_clicked()
{
    hide();
    listdialog = new listDialog(this,username, groupname);
    listdialog ->show();
}
void profileDialog::on_pushbutton_calc_clicked()
{
    hide();
    calcdialog = new calcDialog(this, username,groupname);
    calcdialog ->show();
}
void profileDialog::on_pushbutton_home_clicked()
{
    hide();
    secdialog = new secDialog(this, username, groupname);
    secdialog ->show();
}
