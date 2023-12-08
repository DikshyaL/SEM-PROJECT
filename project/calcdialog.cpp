#include "calcdialog.h"
#include "profiledialog.h"
#include "ui_calcdialog.h"
#include"listdialog.h"
#include"secdialog.h"

calcDialog::calcDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calcDialog)
{
    ui->setupUi(this);
}

calcDialog::~calcDialog()
{
    delete ui;
}
void calcDialog::on_pushbutton_profile_clicked()
{
    hide();
    profiledialog = new profileDialog(this);
    profiledialog ->show();
}
void calcDialog::on_pushbutton_home_clicked()
{
    hide();
    secdialog = new secDialog(this);
    secdialog ->show();
}
void calcDialog::on_pushbutton_pie_clicked()
{
    hide();
    piedialog = new pieDialog(this);
    piedialog ->show();
}
void calcDialog::on_pushbutton_list_clicked()
{
    hide();
    listdialog = new listDialog(this);
    listdialog ->show();
}
