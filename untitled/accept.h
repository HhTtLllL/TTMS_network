#ifndef ACCEPT_H
#define ACCEPT_H

#include <QObject>
#include "tcpclient.h"
#include "user.h"
#include <QWidget>
#include <QMap>
#include <QPair>
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QMenuBar>
#include <QMenu>
#include <QPushButton>
#include <QDebug>
#include <QAction>
#include "tcpclient.h"
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QLineEdit>
#include <QString>
#include "common.h"
#include "user.h"
#include <QTableView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QVBoxLayout>

namespace Ui {
class accept;
}


class accept : public QWidget
{
public:    
    accept();
    void deal();
    tcpClient& tcpsocket = tcpClient::get_tcpclient();
    User& user = User::get_user();

    enum
    {
        MIN,
        INSERTUSER,
        INSERTMOVIE,
        INSERTSEAT,
        INSERTSCHEDULE,
        INSERTSTUDIO,
        INSERTTICKET,
        UPDATEUSER,
        UPDATEMOVIE,
        UPDATESEAT,
        UPDATESCHEDULE,
        UPDATESTUDIO,
        UPDATETICKET,
        DELETEUSER,
        DELETEMOVIE,
        DELETESEAT,
        DELETESCHEDULE,
        DELETESTUDIO,
        DELETETICKET,
        MID,
        QUERYUSER,
        QUERYMOVIE,
        QUERYSEAT,
        QUERYSCHEDULE,
        QUERYSTUDIO,
        QUERYTICKET,
        MAX
    };

    int size; //字符串的大小
    QByteArray data;

    void saveFunction();
    void accept_login(QJsonObject respon); //登录
    void accept_logout(QJsonObject respon); //注销
    void accept_rep(QJsonObject respon);  //注册
    void accept_modify_information(QJsonObject respon); //修改用户信息
    void delete_movie(QJsonObject respon);  //删除电影
    void add_movie(QJsonObject respon);  //增加电影
    void get_movie(QJsonObject respon); //获取 电影
    void modify_movie(QJsonObject respon); //修改电影信息
    void add_studio(QJsonObject respon);  //增加影厅
    void delete_studio(QJsonObject respon); //删除影厅
    void get_studio(QJsonObject respon);  //获取影厅
    void modify_studio(QJsonObject respon);  //修改影厅
    void modify_seat(QJsonObject respon); //修改座位
    void get_seat(QJsonObject respon); //获取座位

    Mainmenu w2;

};

#endif // ACCEPT_H
