// groupdialog.cpp
#include"secdialog.h"
#include"calcdialog.h"
#include "groupdialog.h"
#include "ui_groupdialog.h"
#include "QSqlError"
#include <QInputDialog>
#include <QSqlQuery>
#include <QMessageBox>

QSqlDatabase groupDialog::mydb = QSqlDatabase::addDatabase("QSQLITE");

groupDialog::groupDialog(QWidget *parent, const QString &username, const QString &groupname) :
    QDialog(parent),
    ui(new Ui::groupDialog),
    groupname(groupname),
    username(username)
{
    ui->setupUi(this);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/diksh/ArthaBhaag/database.db");

    if (!mydb.open()) {
        qDebug() << "Failed to open the database in groupDialog:" << mydb.lastError().text();
    }
}



groupDialog::~groupDialog()
{
    delete ui;
}

void groupDialog::on_pushbutton_done_clicked()
{

    QString groupname = ui->lineEdit_groupname->text();
    int numMembers = ui->spinBox_numberofmembers->value();

    if (numMembers <= 0) {
        qDebug() << "Invalid number of members!";
        return;
    }

    if (!mydb.isOpen()) {
        qDebug() << "Database not open in groupDialog!";
        return;
    }

    QSqlQuery query;


    QString createTableUserGroupsQuery = "CREATE TABLE IF NOT EXISTS user_groups ("
                                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                         "group_name TEXT)";
    if (!query.exec(createTableUserGroupsQuery)) {
        qDebug() << "Create user_groups table error:" << query.lastError().text();
        return;
    }

    // Create dynamic table for the new group
    QString tableName = QString("%1_groups_%2").arg(username).arg(groupname);
    QString createTableQuery = QString("CREATE TABLE IF NOT EXISTS %1 ("
                                       "id INTEGER PRIMARY KEY AUTOINCREMENT, ").arg(tableName);
    for (int i = 1; i <= numMembers; ++i) {
        createTableQuery += QString("member%1 NUMERIC DEFAULT 0.0, ").arg(i);
    }

    createTableQuery += "total NUMERIC DEFAULT 0.0, ";
    createTableQuery += "mean NUMERIC DEFAULT 0.0)";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Error creating table:" << query.lastError().text();
        return;
    }

    // Insert a new row into the dynamic group table
    QString addRowQuery = QString("INSERT INTO %1 DEFAULT VALUES").arg(tableName);

    if (!query.exec(addRowQuery)) {
        qDebug() << "Error adding a new row:" << query.lastError().text();
        return;
    }

    // Check if the row with id = 1 exists
    QString checkRowQuery = QString("SELECT COUNT(*) FROM %1 WHERE id = 1").arg(tableName);

    query.prepare(checkRowQuery);

    if (!query.exec()) {
        qDebug() << "Error checking if row with id = 1 exists:" << query.lastError().text();
        return;
    }

    query.next();
    int rowCount = query.value(0).toInt();

    if (rowCount == 0) {
        qDebug() << "Row with id = 1 does not exist!";
        return;
    }

    // Insert another row with zero values
    QString addZeroRowQuery = QString("INSERT INTO %1 DEFAULT VALUES").arg(tableName);

    if (!query.exec(addZeroRowQuery)) {
        qDebug() << "Error adding a row with zero values:" << query.lastError().text();
        return;
    }

    qDebug() << "Group information added to the database:";
    qDebug() << "Group Name: " << groupname;

    hide();
    secdialog =new secDialog(this, username, groupname);
    calcdialog = new calcDialog(this, username, groupname);
}
