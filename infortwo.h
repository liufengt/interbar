#ifndef INFORTWO_H
#define INFORTWO_H
#include "barsql.h"
#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class infortwo;
}

class infortwo : public QWidget
{
    Q_OBJECT

public:
    explicit infortwo(QWidget *parent = nullptr);
    ~infortwo();

private slots:
    void on_backButton_clicked();

    void on_searchButton_clicked();

    void on_clearSchButton_clicked();

private:
    Ui::infortwo *ui;
    barsql *m_ptrbarsql;
    QStandardItemModel *qmodel;
};

#endif // INFORTWO_H
