#pragma once
#ifndef REGDIALOG_H
#define REGDIALOG_H
#include <QDialog>
#include<QObject>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
class MainWindow;
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
    QSqlDatabase mydb;
};


#endif// REGDIALOG_H
