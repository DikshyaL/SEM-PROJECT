#include "regdialog.h"
#include "ui_regdialog.h"
#include"mainwindow.h"
regDialog::regDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regDialog)
{
    ui->setupUi(this);
}

regDialog::~regDialog()
{
    delete ui;
}
void regDialog::on_pushbutton_reg_clicked()
{
    hide();
    mainwindow = new MainWindow(this);
    mainwindow ->show();
}
