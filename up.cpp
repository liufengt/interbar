#include "up.h"
#include "ui_up.h"
#include "manage.h"
#include <QDateTime>
#include <QSqlQuery>
#include <QMessageBox>
//上机功能

up::up(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::up)
{
    ui->setupUi(this);
        this->setWindowTitle("上机");
}

up::~up()
{
    delete ui;
}

void up::on_cancelButton_clicked()
{
    MANAge *w = new MANAge;
    w->show();
    this->close();
}


void up::on_upButton_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM bar");
    QString num = ui->cardline->text();
    QString passline = ui->passwordline->text();
    QString sql = QString("SELECT * FROM bar WHERE card = '%1'").arg(num);   
    if(query.exec(sql)){
        while(query.next()){
        QString passid = query.value(2).toString();
        QString frequency = query.value(5).toString();
        QString state = query.value(3).toString();
        QString pay = query.value(11).toString();

        int fre = frequency.toInt();
        fre++;//上机次数加一
      if(passid == passline){
            if(pay == "未缴费"){
              QMessageBox msgBox;
              msgBox.setText("上机失败,请先将上次费用缴清");
              msgBox.setStandardButtons(QMessageBox::Ok);
              msgBox.exec();
            }
            else{
            if(state == "1"){
              QMessageBox msgBox;
              msgBox.setText("上机失败,该网卡正在使用");
              msgBox.setStandardButtons(QMessageBox::Ok);
              msgBox.exec();
          }
            else{
         int state = 1;
         QDate datetime = QDate::currentDate();
         QString yeartime = datetime.toString("yyyy-MM-dd");//获取日期并转换为qstring
         QTime time = QTime::currentTime();
         QString daytime = time.toString("hh:mm:ss");//获取时间
         QString sql2 = QString("UPDATE bar SET upday='%1',frequency=%2,state=%3,uptime='%4' WHERE card='%5';")
                        .arg(yeartime)
                        .arg(fre)
                        .arg(state)
                        .arg(daytime)
                        .arg(num); // 更新数据
         if(query.exec(sql2)){
             QMessageBox msgBox;
             msgBox.setText("上机成功");
             msgBox.setStandardButtons(QMessageBox::Ok);
             msgBox.exec();
             MANAge *w = new MANAge;
             w->show();
             this->close();
         }
         else{
             QMessageBox msgBox;
             msgBox.setText("上机失败");
             msgBox.setStandardButtons(QMessageBox::Ok);
             msgBox.exec();
         }
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

