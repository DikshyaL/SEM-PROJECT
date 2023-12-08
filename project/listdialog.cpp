#include "listdialog.h"
#include "ui_listdialog.h"
#include"secdialog.h"

listDialog::listDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listDialog)
{
    ui->setupUi(this);
}

listDialog::~listDialog()
{
    delete ui;
}
void listDialog::on_pushbutton_profile_clicked()
{
    hide();
    profiledialog = new profileDialog(this);
    profiledialog ->show();
}
void listDialog::on_pushbutton_home_clicked()
{
    hide();
    secdialog = new secDialog(this);
    secdialog ->show();
}
void listDialog::on_pushbutton_pie_clicked()
{
    hide();
    piedialog = new pieDialog(this);
    piedialog ->show();
}
void listDialog::on_pushbutton_calc_clicked()
{
    hide();
    calcdialog = new calcDialog(this);
    calcdialog ->show();
}
