#include "infortwo.h"
#include "ui_infortwo.h"
#include "information.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <QStandardItemModel>
#include <QSqlQuery>
//用户数据查询第二页

infortwo::infortwo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::infortwo)
,m_ptrbarsql(nullptr)
{
    ui->setupUi(this);
    this->setWindowTitle("用户数据库");
    m_ptrbarsql = barsql::getinstance();
    m_ptrbarsql->init();
    qmodel = new QStandardItemModel();
    QSqlQuery query;
    query.exec("SELECT * FROM bar");
    qmodel->setColumnCount(6);
    qmodel->setHorizontalHeaderLabels(QStringList()<<"id"<<"card"<<"上机时间"<<"下机时间"<<"会员状态"<<"缴费情况");

    int row = 0;
    while (query.next()) {  // 遍历查询结果
        for (int i = 0; i < 12; i++) {
            if(i == 0||i == 1||i>=8){
            QStandardItem* item = new QStandardItem(query.value(i).toString());
                if(i>=8){
                    qmodel->setItem(row, i-6, item);
                }
                else{
                    qmodel->setItem(row, i, item);
                }
            }  // 写入model
        }
        row++;
    }
    ui->tableView->setModel(qmodel);
}

infortwo::~infortwo()
{
    delete ui;
}

void infortwo::on_backButton_clicked()
{
    information *w = new information;
    w->show();
    this->close();
}


void infortwo::on_searchButton_clicked()
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
        qmodel->setColumnCount(6);
        qmodel->setHorizontalHeaderLabels(QStringList()<<"id"<<"card"<<"上机时间"<<"下机时间"<<"会员状态"<<"缴费情况");
        for(int i = 0;i<count;){
            while(query.next())
            {
                QString id = query.value(0).toString();
                QString card = query.value(1).toString();
                QString uptime = query.value(8).toString();
                QString downtime = query.value(9).toString();
                QString vip = query.value(10).toString();
                QString pay = query.value(11).toString();


                qmodel->setItem(i,0,new QStandardItem(id));
                qmodel->setItem(i,1,new QStandardItem(card));
                qmodel->setItem(i,2,new QStandardItem(uptime));
                qmodel->setItem(i,3,new QStandardItem(downtime));
                qmodel->setItem(i,4,new QStandardItem(vip));
                qmodel->setItem(i,5,new QStandardItem(pay));
                i++;
            }
        }
    }
}


void infortwo::on_clearSchButton_clicked()
{
    ui->usercard->clear();
    qmodel->clear();
    QSqlQuery query;
    query.exec("SELECT * FROM bar");
    qmodel->setColumnCount(6);
    qmodel->setHorizontalHeaderLabels(QStringList()<<"id"<<"card"<<"上机时间"<<"下机时间"<<"会员状态"<<"缴费情况");
    int row = 0;
    while (query.next()) {  // 遍历查询结果
            for (int i = 0; i < 12; i++) {
                if(i == 0||i == 1||i>=8){
                    QStandardItem* item = new QStandardItem(query.value(i).toString());
                    if(i>=8){
                        qmodel->setItem(row, i-6, item);
                    }
                    else{
                        qmodel->setItem(row, i, item);
                    }
                }  // 写入model
            }
            row++;
        }
    ui->tableView->setModel(qmodel);
}

