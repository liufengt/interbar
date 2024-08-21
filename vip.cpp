#include "vip.h"
#include "ui_vip.h"
#include "manage.h"
#include <QSqlQuery>
#include <QMessageBox>
//会员功能

vip::vip(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::vip)
{
    ui->setupUi(this);
        this->setWindowTitle("用户升级");
}

vip::~vip()
{
    delete ui;
}

void vip::on_cancelButton_clicked()
{
    MANAge *w = new MANAge;
    w->show();
    this->close();
}



void vip::on_vipButton_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM bar");
    QString usercard = ui->cardline->text();
    QString sql = QString("SELECT * FROM bar WHERE card = '%1'").arg(usercard);
    if(query.exec(sql)){
        while(query.next()){
            QString nowvip = query.value(10).toString();
            if(nowvip == "vip"||nowvip == "svip"){
                QMessageBox msgBox;
                msgBox.setText("该号已是vip或svip");
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
            }
            else{
                QString vip = "vip";
                QString sql2 = QString("UPDATE bar SET vip='%1' WHERE card='%2';").arg(vip).arg(usercard);
                if(query.exec(sql2)){
                    QMessageBox msgBox;
                    msgBox.setText("升级为vip成功");
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();
                }
            }
        }
    }
}


void vip::on_svipButton_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM bar");
    QString usercard = ui->cardline->text();
    QString sql = QString("SELECT * FROM bar WHERE card = '%1'").arg(usercard);
    if(query.exec(sql)){
        while(query.next()){
            QString nowvip = query.value(10).toString();
            if(nowvip == "vip"||nowvip == "svip"){
                QMessageBox msgBox;
                msgBox.setText("该号已是vip或svip");
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
            }
            else{
                QString svip = "svip";
                QString sql2 = QString("UPDATE bar SET vip='%1' WHERE card='%2';").arg(svip).arg(usercard);
                if(query.exec(sql2)){
                    QMessageBox msgBox;
                    msgBox.setText("升级为svip成功");
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();

                }
            }
        }
    }
}
