#pragma once
#ifndef PIEDIALOG_H
#define PIEDIALOG_H

#include <QDialog>

namespace Ui {
class pieDialog;
}

class pieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit pieDialog(QWidget *parent = nullptr);
    ~pieDialog();

private:
    Ui::pieDialog *ui;
};

#endif // PIEDIALOG_H
