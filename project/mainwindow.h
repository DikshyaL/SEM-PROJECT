#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include"secdialog.h"
#include"profiledialog.h"
#include"calcdialog.h"
#include"listdialog.h"
#include"piedialog.h"
#include"secdialog.h"
#include"regdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushbutton_login_clicked();
    void on_pushbutton_reg_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    secDialog *secdialog;
    regDialog *regdialog;
    MainWindow *mainwindow;
;

};
#endif // MAINWINDOW_H
