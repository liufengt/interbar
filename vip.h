#ifndef VIP_H
#define VIP_H

#include <QWidget>

namespace Ui {
class vip;
}

class vip : public QWidget
{
    Q_OBJECT

public:
    explicit vip(QWidget *parent = nullptr);
    ~vip();

private slots:
    void on_cancelButton_clicked();

    void on_vipButton_clicked();

    void on_svipButton_clicked();

private:
    Ui::vip *ui;
};

#endif // VIP_H
