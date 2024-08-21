#include "information.h"
#include "manage.h"
#include "infortwo.h"
#include "barsql.h"
#include "ui_information.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <QStandardItemModel>
#include <QSqlQuery>

information::information(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::information)
,m_ptrbarsql(nullptr)
{
    ui->setupUi(this);
    this->setWindowTitle("用户数据库");
    m_ptrbarsql = barsql::getinstance();
    m_ptrbarsql->init();
    qmodel = new QStandardItemModel();
    QSqlQuery query;
    query.exec("SELECT * FROM bar");
    qmodel->setColumnCount(8);
    qmodel->setHorizontalHeaderLabels(QStringList()<<"id"<<"card"<<"password"<<"状态"<<"剩余金额"<<"上机次数"<<"上机日期"<<"下机日期");

    int row = 0;
    while (query.next()) {  // 遍历查询结果
        for (int i = 0; i < qmodel->columnCount(); i++) {
            QStandardItem* item = new QStandardItem(query.value(i).toString());
            qmodel->setItem(row, i, item);  // 写入model
        }
        row++;
    }
    ui->tableView->setModel(qmodel);
}

information::~information()
{
    delete ui;
}
//返回管理界面
void information::on_backButton_clicked()
{
    MANAge *w = new MANAge;
    w->show();
    this->close();
}

//模拟制作数据
void information::on_imitateButton_clicked()
{
    //制作100条数据
    QRandomGenerator g;
    QRandomGenerator c;
    QRandomGenerator f;
    f.seed(0);
    g.seed(0);
    c.seed(0);
    for(int i = 0;i<100;i++){
        auto card = g.bounded(111,666);
        QString s = QString::number(card);
        auto state = g.bounded(0,2);
        auto frequency = g.bounded(0,100);
        barinf info;
        if(i%3){
            info.reamount = "60";
            info.vip = "vip";
        }
        else if(i%7){
            info.reamount = "45";
            info.vip = "";
        }
        else if(i%2){
            info.reamount = "20";
            info.vip = "vip";
        }
        else {
            info.reamount = "10";
            info.vip = "svip";
        }

        info.id= i;
        info.card = s;
        info.state = state;
        info.password = "123456";
        info.frequency = frequency;
        info.upday = "2024-08-14";
        info.downday = "2024-08-23";
        info.uptime = "15:34:40";
        info.downtime = "19:59:29";
        info.pay = "已缴费";
        m_ptrbarsql->addCard(info);
    }
    QSqlQuery query;
    query.exec("SELECT * FROM bar");
    qmodel->setColumnCount(8);
    qmodel->setHorizontalHeaderLabels(QStringList()<<"id"<<"card"<<"password"<<"状态"<<"剩余金额"<<"上机次数"<<"上机日期"<<"下机日期");
    int row = 0;
    while (query.next()) {  // 遍历查询结果
        for (int i = 0; i < qmodel->columnCount(); i++) {
            QStandardItem* item = new QStandardItem(query.value(i).toString());
            qmodel->setItem(row, i, item);  // 写入model
        }
        row++;
    }
    ui->tableView->setModel(qmodel);
}


//清空表
void information::on_clearButton_clicked()
{
    m_ptrbarsql->clearbartable();
    qmodel->clear();
}


//搜索功能
void information::on_searchButton_clicked()
{
    qmodel->clear();
    int count = 0;
    QString num = ui->usercard->text();
    QSqlQuery query;
    QString number = QString("SELECT COUNT(*) FROM bar WHERE card GLOB '*%1*'").arg(num);
    if (query.exec(number)) {
        if (query.next()) {
        count = query.value(0).toInt();
        }
    }
    QString sql = QString("SELECT * FROM bar WHERE card GLOB '*%1*'").arg(num);
    if(query.exec(sql)){
        qmodel->setColumnCount(8);
        qmodel->setHorizontalHeaderLabels(QStringList()<<"id"<<"card"<<"password"<<"状态"<<"剩余金额"<<"上机次数"<<"上机日期"<<"下机日期");
        for(int i = 0;i<count;){
    while(query.next())
    {
         QString id = query.value(0).toString();
         QString card = query.value(1).toString();
         QString password = query.value(2).toString();
         QString state = query.value(3).toString();
         QString reamount = query.value(4).toString();
         QString frequency = query.value(5).toString();
         QString upday = query.value(6).toString();
         QString downday = query.value(7).toString();


        qmodel->setItem(i,0,new QStandardItem(id));
        qmodel->setItem(i,1,new QStandardItem(card));
        qmodel->setItem(i,2,new QStandardItem(password));
        qmodel->setItem(i,3,new QStandardItem(state));
        qmodel->setItem(i,4,new QStandardItem(reamount));
        qmodel->setItem(i,5,new QStandardItem(frequency));
        qmodel->setItem(i,6,new QStandardItem(upday));
        qmodel->setItem(i,7,new QStandardItem(downday));
        i++;
            }
    }
    }
}

void information::on_clearSchButton_clicked()
{
    ui->usercard->clear();
    qmodel->clear();
    QSqlQuery query;
    query.exec("SELECT * FROM bar");
    qmodel->setColumnCount(8);
    qmodel->setHorizontalHeaderLabels(QStringList()<<"id"<<"card"<<"password"<<"状态"<<"剩余金额"<<"上机次数"<<"上机日期"<<"下机日期");
    int row = 0;
    while (query.next()) {  // 遍历查询结果
        for (int i = 0; i < qmodel->columnCount(); i++) {
            QStandardItem* item = new QStandardItem(query.value(i).toString());
            qmodel->setItem(row, i, item);  // 写入model
        }
        row++;
    }
    ui->tableView->setModel(qmodel);
}


void information::on_pushButton_clicked()
{
    infortwo *w = new infortwo;
    w->show();
    this->close();
}

