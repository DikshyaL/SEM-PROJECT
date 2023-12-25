#pragma once
#ifndef PIEDIALOG_H
#define PIEDIALOG_H
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

namespace Ui {
class pieDialog;
}

class pieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit pieDialog(QWidget *parent = nullptr,const QString &username = "");
    ~pieDialog();

private:
    Ui::pieDialog *ui;
    QSqlDatabase mydb;
    QString username;
};

#endif // PIEDIALOG_H
