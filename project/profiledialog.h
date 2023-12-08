#pragma once
#ifndef PROFILEDIALOG_H
#define PROFILEDIALOG_H
#include"calcdialog.h"
#include"piedialog.h"
class secDialog;
class listDialog;
#include <QDialog>

namespace Ui {
class profileDialog;
}

class profileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit profileDialog(QWidget *parent = nullptr);
    ~profileDialog();
private slots:
    void on_pushbutton_list_clicked();
    void on_pushbutton_home_clicked();
    void on_pushbutton_pie_clicked();
    void on_pushbutton_calc_clicked();

private:
    Ui::profileDialog *ui;
    listDialog *listdialog;
    pieDialog *piedialog;
    calcDialog *calcdialog;
    secDialog *secdialog;
};

#endif // PROFILEDIALOG_H
