#pragma once
#ifndef REGDIALOG_H
#define REGDIALOG_H
#include <QDialog>
#include<QObject>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
class MainWindow;
class listDialog;
namespace Ui {
class regDialog;
}

class regDialog : public QDialog
{
    Q_OBJECT

public:
    explicit regDialog(QWidget *parent = nullptr);
    ~regDialog();

private slots:
   void on_pushbutton_reg_clicked();
private:
    Ui::regDialog *ui;
    MainWindow *mainwindow;
    listDialog *listdialog;
    QSqlDatabase mydb;
    QString username;

};


#endif// REGDIALOG_H
