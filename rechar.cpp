#include "rechar.h"
#include "ui_rechar.h"
#include "manage.h"
#include <QSqlQuery>
#include <QMessageBox>
//充值功能


rechar::rechar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::rechar)
{
    ui->setupUi(this);
        this->setWindowTitle("充值");
}

rechar::~rechar()
{
    delete ui;
}

void rechar::on_cancelButton_clicked()
{
    MANAge *w = new MANAge;
    w->show();
    this->close();
}


void rechar::on_rechargeButton_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM bar");
    QString nowcard = ui->cardline->text();
    QString money = ui->moneyline->text();
    int nowmoney = money.toInt();
    QString sql = QString("SELECT * FROM bar WHERE card = '%1'").arg(nowcard);
    if(query.exec(sql)){
        while (query.next()) {
            QString nowreamount = query.value(4).toString();
            int nowmount = nowreamount.toInt();
            nowmount+=nowmoney;
            QString reamount = QString::number(nowmount);
            QString sql2 = QString("UPDATE bar SET reamount=%1 WHERE card='%2';")
                            .arg(nowmount)
                            .arg(nowcard);
            if(query.exec(sql2)){
                QMessageBox msgBox;
                msgBox.setText("充值成功");
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
                ui->reamountline->setText(reamount);
            }
            else{
                QMessageBox msgBox;
                msgBox.setText("充值失败");
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
            }
        }
    }
}

