#include "widget.h"
#include "ui_widget.h"
#include "manage.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
        this->setWindowTitle("登录成功");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_backButton_clicked()
{
    MANAge *w = new MANAge;
    w->show();
    this->close();
}



