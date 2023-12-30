#ifndef TRANSDIALOG_H
#define TRANSDIALOG_H
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

#include <QDialog>
class calcDialog;
namespace Ui {
class transDialog;
}

class transDialog : public QDialog
{
    Q_OBJECT

public:
    explicit transDialog(QWidget *parent = nullptr, const QString &username = "", const QString &groupname = "");
    ~transDialog();
private slots:
    void on_pushbutton_done_clicked();

    double calculateMeanValue(const QSqlRecord& record, int numMembers)
    {
        double totalValue = calculateTotalValue(record);


        if (numMembers > 0) {
            return totalValue / static_cast<double>(numMembers);
        } else {

            return 0.0;
        }
    }
    double calculateTotalValue(const QSqlRecord& record)
    {
        double totalValue = 0.0;

        // Assuming that member values start from column 2 (index 1)
        for (int i = 1; i < record.count(); ++i) {
            if (record.fieldName(i) != "id" && record.fieldName(i) != "mean") {
                totalValue += record.value(i).toDouble();
            }
        }

        return totalValue;
    }


private:
    Ui::transDialog *ui;
    calcDialog *calcdialog;
    QSqlDatabase mydb;
    QString groupname;
    QString username;
};

#endif // TRANSDIALOG_H
