
#ifndef LISTDIALOG_H
#define LISTDIALOG_H

#include "adddialog.h"
#include "profiledialog.h"
#include "piedialog.h"
#include "calcdialog.h"
#include "regdialog.h"
#include <QMessageBox>
#include <QtSql>
#include <QDialog>
class MainWindow;
class secDialog;

namespace Ui {
class listDialog;
}

class listDialog : public QDialog
{
    Q_OBJECT

public:
    explicit listDialog(QWidget *parent = nullptr, const QString &username = "");
    ~listDialog();
    QString getCurrentUser() const;

private slots:

    void on_pushbutton_food_clicked();
    void on_pushbutton_mis_clicked();
    void on_pushbutton_laundry_clicked();
    void on_pushbutton_enter_clicked();
    void on_pushbutton_profile_clicked();
    void on_pushbutton_home_clicked();
    void on_pushbutton_pie_clicked();
    void on_pushbutton_calc_clicked();


private:
    Ui::listDialog *ui;
    addDialog *adddialog;
    profileDialog *profiledialog;
    secDialog *secdialog;
    pieDialog *piedialog;
    calcDialog *calcdialog;
    QString username;
};

#endif // LISTDIALOG_H
