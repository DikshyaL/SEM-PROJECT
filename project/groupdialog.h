#ifndef GROUPDIALOG_H
#define GROUPDIALOG_H
#include "qsqldatabase.h"
#include <QDialog>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
class secDialog;
namespace Ui {
class groupDialog;
}

class groupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit groupDialog(QWidget *parent = nullptr, const QString &username = "");
    ~groupDialog();
private slots:
    void on_pushbutton_done_clicked();

private:
    Ui::groupDialog *ui;
    secDialog *secdialog;
    QString username;
    QSqlDatabase mydb;
};

#endif // GROUPDIALOG_H
