#ifndef RECHAR_H
#define RECHAR_H

#include <QWidget>

namespace Ui {
class rechar;
}

class rechar : public QWidget
{
    Q_OBJECT

public:
    explicit rechar(QWidget *parent = nullptr);
    ~rechar();

private slots:
    void on_cancelButton_clicked();

    void on_rechargeButton_clicked();

private:
    Ui::rechar *ui;
};

#endif // RECHAR_H
