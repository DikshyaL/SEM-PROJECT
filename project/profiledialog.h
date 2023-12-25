#pragma once
#ifndef PROFILEDIALOG_H
#define PROFILEDIALOG_H
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
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
    explicit profileDialog(QWidget *parent = nullptr,const QString &username = "");
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
    QSqlDatabase mydb;
    QString username;
};

#endif // PROFILEDIALOG_H
