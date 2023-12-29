// transdialog.cpp

#include "transdialog.h"
#include "ui_transdialog.h"
#include "calcdialog.h"

transDialog::transDialog(QWidget *parent, const QString &username, const QString &groupname) :
    QDialog(parent),
    ui(new Ui::transDialog),
    calcdialog(nullptr),
    groupname(groupname),
    username(username)
{
    ui->setupUi(this);

    // Initialize and open the database connection
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/diksh/ArthaBhaag/database.db");

    if (!mydb.open()) {
        qDebug() << "Failed to open the database in transDialog:" << mydb.lastError().text();
    }
}

transDialog::~transDialog()
{
    delete ui;
}

void transDialog::on_pushbutton_done_clicked()
{
    if (username.isEmpty()) {
        qDebug() << "Username is empty!";
        return;
    }

    // Get the user input for group member and value
    int groupMember = ui->lineEdit_who->text().toInt();
    double transactionValue = ui->lineEdit_how->text().toDouble();

    // Get the group name
    QString groupName = ui->lineEdit_groupname->text();

    if (groupName.isEmpty()) {
        qDebug() << "Group name is empty!";
        return;
    }

    // Update the group table with the transaction value
    QSqlQuery query;
    qDebug() << username;
    // Assuming the table name is in the format: username_groups_groupname
    QString tableName = QString("%1_groups_%2").arg(username).arg(groupName);

    // Check if the table exists
    if (!mydb.tables().contains(tableName)) {
        qDebug() << "Table doesn't exist:" << tableName;
        return;
    }

    // Check if there is an existing 'id' column in the table
    QString checkIdColumnQuery = QString("PRAGMA table_info(%1)").arg(tableName);
    query.prepare(checkIdColumnQuery);

    if (!query.exec()) {
        qDebug() << "Error checking if 'id' column exists:" << query.lastError().text();
        return;
    }

    int numMembers = mydb.record(tableName).count() - 3;
    if (numMembers < 3) {
        qDebug() << "Error: The table should have at least 2 members (id and total).";
        return;
    }

    bool idColumnExists = false;

    while (query.next()) {
        QString columnName = query.value("name").toString();
        if (columnName == "id") {
            idColumnExists = true;
            break;
        }
    }

    if (!idColumnExists) {
        // Add 'id' column to the table
        QString createIdColumnQuery = QString("ALTER TABLE %1 ADD COLUMN id INTEGER PRIMARY KEY AUTOINCREMENT").arg(tableName);
        if (!query.exec(createIdColumnQuery)) {
            qDebug() << "Error adding 'id' column:" << query.lastError().text();
            return;
        }
    }

    // Update the specific member column
    QString updateQuery = QString("UPDATE %1 SET member%2 = member%2 + :value WHERE id = 1").arg(tableName).arg(groupMember);
    query.prepare(updateQuery);
    query.bindValue(":value", transactionValue);

    if (!query.exec()) {
        qDebug() << "Error updating transaction:" << query.lastError().text();
        return;
    } else {
        qDebug() << "Transaction added successfully!";
    }

    // Update the total column using a subquery
    QString updateTotalQuery = QString("UPDATE %1 SET total = ").arg(tableName);
    for (int i = 1; i <= numMembers; ++i) {
        updateTotalQuery += QString("member%1 + ").arg(i);
    }
    updateTotalQuery.chop(2); // Remove the trailing '+'
    updateTotalQuery += QString(" WHERE id = 1");
    if (!query.exec(updateTotalQuery)) {
        qDebug() << "Error updating total:" << query.lastError().text();
        return;
    }

    // Update the mean column using a subquery
    QString updateMeanQuery = QString("UPDATE %1 SET mean = total / %2 WHERE id = 1").arg(tableName).arg(numMembers);
    if (!query.exec(updateMeanQuery)) {
        qDebug() << "Error updating mean:" << query.lastError().text();
        return;
    }

    // Fetch the member values from row 1
    QVector<double> memberValues;
    for (int i = 1; i <= numMembers; ++i) {
        QString selectMemberValueQuery = QString("SELECT member%1 FROM %2 WHERE id = 1").arg(i).arg(tableName);
        if (!query.exec(selectMemberValueQuery) || !query.next()) {
            qDebug() << "Error fetching member%1 value:" << query.lastError().text();
            return;
        }
        double memberValue = query.value(0).toDouble();
        memberValues.append(memberValue);
    }

    // Fetch the mean value from row 1
    double meanValue = 0.0; // Initialize with a default value, or fetch it from the database
    QString selectMeanValueQuery = QString("SELECT mean FROM %1 WHERE id = 1").arg(tableName);
    if (!query.exec(selectMeanValueQuery) || !query.next()) {
        qDebug() << "Error fetching mean value:" << query.lastError().text();
        return;
    }
    meanValue = query.value(0).toDouble();

    // Calculate differences and update the second row
    QString updateDiffRowQuery = QString("UPDATE %1 SET mean = :mean, ").arg(tableName);
    for (int i = 1; i <= numMembers; ++i) {
        updateDiffRowQuery += QString("member%1 = :member%1, ").arg(i);
    }
    updateDiffRowQuery.chop(2); // Remove the trailing ','
    updateDiffRowQuery += " WHERE id = 2"; // Assuming the second row is always available

    query.prepare(updateDiffRowQuery);
    query.bindValue(":mean", meanValue);
    for (int i = 1; i <= numMembers; ++i) {
        query.bindValue(":member" + QString::number(i), memberValues.at(i - 1) - meanValue);
    }

    if (!query.exec()) {
        qDebug() << "Error updating the second row with differences:" << query.lastError().text();
        return;
    } else {
        qDebug() << "Second row updated with differences!";
    }
    calcdialog= new calcDialog(this, username, groupName);
    hide();
}
