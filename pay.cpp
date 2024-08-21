#include "pay.h"
#include "manage.h"
#include "ui_pay.h"
#include <QDateTime>
#include <QSqlQuery>
#include <QMessageBox>

pay::pay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::pay)
{
    ui->setupUi(this);
        this->setWindowTitle("缴费");
}

pay::~pay()
{
    delete ui;
}

void pay::on_pauButton_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM bar");
    QString usercard = ui->cardline->text();
    QString sql = QString("SELECT * FROM bar WHERE card = '%1'").arg(usercard);
    if(query.exec(sql)){
        while(query.next()){
            QString pay = query.value(11).toString();
            QString state = query.value(3).toString();
            QString utime = query.value(8).toString();
            QString dtime = query.value(9).toString();
            QTime utm=QTime::fromString(utime,"hh:mm:ss");
            QTime dtm=QTime::fromString(dtime,"hh:mm:ss");
            qint64 theTime = utm.secsTo(dtm);
            if(theTime<0){
                theTime = -theTime;
            }
            if(state == "0"){
            int h = theTime/3600+1;//此次上机时间
            int moy = h*8;//消费金额
            QString nowvip = query.value(10).toString();
            QString nowreamount = query.value(4).toString();
            int reamount = nowreamount.toInt();
            if(pay == "已缴费"){
                QMessageBox msgBox;
                msgBox.setText("该账户费用已缴清");
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
            }
            else{
            if(nowvip == "vip"){
                int vipmoy = moy*0.9;//vip消费金额
                reamount=reamount-vipmoy;
                QString vipmoney = QString::number(vipmoy);
                QString reamou = QString::number(reamount);
                QString nowpay = "已缴费";
                QString sql2 = QString("UPDATE bar SET reamount='%1',pay='%2' WHERE card='%3';").arg(reamount).arg(nowpay).arg(usercard);//更新数据
                if(query.exec(sql2)){
                QMessageBox msgBox;
                ui->moneyline->setText(vipmoney);
                ui->reamountline->setText(reamou);
                if(reamount<0){
                    QMessageBox msgBox;
                    msgBox.setText("余额不足，已欠费，请及时充值");
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();
                }
            }
            }
            else if(nowvip == "svip"){

                int svipmoy = moy*0.7;//svip消费金额
                reamount-=svipmoy;
                QString svipmoney = QString::number(svipmoy);
                QString reamou = QString::number(reamount);
                QString nowpay = "已缴费";
                QString sql2 = QString("UPDATE bar SET reamount='%1',pay='%2' WHERE card='%3';").arg(reamount).arg(nowpay).arg(usercard);//更新数据
                if(query.exec(sql2)){
                ui->moneyline->setText(svipmoney);
                ui->reamountline->setText(reamou);
                if(reamount<0){
                    QMessageBox msgBox;
                    msgBox.setText("余额不足，已欠费，请及时充值");
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();
                }
            }
            }
                else{
                int ptmoy = moy*1;//svip消费金额
                reamount-=ptmoy;
                QString ptmoney = QString::number(ptmoy);
                QString reamou = QString::number(reamount);
                QString nowpay = "已缴费";
                QString sql2 = QString("UPDATE bar SET reamount='%1',pay='%2' WHERE card='%3';").arg(reamount).arg(nowpay).arg(usercard);//更新数据
                if(query.exec(sql2)){
                    ui->moneyline->setText(ptmoney);
                    ui->reamountline->setText(reamou);
                    if(reamount<0){
                        QMessageBox msgBox;
                        msgBox.setText("余额不足，已欠费，请及时充值");
                        msgBox.setStandardButtons(QMessageBox::Ok);
                        msgBox.exec();
                    }
                }
            }
            }
            }
            else{
                QMessageBox msgBox;
                msgBox.setText("该账号还未下机");
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
            }
        }
}
}


void pay::on_cancelButton_clicked()
{
    MANAge *w = new MANAge;
    w->show();
    this->close();
}

