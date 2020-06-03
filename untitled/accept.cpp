#include "accept.h"
#include "tcpclient.h"
#include "user.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QMenuBar>
#include <QMenu>
#include <QPushButton>
#include <QDebug>
#include <QAction>
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QLineEdit>
#include <QString>
#include "common.h"
#include <QObject>


accept::accept()
{
    saveFunction();
    connect(tcpsocket.tcpSocket,&QTcpSocket::readyRead,[=]()
    {
        data = tcpsocket.tcpSocket->readAll();
        size = data.size();

     //   qDebug() << data;
        qDebug() << "接受_2";
        deal();

    });



}

void accept::deal()
{
    //第一个空格出现的位置
    int number_l = data.indexOf(' ');
    int number_l_2 = -1;
    for(int i = number_l + 1; i < size ; i ++ )
    {
        if(data[i] == ' ')
        {
            number_l_2 = i;
            break;
        }
    }

    QString pos = data.mid(number_l,number_l_2);

    //第一个 { 出现的位置
    int number_r = data.indexOf('{');
    QByteArray json = data.mid(number_r);

    qDebug() << number_l << "   " << number_l_2;
    QJsonDocument doc = QJsonDocument::fromJson(json);
    QJsonObject obj = doc.object();
    qDebug() << obj;

}
void accept::saveFunction()
{
    mFuncPtr.insert(qMakePair<QString,void*>("18",(void*)&accept::accept_login));
}
