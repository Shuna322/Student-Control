#include "database.h"
#include <QMessageBox>
#include <QCoreApplication>
database::database()
{

}

void database::connect()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("kyrsova");
    db.setUserName("root");
    db.setPassword("root");
    if (!db.open())
        QMessageBox(QMessageBox::Critical,"Помилка підключення до бази данних",db.lastError().text()).exec();
    else qDebug() << "До бази даних підключився!";
}

QSqlDatabase database::getdb()
{
    return db;
}

bool database::loginVerification(QString _l, QString _p)
{
    QSqlQuery query =  QSqlQuery(db);
    query.exec("select * from users where login='" + _l + "' and  pass ='" + _p + "';");
    bool i = 0;
    while(query.next()) i=true;
    if (i == 1) qDebug() << "Логін і Пароль правильний !";
        return i;
}
