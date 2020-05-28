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

        //切换界面，切换至 修改密码的界面
        ui->stackedWidget->setCurrentWidget(ui->modify_password_ui);
        //ui->stackedWidget->setCurrentWidget(ui->modifi_password_ui);
    });

    connect(ui->modify_information,&QAction::triggered,[=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->modify_information_ui);
    });

    connect(ui->logout,&QAction::triggered,[=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->logout_ui);

    });

    connect(ui->delete_movie,&QAction::triggered,[=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->delete_movie_ui);

    });

    connect(ui->add_movie,&QAction::triggered,[=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->add_movie_ui);
    });

    connect(ui->modify_movie,&QAction::triggered,[=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->modify_movie_inforation);
    });

    connect(ui->add_theater,&QAction::triggered,[=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->add_theater_ui);
    });

    connect(ui->delete_theater,&QAction::triggered,[=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->delete_theater_ui);
    });

    connect(ui->modify_theater,&QAction::triggered,[=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->modify_theater_ui);
    });

    connect(ui->add_movie_plan,&QAction::triggered,[=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->add_movie_plan_ui);
    });
}

Mainmenu::~Mainmenu()
{
    delete ui;
}
