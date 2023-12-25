#include "listdialog.h"
#include "ui_listdialog.h"
#include "adddialog.h"
#include "profiledialog.h"
#include "secdialog.h"
#include "piedialog.h"
#include "calcdialog.h"
#include "regdialog.h"

listDialog::listDialog(QWidget *parent, const QString &username)
    : QDialog(parent),
    ui(new Ui::listDialog),
    adddialog(nullptr),
    profiledialog(nullptr),
    secdialog(nullptr),
    piedialog(nullptr),
    calcdialog(nullptr),
    username(username)
{
    ui->setupUi(this);
    qDebug() << "Username passed to listDialog: " << username;
}
listDialog::~listDialog()
{
    delete ui;
}

QString listDialog::getCurrentUser() const
{
    return username;
}


void listDialog::on_pushbutton_food_clicked()
{
    adddialog = new addDialog(this, this, getCurrentUser());
    adddialog->setCategory("food");
    adddialog->show();
}


void listDialog::on_pushbutton_mis_clicked()
{
    adddialog = new addDialog(this, this,getCurrentUser());
    adddialog->setCategory("miscellaneous");
    adddialog->show();
}

void listDialog::on_pushbutton_laundry_clicked()
{
    adddialog = new addDialog(this, this,getCurrentUser());
    adddialog->setCategory("laundry");
    adddialog->show();
}

void listDialog::on_pushbutton_enter_clicked()
{
    adddialog = new addDialog(this, this,getCurrentUser());
    adddialog->setCategory("entertainment");
    adddialog->show();
}

void listDialog::on_pushbutton_profile_clicked()
{
    hide();
    profiledialog = new profileDialog(this, username);
    profiledialog->show();
}

void listDialog::on_pushbutton_home_clicked()
{
    hide();
    secdialog = new secDialog(this, username);
    secdialog->show();
}

void listDialog::on_pushbutton_pie_clicked()
{
    hide();
    piedialog = new pieDialog(this, username);
    piedialog->show();
}

void listDialog::on_pushbutton_calc_clicked()
{
    hide();
    calcdialog = new calcDialog(this, username);
    calcdialog->show();
}
