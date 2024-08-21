#ifndef DOWN_H
#define DOWN_H

#include <QWidget>

namespace Ui {
class down;
}

class down : public QWidget
{
    Q_OBJECT

public:
    explicit down(QWidget *parent = nullptr);
    ~down();

private slots:
    void on_downButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::down *ui;
};

#endif // DOWN_H
