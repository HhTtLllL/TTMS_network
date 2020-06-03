#include "mainwindow.h"
#include <QApplication>
#include "login.h"
#include "mainmenu.h"
#include "accept.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();


    Mainmenu w2;
   //w2.show();

    accept ac;


    return a.exec();
}
