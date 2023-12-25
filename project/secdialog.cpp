#include "secdialog.h"
#include "ui_secdialog.h"

secDialog::secDialog(QWidget *parent,const QString &username) :
    QDialog(parent),
    ui(new Ui::secDialog),
    profiledialog(nullptr),
    listdialog(nullptr),
    piedialog(nullptr),
    calcdialog(nullptr),
    secdialog(nullptr),
    username(username)
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
    profiledialog = new profileDialog(this, username);
    profiledialog ->show();
}
void secDialog::on_pushbutton_pie_clicked()
{
    hide();
    piedialog = new pieDialog(this, username);
    piedialog ->show();
}
void secDialog::on_pushbutton_list_clicked()
{
    hide();
    listdialog = new listDialog(this, username);
    listdialog ->show();
}
void secDialog::on_pushbutton_calc_clicked()
{
    hide();
    calcdialog = new calcDialog(this,username);
    calcdialog ->show();
}
void secDialog::on_pushbutton_home_clicked()
{
    hide();
    secdialog = new secDialog(this,username);
    secdialog ->show();
}
void secDialog::on_pushbutton_group_clicked()
{
    groupdialog = new groupDialog(this, username);
    groupdialog ->show();
}
