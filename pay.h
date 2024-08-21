#ifndef PAY_H
#define PAY_H

#include <QWidget>

namespace Ui {
class pay;
}

class pay : public QWidget
{
    Q_OBJECT

public:
    explicit pay(QWidget *parent = nullptr);
    ~pay();

private slots:
    void on_pauButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::pay *ui;
};

#endif // PAY_H
