#ifndef ADD_H
#define ADD_H
#include <QStandardItemModel>
#include <QWidget>
#include "barsql.h"

namespace Ui {
class add;
}

class add : public QWidget
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

private slots:
    void on_cancelButton_clicked();

    void on_addButton_clicked();

private:
    Ui::add *ui;
    barsql *m_ptrbarsql;
    QStandardItemModel *qmodel;
};

#endif // ADD_H
