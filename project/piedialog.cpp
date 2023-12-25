#include "piedialog.h"
#include "ui_piedialog.h"

pieDialog::pieDialog(QWidget *parent, const QString &username) :
    QDialog(parent),
    ui(new Ui::pieDialog),
    username(username)
{
    ui->setupUi(this);
}

pieDialog::~pieDialog()
{
    delete ui;
}
