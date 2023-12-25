#include "profiledialog.h"
#include "ui_profiledialog.h"
#include"secdialog.h"
#include"listdialog.h"

profileDialog::profileDialog(QWidget *parent, const QString &username) :
    QDialog(parent),
    ui(new Ui::profileDialog),
   listdialog(nullptr),
    piedialog(nullptr),
    calcdialog(nullptr),
    secdialog(nullptr),
    username(username)

{
    ui->setupUi(this);
}

profileDialog::~profileDialog()
{
    delete ui;
}
void profileDialog::on_pushbutton_pie_clicked()
{
    hide();
    piedialog = new pieDialog(this, username);
    piedialog ->show();
}
void profileDialog::on_pushbutton_list_clicked()
{
    hide();
    listdialog = new listDialog(this,username );
    listdialog ->show();
}
void profileDialog::on_pushbutton_calc_clicked()
{
    hide();
    calcdialog = new calcDialog(this, username);
    calcdialog ->show();
}
void profileDialog::on_pushbutton_home_clicked()
{
    hide();
    secdialog = new secDialog(this, username);
    secdialog ->show();
}
