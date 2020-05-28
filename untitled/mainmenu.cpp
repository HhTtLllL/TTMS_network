#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QMenuBar>
#include <QMenu>
#include <QPushButton>
#include <QDebug>
#include <QAction>

Mainmenu::Mainmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mainmenu)
{
    ui->setupUi(this);

    connect(ui->modify_password,&QAction::triggered,[=]()

    {
        qDebug() << "修改密码" ;
    });
    /*connect(ui->modify_password,&QPushButton::clicked,[=]()

    {
        qDebug() << "修改密码" ;
    });*/

}

Mainmenu::~Mainmenu()
{
    delete ui;
}
