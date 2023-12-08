#pragma once
#ifndef SECDIALOG_H
#define SECDIALOG_H
#include <QDialog>
#include"profiledialog.h"
#include"listdialog.h"
#include"piedialog.h"
#include"calcdialog.h"

namespace Ui {
class secDialog;
}

class secDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secDialog(QWidget *parent = nullptr);
    ~secDialog();
private slots:
    void on_pushbutton_profile_clicked();
    void on_pushbutton_pie_clicked();
    void on_pushbutton_calc_clicked();
    void on_pushbutton_list_clicked();
    void on_pushbutton_home_clicked();

private:
    Ui::secDialog *ui;
    profileDialog *profiledialog;
    listDialog *listdialog;
    pieDialog *piedialog;
    calcDialog *calcdialog;
    secDialog *secdialog;

};

#endif // SECDIALOG_H
