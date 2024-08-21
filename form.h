#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}
//未使用
class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
