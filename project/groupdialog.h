#ifndef GROUPDIALOG_H
#define GROUPDIALOG_H
#include "qsqldatabase.h"
#include <QDialog>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include"calcdialog.h"
class secDialog;
namespace Ui {
class groupDialog;
}

class groupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit groupDialog(QWidget *parent = nullptr, const QString &username = "", const QString &groupname="");
    ~groupDialog();
    static bool groupExistsForUser(const QString &username);
    static QSqlDatabase mydb;
private slots:
    void on_pushbutton_done_clicked();

private:
    Ui::groupDialog *ui;
    secDialog *secdialog;
    QString groupname;
    QString username;
    calcDialog *calcdialog;


};

#endif // GROUPDIALOG_H
