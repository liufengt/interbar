#ifndef INFORMATION_H
#define INFORMATION_H
#include "barsql.h"
#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class information;
}

class information : public QWidget
{
    Q_OBJECT

public:
    explicit information(QWidget *parent = nullptr);
    ~information();


private slots:

    void on_clearSchButton_clicked();

    void on_backButton_clicked();

    void on_searchButton_clicked();

    void on_imitateButton_clicked();

    void on_clearButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::information *ui;
    barsql *m_ptrbarsql;
    QStandardItemModel *qmodel;
};

#endif // INFORMATION_H
