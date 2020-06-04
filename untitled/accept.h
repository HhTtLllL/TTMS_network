#ifndef ACCEPT_H
#define ACCEPT_H

#include <QObject>
#include "tcpclient.h"
#include "user.h"
#include <QWidget>
#include <QMap>
#include <QPair>
#include "mainmenu.h"


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
          INSERTUSER,  //注册 2
          INSERTMOVIE, //添加电影 3
          INSERTSEAT,
          INSERTSCHEDULE,
          INSERTSTUDIO, //增加影厅 6
          UPDATEUSER,  //修改用户信息 7
          UPDATEMOVIE, //修改电影信息 8
          UPDATESEAT,
          UPDATESCHEDULE,
          UPDATESTUDIO, //修改影厅 11
          DELETEUSER,  //注销  12
          DELETEMOVIE,  //删除电影 13
          DELETESEAT,
          DELETESCHEDULE,
          DELETESTUDIO,//删除影厅 16
          MID,
          QUERYUSER,  //登录   18
          QUERYMOVIE, //获取电影 19
          QUERYSEAT,
          QUERYSCHEDULE,
          QUERYSTUDIO, //获取影厅22
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
