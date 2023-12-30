#pragma once
#ifndef PROFILEDIALOG_H
#define PROFILEDIALOG_H
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
#include "ui_profiledialog.h"
#include "listdialog.h"
#include "calcdialog.h"
#include "secdialog.h"
class secDialog;
class calcDialog;
class listDialog;
class pieDialog;
class regDialog;
#include <QDialog>


namespace Ui {
class profileDialog;
}

class profileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit profileDialog(QWidget *parent = nullptr,const QString &username = "", const QString &groupname = "");
    ~profileDialog();
private slots:
    void on_pushbutton_list_clicked();
    void on_pushbutton_home_clicked();

    void on_pushbutton_calc_clicked();
    void on_pushbutton_expenses_clicked();

private:
    Ui::profileDialog *ui;
    listDialog *listdialog;

    calcDialog *calcdialog;
    secDialog *secdialog;
    QSqlDatabase mydb;
    QString username;
    QString groupname;
};

#endif // PROFILEDIALOG_H
