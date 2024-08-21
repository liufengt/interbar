#ifndef MANAGE_H
#define MANAGE_H
#include "add.h"

#include <QWidget>

namespace Ui {
class MANAge;
}

class MANAge : public QWidget
{
    Q_OBJECT

public:
    explicit MANAge(QWidget *parent = nullptr);
    ~MANAge();

private slots:
    void on_lookforButton_clicked();

    void on_downButton_clicked();

    void on_logoff_clicked();

    void on_addButton_clicked();

    void on_u_clicked();

    void on_cancelButton_clicked();

    void on_staButton_clicked();

    void on_payButton_clicked();

    void on_rechargeButton_clicked();

private:
    Ui::MANAge *ui;
    add m_dlgcard;
};

#endif // MANAGE_H
