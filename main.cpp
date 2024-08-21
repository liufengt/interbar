#include "login.h"
#include <QApplication>
#include "barsql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    barsql sql;
    login w;
    w.show();
    return a.exec();
    return 0;
}
