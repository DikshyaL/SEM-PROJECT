// calcdialog.h
#ifndef CALCDIALOG_H
#define CALCDIALOG_H

#include <QDialog>

class profileDialog;
class pieDialog;
class listDialog;
class secDialog;
class transDialog;

namespace Ui {
class calcDialog;
}

class calcDialog : public QDialog {
    Q_OBJECT

public:
    explicit calcDialog(QWidget *parent = nullptr, const QString &username = "");
    ~calcDialog();

private slots:
    void on_pushbutton_profile_clicked();
    void on_pushbutton_home_clicked();
    void on_pushbutton_trans_clicked();
    void on_pushbutton_pie_clicked();
    void on_pushbutton_list_clicked();

private:
    Ui::calcDialog *ui;
    QString username;
    profileDialog* profiledialog;
    pieDialog* piedialog;
    listDialog* listdialog;
    secDialog* secdialog;
    transDialog* transdialog;
};

#endif // CALCDIALOG_H
