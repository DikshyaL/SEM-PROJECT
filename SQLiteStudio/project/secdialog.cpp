#include "secdialog.h"
#include "ui_secdialog.h"

secDialog::secDialog(QWidget *parent,const QString &username, const QString &groupname) :
    QDialog(parent),
    ui(new Ui::secDialog),
    profiledialog(nullptr),
    listdialog(nullptr),
    calcdialog(nullptr),
    secdialog(nullptr),
    username(username),
    groupname(groupname)
{
    ui->setupUi(this);
}

secDialog::~secDialog()
{
    delete ui;
}
void secDialog::on_pushbutton_profile_clicked()
{
    hide();
    profiledialog = new profileDialog(this, username, groupname);
    profiledialog ->show();
}
void secDialog::on_pushbutton_list_clicked()
{
    hide();
    listdialog = new listDialog(this, username, groupname);
    listdialog ->show();
}
void secDialog::on_pushbutton_calc_clicked()
{
    hide();
    calcdialog = new calcDialog(this,username, groupname);
    calcdialog ->show();
}
void secDialog::on_pushbutton_home_clicked()
{
    hide();
    secdialog = new secDialog(this,username, groupname);
    secdialog ->show();
}
void secDialog::on_pushbutton_group_clicked()
{
    groupdialog = new groupDialog(this, username, groupname);
    groupdialog ->show();
}
