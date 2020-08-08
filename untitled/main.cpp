#include "mainwindow.h"
#include <QApplication>
#include "login.h"
#include "mainmenu.h"
#include "accept.h"
#include "acceptdeal.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();


    Mainmenu w2;
    w2.show();

    Acceptdeal e(new QWidget);

    e.show();


    return a.exec();
}
