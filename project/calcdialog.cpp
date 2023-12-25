// calcdialog.cpp
#include "calcdialog.h"
#include "ui_calcdialog.h"
#include "profiledialog.h"
#include "piedialog.h"
#include "listdialog.h"
#include "secdialog.h"
#include "transdialog.h"

calcDialog::calcDialog(QWidget *parent, const QString &username)
    : QDialog(parent),
    ui(new Ui::calcDialog),
    username(username),
    profiledialog(nullptr),
    piedialog(nullptr),
    listdialog(nullptr),
    secdialog(nullptr),
    transdialog(nullptr)
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
    profiledialog = new profileDialog(this,username);
    profiledialog->show();
}

void calcDialog::on_pushbutton_home_clicked()
{
    hide();
    secdialog = new secDialog(this,username);
    secdialog->show();
}

void calcDialog::on_pushbutton_trans_clicked()
{
    transdialog = new transDialog(this,username);
    transdialog->show();
}

void calcDialog::on_pushbutton_pie_clicked()
{
    hide();
    piedialog = new pieDialog(this,username);
    piedialog->show();
}

void calcDialog::on_pushbutton_list_clicked()
{
    hide();
    listdialog = new listDialog(this, username);
    listdialog->show();
}
