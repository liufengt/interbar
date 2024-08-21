#include "barsql.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QCoreApplication>
barsql * barsql::ptrbarinf = nullptr;
barsql::barsql(QObject *parent)
    : QObject{parent}
{
    init();
}

void barsql::init()
{
    if(QSqlDatabase::drivers().isEmpty()){
        qDebug()<<"No database divers found";
    }

    m_db = QSqlDatabase::addDatabase("QSQLITE");
#if 0
    auto str = QCoreApplication::applicationDirPath()+"data.db";
    qDebug()<<str;
#endif

    m_db.setDatabaseName("D:/king/data.db");
    if(!m_db.open()){
        qDebug()<<"db not open";
    }
}

quint32 barsql::getCardnum()
{
    QSqlQuery sql(m_db);
    sql.exec("select count(id) from bar;");
    quint32 uicnt = 0;
    while (sql.next()) {
        uicnt = sql.value(0).toUInt();
    }
    return uicnt;
}

QList<barinf> barsql::getPageCard(quint32 page, quint32 cardCnt)
{
    QList<barinf> l;
    QSqlQuery sql(m_db);
    QString strsql = QString("select * from bar order by card limit %1 offset %2").arg(cardCnt).arg(page*cardCnt);
    sql.exec(strsql);
    barinf info;
    while (sql.next()) {
        info.id = sql.value(0).toUInt();
        info.card = sql.value(1).toString();
        info.password = sql.value(2).toString();
        info.state = sql.value(3).toUInt();
        info.reamount = sql.value(4).toString();
        info.frequency = sql.value(5).toUInt();
        info.upday = sql.value(6).toString();
        info.downday = sql.value(7).toString();
        info.uptime = sql.value(8).toString();
        info.vip = sql.value(9).toString();
        info.downtime = sql.value(10).toString();
        l.push_back(info);
    }
    return l;
}

bool barsql::addCard(barinf info)
{
    QSqlQuery sql(m_db);
    QString strsql = QString("insert into bar values (NULL,'%1','%2',%3,'%4',%5,'%6','%7','%8','%9','%10','%11')")
                    .arg(info.card)
                    .arg(info.password)
                    .arg(info.state)
                    .arg(info.reamount)
                    .arg(info.frequency)
                    .arg(info.upday)
                    .arg(info.downday)
                    .arg(info.uptime)
                    .arg(info.downtime)
                    .arg(info.vip)
                    .arg(info.pay);
    return sql.exec(strsql);
}


bool barsql::clearbartable()
{
    QSqlQuery sql(m_db);
    return sql.exec("delete from bar");
}
