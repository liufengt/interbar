#ifndef BARSQL_H
#define BARSQL_H

#include <QObject>
#include <QSqlDatabase>
struct barinf {
    int id;
    QString card;
    QString password;
    int state;
    QString reamount;
    int frequency;
    QString upday;
    QString downday;
    QString uptime;
    QString downtime;
    QString vip;
    QString pay;
};

class barsql : public QObject
{
    Q_OBJECT
public:
    static barsql *ptrbarinf;
    static barsql *getinstance(){
         if(nullptr == ptrbarinf){
            ptrbarinf = new barsql;
         }
         return ptrbarinf;
    }

    explicit barsql(QObject *parent = nullptr);

    void init();
    //查询网卡数量
    quint32 getCardnum();
    //获取第几页数据,从第零页开始
    QList<barinf> getPageCard(quint32 page,quint32 cardCnt);
    //增加网卡
    bool addCard(barinf);
    //清空网卡表
    bool clearbartable();

signals:
private:
    QSqlDatabase m_db;
};

#endif // BARSQL_H
