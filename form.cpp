#include "form.h"
#include "ui_form.h"
#include "login.h"
#include <QMessageBox>
#include <QSettings>
#include <QString>

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
   this->setWindowTitle("注册");
}

Form::~Form()
{
    delete ui;
}



void Form::on_pushButton_clicked()
{
    QString name,pass,pass2;
    name = ui->namelineEdit->text();
    pass = ui->passwordlineEdit->text();
    pass2 = ui->passwordlineEdit2->text();
    if(name!=""&&pass!=""&&pass!=""){
        if(pass==pass2){
            QMessageBox rgs;
            rgs.setText("注册成功");
            rgs.setStandardButtons(QMessageBox::Yes);
            rgs.exec();
            login *l = new login;
            l->show();
            this->close();
        }
        else{
            QMessageBox pass;
            pass.setText("两次密码输入不一致");
            pass.setStandardButtons(QMessageBox::Ok);
            pass.exec()
                ;        }
    }

    else{
        QMessageBox pass_2;
        pass_2.setText("用户名或密码为空");
        pass_2.setStandardButtons(QMessageBox::Ok);
    }
}



void Form::on_cancelButton_clicked()
{
    login *l=new login();
    l->show();
    this->close();
}

