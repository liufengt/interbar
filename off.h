#include "barsql.h"
#ifndef OFF_H
#define OFF_H

#include <QWidget>

namespace Ui {
class off;
}

class off : public QWidget
{
    Q_OBJECT

public:
    explicit off(QWidget *parent = nullptr);
    ~off();

private slots:
    void on_cancelButton_clicked();

    void on_offButton_clicked();

private:
    Ui::off *ui;
    barsql *m_ptrbarsql;
};

#endif // OFF_H
