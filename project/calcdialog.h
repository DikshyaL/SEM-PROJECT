// calcdialog.h
#ifndef CALCDIALOG_H
#define CALCDIALOG_H
#include "qsqldatabase.h"
#include <QDialog>


class profileDialog;

class listDialog;
class secDialog;
class transDialog;
namespace Ui {
class calcDialog;
}

class calcDialog : public QDialog {
    Q_OBJECT

public:
    explicit calcDialog(QWidget *parent = nullptr, const QString &username = "", const QString &groupname = "");
    ~calcDialog();
    QSqlDatabase mydb;
    void displayUserInfo();
    int getNumberOfMembers(const QString &username, const QString &groupname);

private slots:
    void on_pushbutton_profile_clicked();
    void on_pushbutton_home_clicked();
    void on_pushbutton_trans_clicked();
    void on_pushbutton_list_clicked();
    void on_pushbutton_g_clicked();
    void on_spinBox_member_valueChanged(int value);


private:
    Ui::calcDialog *ui;
    QString username;
    QString groupname;
    profileDialog* profiledialog;

    listDialog* listdialog;
    secDialog* secdialog;
    calcDialog* calcdialog;
    transDialog* transdialog;

};

#endif
