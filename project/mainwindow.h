#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
class secDialog;
class listDialog;
class regDialog;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,const QString &username = "");
    ~MainWindow();

private slots:
    void on_pushbutton_login_clicked();
    void on_pushbutton_reg_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    secDialog *secdialog;
    regDialog *regdialog;
    listDialog *listdialog;
    MainWindow *mainwindow;
    QString username;
;

};
#endif
