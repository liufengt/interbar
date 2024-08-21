#ifndef UP_H
#define UP_H

#include <QWidget>

namespace Ui {
class up;
}

class up : public QWidget
{
    Q_OBJECT

public:
    explicit up(QWidget *parent = nullptr);
    ~up();

private slots:
    void on_cancelButton_clicked();

    void on_upButton_clicked();

private:
    Ui::up *ui;
};

#endif // UP_H
