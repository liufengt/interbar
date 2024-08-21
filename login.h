#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_loginButton_clicked();

    void on_Register_clicked();

    void on_cancelButton_clicked();


    void on_checkBox_clicked(bool checked);

private:
    Ui::login *ui;
};

#endif // LOGIN_H
