#include "profiledialog.h"
#include "ui_profiledialog.h"
#include"secdialog.h"
#include"listdialog.h"

profileDialog::profileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profileDialog)
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
    piedialog = new pieDialog(this);
    piedialog ->show();
}
void profileDialog::on_pushbutton_list_clicked()
{
    hide();
    listdialog = new listDialog(this);
    listdialog ->show();
}
void profileDialog::on_pushbutton_calc_clicked()
{
    hide();
    calcdialog = new calcDialog(this);
    calcdialog ->show();
}
void profileDialog::on_pushbutton_home_clicked()
{
    hide();
    secdialog = new secDialog(this);
    secdialog ->show();
}
