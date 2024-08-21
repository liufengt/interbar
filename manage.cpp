#include "manage.h"
#include "ui_manage.h"
#include "information.h"
#include "down.h"
#include "off.h"
#include "add.h"
#include "vip.h"
#include "up.h"
#include "rechar.h"
#include "pay.h"
//网吧计费管理主界面

MANAge::MANAge(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MANAge)
{
    ui->setupUi(this);
        this->setWindowTitle("网吧计费管理");
}

MANAge::~MANAge()
{
    delete ui;
}

void MANAge::on_lookforButton_clicked()
{
    information *w = new information;
    w->show();
    this->close();
}


void MANAge::on_downButton_clicked()
{
    down *w = new down;
    w->show();
    this->close();
}



void MANAge::on_logoff_clicked()
{
    off *w = new off;
    w->show();
    this->close();
}


void MANAge::on_addButton_clicked()
{
    add *w = new add;
    w->show();
    this->close();
}


void MANAge::on_u_clicked()
{
    up *w = new up;
    w->show();
    this->close();
}


void MANAge::on_cancelButton_clicked()
{
    delete ui;
}


void MANAge::on_staButton_clicked()
{
    vip *w = new vip;
    w->show();
    this->close();
}


void MANAge::on_payButton_clicked()
{
    rechar *w = new rechar;
    w->show();
    this->close();
}


void MANAge::on_rechargeButton_clicked()
{
    pay *w = new pay;
    w->show();
    this->close();
}

