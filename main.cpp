#include "market.h"
#include "mainmenu.h"
#include <QApplication>
#include "registerwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RegisterWindow w;
    w.show();
    return a.exec();
}
