#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#endif // DATABASE_MANAGER_H

class DbManager {
public:
    DbManager(const QString& path);
private:
    QSqlDatabase m_db;
};

DbManager::DbManager(const QString& path) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()) {
        qDebug() << "Error::Connection to database failed!";
    } else {
        qDebug() << "Database connected successfully!";
    }
}

//Login
bool DbManger::addPerson (const QString& username, const QString& password) {
    bool success = false;
    QSqlQuery query;
    query.prepare("(:username)"
                  "(:password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (query.exec()) {
        sucess = true;
    } else {
        qDebug() << "Login Error:" << query.lastError();
    }

    return sucess;
}
