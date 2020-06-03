#ifndef ACCEPT_H
#define ACCEPT_H

#include <QObject>
#include "tcpclient.h"
#include "user.h"
#include <QWidget>
#include <QMap>
#include <QPair>

typedef void* (*FUNC)();

class accept : public QWidget
{
public:
    accept();
    void deal();
    tcpClient& tcpsocket = tcpClient::get_tcpclient();
    User& user = User::get_user();

    QMap<QString,void*> mFuncPtr;

    enum
      {
          MIN,
          INSERTUSER,
          INSERTMOVIE,
          INSERTSEAT,
          INSERTSCHEDULE,
          INSERTSTUDIO,
          UPDATEUSER,
          UPDATEMOVIE,
          UPDATESEAT,
          UPDATESCHEDULE,
          UPDATESTUDIO,
          DELETEUSER,
          DELETEMOVIE,
          DELETESEAT,
          DELETESCHEDULE,
          DELETESTUDIO,
          MID,
          QUERYUSER,  //登录   18
          QUERYMOVIE,
          QUERYSEAT,
          QUERYSCHEDULE,
          QUERYSTUDIO,
          MAX
      };

    int size; //字符串的大小
    QByteArray data;

    void saveFunction();
    void* accept_login(); //登录
};

#endif // ACCEPT_H
