#include "secdialog.h"
#include "ui_secdialog.h"

secDialog::secDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secDialog)
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
    profiledialog = new profileDialog(this);
    profiledialog ->show();
}
void secDialog::on_pushbutton_pie_clicked()
{
    hide();
    piedialog = new pieDialog(this);
    piedialog ->show();
}
void secDialog::on_pushbutton_list_clicked()
{
    hide();
    listdialog = new listDialog(this);
    listdialog ->show();
}
void secDialog::on_pushbutton_calc_clicked()
{
    hide();
    calcdialog = new calcDialog(this);
    calcdialog ->show();
}
void secDialog::on_pushbutton_home_clicked()
{
    hide();
    secdialog = new secDialog(this);
    secdialog ->show();
}
