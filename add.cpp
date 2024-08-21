#include "add.h"
#include "ui_add.h"
#include "manage.h"
#include "barsql.h"
#include <QMessageBox>
#include <QStandardItemModel>
#include <QSqlQuery>

add::add(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::add)
,m_ptrbarsql(nullptr)
{
    ui->setupUi(this);
        this->setWindowTitle("注册");
}

add::~add()
{
    m_ptrbarsql = barsql::getinstance();
    m_ptrbarsql->init();
    qmodel = new QStandardItemModel();
    QSqlQuery query;
    query.exec("SELECT * FROM bar");
    delete ui;
}

void add::on_cancelButton_clicked()
{
    MANAge *w = new MANAge;
    w->show();
    this->close();
}


void add::on_addButton_clicked()
{
    barinf info;
    auto ptr = barsql::getinstance();
    QString card;
    QString password;
    QString reamount;
    QSqlQuery query;
    QString usercard = ui->cardline->text();
    QString sql = QString("SELECT * FROM bar WHERE card = '%1'").arg(usercard);
    if(query.exec(sql)){
        while(query.next()){
            QString nowcard = query.value(1).toString();
            if(nowcard == usercard){
                goto END;
            }
            else{
                goto LOOP;
            }
    }
    }//判断是否存在重复用户名
    LOOP:
        card = ui->cardline->text();
        password = ui->passwordline->text();
        reamount = ui->reamountline->text();
        info.card = card;
        info.password = password;
        info.reamount = reamount;
        info.frequency = 0;
        info.state = 0;
        if(card == ""||password == ""||reamount == ""){
            QMessageBox msgBox;
            msgBox.setText("用户名，密码或开卡金额为空");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
        }
        else{
        ptr->addCard(info);
        QMessageBox msgBox;
        msgBox.setText("注册成功");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        }
        if(3==2){
    END:
        QMessageBox msgBox;
        msgBox.setText("该用户已存在");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}

