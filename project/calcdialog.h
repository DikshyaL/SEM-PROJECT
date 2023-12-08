#pragma once
#ifndef CALCDIALOG_H
#define CALCDIALOG_H
#include"piedialog.h"
#include <QDialog>
class listDialog;
class profileDialog;
class secDialog;
namespace Ui {
class calcDialog;
}

class calcDialog : public QDialog
{
    Q_OBJECT

public:
    explicit calcDialog(QWidget *parent = nullptr);
    ~calcDialog();
private slots:
    void on_pushbutton_profile_clicked();
    void on_pushbutton_pie_clicked();
    void on_pushbutton_list_clicked();
    void on_pushbutton_home_clicked();
private:
    Ui::calcDialog *ui;
    profileDialog *profiledialog;
    pieDialog *piedialog;
    listDialog *listdialog;
    secDialog *secdialog;
};

#endif // CALCDIALOG_H
