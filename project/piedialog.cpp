#include "piedialog.h"
#include "ui_piedialog.h"

pieDialog::pieDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pieDialog)
{
    ui->setupUi(this);
}

pieDialog::~pieDialog()
{
    delete ui;
}
