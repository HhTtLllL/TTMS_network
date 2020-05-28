#include "mainwindow.h"
#include <QApplication>
#include "login.h"
#include "mainmenu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    //w.show();
    Mainmenu w1;
    w1.show();


    return a.exec();
}
