#include "login.h"
#include "ui_login.h"
#include "widget.h"
#include "form.h"
#include <QMessageBox>

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员登录");
}

login::~login()
{
    delete ui;
}

void login::on_loginButton_clicked()
{
    if(ui->username->text()!=""&&ui->password->text()!=""){

        if(ui->username->text()==tr("liufeng")&&ui->password->text()==tr("yu678")){
            Widget *w = new Widget;
            w->show();
            this->hide();
        }
        else{
            QMessageBox msgBox;
            msgBox.setText("用户名或密码输入错误");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
        }
    }
    else{
        QMessageBox pass;
        pass.setText("用户名或密码为空");
        pass.setStandardButtons(QMessageBox::Ok);
        pass.exec();
    }
}


void login::on_Register_clicked()
{
    Form *f=new Form();
    f->show();
    this->hide();
}


void login::on_cancelButton_clicked()
{
    this->close();//关闭界面
}


void login::on_checkBox_clicked(bool checked)
{
    if(checked)
    {
        ui->password->setEchoMode(QLineEdit::Normal);
    }//显示密码
    else{
        ui->password->setEchoMode(QLineEdit::Password);
    }
}

