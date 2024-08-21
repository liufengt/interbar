#include "off.h"
#include "ui_off.h"
#include "manage.h"
#include <QList>
#include <QSqlQuery>
#include <QMessageBox>
//注销功能

off::off(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::off)
,m_ptrbarsql(nullptr)
{
    ui->setupUi(this);
        this->setWindowTitle("注销");
    m_ptrbarsql = barsql::getinstance();
    m_ptrbarsql->init();
}

off::~off()
{
    delete ui;
}

void off::on_cancelButton_clicked()
{
    MANAge *w = new MANAge;
    w->show();
    this->close();
}


void off::on_offButton_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM bar");
    QString usercard = ui->usercard->text();
    QString userpassid = ui->password->text();
    QString sql = QString("SELECT * FROM bar WHERE card = '%1'").arg(usercard);
        if(query.exec(sql)){
        while(query.next())
        {
        QString passid = query.value(2).toString();
        if(userpassid == passid){
        QString sql2 = QString("delete from bar where card = '%1'").arg(usercard);
            if(query.exec(sql2)){
                    QMessageBox msgBox;
                    msgBox.setText("注销成功");
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();
            }
        }
        else{
            QMessageBox msgBox;
            msgBox.setText("注销失败，用户名或密码错误");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
        }
        }
        }
}

