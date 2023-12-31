#pragma once
#ifndef SECDIALOG_H
#define SECDIALOG_H
#include <QDialog>
#include"profiledialog.h"
#include"listdialog.h"
#include"calcdialog.h"
#include"groupdialog.h"
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class secDialog;
}

class secDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secDialog(QWidget *parent = nullptr,const QString &username  = "", const QString &groupname = "");
    ~secDialog();
private slots:
    void on_pushbutton_profile_clicked();
    void on_pushbutton_calc_clicked();
    void on_pushbutton_list_clicked();
    void on_pushbutton_home_clicked();
    void on_pushbutton_group_clicked();


private:
    Ui::secDialog *ui;
    profileDialog *profiledialog;
    listDialog *listdialog;
    calcDialog *calcdialog;
    secDialog *secdialog;
    groupDialog *groupdialog;
    QSqlDatabase mydb;
    QString username;
    QString groupname;
};

#endif // SECDIALOG_H
