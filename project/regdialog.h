#pragma once
#ifndef REGDIALOG_H
#define REGDIALOG_H
#include <QDialog>
#include<QObject>
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
};


#endif// REGDIALOG_H
