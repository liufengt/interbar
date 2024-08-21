#include "down.h"
#include "ui_down.h"
#include "manage.h"
#include <QDateTime>
#include <QSqlQuery>
#include <QMessageBox>
//下机功能.
down::down(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::down)
{
    ui->setupUi(this);
        this->setWindowTitle("下机");
}

down::~down()
{
    delete ui;
}

void down::on_downButton_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM bar");
    QString num = ui->cardline->text();
    QString passline = ui->passwordline->text();
    QString sql = QString("SELECT * FROM bar WHERE card = '%1'").arg(num);
    if(query.exec(sql)){
        while(query.next()){
            QString passid = query.value(2).toString();
            QString state = query.value(3).toString();
            if(passid == passline){
                if(state == "0"){
                    QMessageBox msgBox;
                    msgBox.setText("未被使用");
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();
                }
                else{
                    int state = 0;
                    QDate datetime = QDate::currentDate();
                    QString yeartime = datetime.toString("yyyy-MM-dd");//获取日期并转换为qstring
                    QTime time = QTime::currentTime();
                    QString daytime = time.toString("hh:mm:ss");//获取时间
                    QString pay = "未缴费";
                    QString sql2 = QString("UPDATE bar SET downday='%1',state=%2,downtime='%3',pay='%4' WHERE card='%5';")
                                       .arg(yeartime)
                                       .arg(state)
                                       .arg(daytime)
                                       .arg(pay)
                                       .arg(num); // 更新数据
                    if(query.exec(sql2)){
                        QMessageBox msgBox;
                        msgBox.setText("下机成功");
                        msgBox.setStandardButtons(QMessageBox::Ok);
                        msgBox.exec();
                        MANAge *w = new MANAge;
                        w->show();
                        this->close();
                    }
                    else{
                        QMessageBox msgBox;
                        msgBox.setText("下机失败");
                        msgBox.setStandardButtons(QMessageBox::Ok);
                        msgBox.exec();
                    }
                }
            }
            else{
                QMessageBox msgBox;
                msgBox.setText("用户名或密码输入错误");
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
            }
        }
    }
}


void down::on_cancelButton_clicked()
{
    MANAge *w = new MANAge;
    w->show();
    this->close();
}

