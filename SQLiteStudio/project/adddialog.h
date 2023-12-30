// adddialog.h
#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include "calcdialog.h"
#include <QDialog>

namespace Ui {
class addDialog;
}

class listDialog;

class addDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDialog(QWidget *parent = nullptr, listDialog *listDialogParent = nullptr, const QString &username = "", const QString &groupname = "");
    ~addDialog();
    void setCategory(const QString &category);


private slots:
    void on_pushbutton_done_clicked();

private:
    Ui::addDialog *ui;
    listDialog *listdialog;
    calcDialog *calcdialog;
    QString username;
    QString groupname;
    QString category;
    bool transactionActive;
    void commitOrRollbackTransaction(bool commit);
};

#endif // ADDDIALOG_H
