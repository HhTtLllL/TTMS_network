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
#include <QStandardItemModel>
#include <QMessageBox>

accept::accept()
{
  /*  connect(tcpsocket.tcpSocket,&QTcpSocket::readyRead,[=]()
    {
        data = tcpsocket.tcpSocket->readAll();
        size = data.size();

        qDebug() <<"接受数据" << data;
        qDebug() << "接受_2";
        deal();

    });*/




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

    QString pos = data.mid(number_l+1,number_l_2 - number_l - 1);

    //第一个 { 出现的位置
    int number_r = data.indexOf('{');
    QByteArray json = data.mid(number_r);

    qDebug() << number_l << "   " << number_l_2;
    QJsonDocument doc = QJsonDocument::fromJson(json);
    QJsonObject obj = doc.object();
    qDebug() << obj;



    if(pos.toInt() == accept::QUERYUSER)  //登录
    {
        qDebug() << "调用登录代码";
        accept_login(obj);
    }
    else if(pos.toInt() == accept::DELETEUSER) //注销
    {
        accept_logout(obj);
    }
    else if(pos.toInt() == accept::INSERTUSER) //注册
    {
        accept_rep(obj);
    }
    else if(pos.toInt() == accept::UPDATEUSER) //修改信息
    {
        accept_modify_information(obj);
        QMessageBox::information(NULL, "修改信息", "成功修改");
    }
    else if(pos.toInt() == accept::DELETEMOVIE) //删除电影
    {
        delete_movie(obj);
        QMessageBox::information(NULL, "删除电影", "成功删除");
    }
    else if(pos.toInt() == accept::INSERTMOVIE) //增加电影
    {
        add_movie(obj);
        QMessageBox::information(NULL, "增加电影", "增加成功");
    }
    else if(pos.toInt() == accept::QUERYMOVIE) //获取电影
    {
        get_movie(obj);
        QMessageBox::information(NULL, "获取电影", "获取成功");
    }
    else if(pos.toInt() == accept::UPDATEMOVIE) //修改电影
    {
        modify_movie(obj);
        QMessageBox::information(NULL, "修改电影", "成功修改");
    }
    else if(pos.toInt() == accept::INSERTSTUDIO) //增加影厅
    {
        add_studio(obj);
        QMessageBox::information(NULL, "增加影厅", "成功增加");
    }
    else if(pos.toInt() == accept::DELETESTUDIO)  //删除演出厅
    {
        delete_studio(obj);
        QMessageBox::information(NULL, "删除演出厅", "成功删除");
    }
    else if(pos.toInt() == accept::QUERYSTUDIO) //查询演出厅
    {
        get_studio(obj);
        QMessageBox::information(NULL, "查询演出厅", "查询成功");
    }
    else if(pos.toInt() == accept::UPDATESTUDIO)  //修改演出厅
    {
        modify_studio(obj);
        QMessageBox::information(NULL, "修改演出厅", "成功修改");
    }
    else if(pos.toInt() == accept::UPDATESEAT)  //修改座位
    {
        QMessageBox::information(NULL, "修改作为", "成功修改");

    }
    else if(pos.toInt() == accept::QUERYSEAT) //获取座位
    {
        QMessageBox::information(NULL, "获取座位", "成功获取");

    }
    else if(pos.toInt() == accept::INSERTSCHEDULE) //增加电影计划
    {
        QMessageBox::information(NULL, "增加电影", "成功增加");
    }
    else if(pos.toInt() == accept::UPDATESCHEDULE) //修改电影计划
    {
        QMessageBox::information(NULL, "修改电影计划", "成功修改");

    }
    else if(pos.toInt() == accept::DELETESCHEDULE) //删除电影计划
    {

        QMessageBox::information(NULL, "删除电影计划", "成功删除");
    }
    else if(pos.toInt() == accept::QUERYSCHEDULE)  //查询演出计划
    {

        QMessageBox::information(NULL, "查询演出计划", "查询成功");
    }

}
/*
void accept::saveFunction()
{
    pFunc = &accept::accept_login;
    mFuncPtr.insert(qMakePair<QString,void*>("18",(void*)&accept::accept_login));
}*/


//登录
void accept::accept_login(QJsonObject respon)
{
    QJsonValue value;


    if( respon.value("state").toInt() == 400 )
    {
        //登录失败
        qDebug() << "登录失败";
        return ;
    }

    QJsonArray  data = respon.value("data").toArray();
    int nSize = data.size();

    for(int i = 0 ; i < nSize ; i ++ )
    {
        user.uid = data.at(i).toObject().value("uid").toInt();
        user.userName = data.at(i).toObject().value("userName").toString();
        user.passWord = data.at(i).toObject().value("passWord").toString();
        //user.sex = data.at(i).toObject().value("sex").toString();
        user.phoneNumber = data.at(i).toObject().value("phoneNumber").toString();
        user.mibao = data.at(i).toObject().value("mibao").toString();
        user.power = data.at(i).toObject().value("power").toInt();
    }

    qDebug() << "调用登录主菜单";
    w2.show();
}

//注销
void accept::accept_logout(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //登录失败
        qDebug() << "注销失败";
        return ;
    }

    //注销成功
    //关闭界面
}

//注册
void accept::accept_rep(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //注册失败
        qDebug() << "注册失败";
        return ;
    }

    //注册成功  --弹出一个窗口


}

//修改用户信息
void accept::accept_modify_information(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //修改失败
        qDebug() << "修改失败";
        return ;
    }

    //修改成功
}

//添加电影
void accept::add_movie(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //添加失败
        qDebug() << "添加失败";
        return ;
    }

    //添加失败
}

//删除电影
void accept::delete_movie(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //删除失败
        qDebug() << "删除失败";
        return ;
    }

    //删除失败
}

//获取所有电影
void accept::get_movie(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //获取失败
        qDebug() << "获取失败";
        return ;
    }


    QStandardItemModel* model = new QStandardItemModel();
    model->setColumnCount(5);

    QStringList header;
    header<<tr("电影名")<<tr("上映时间")<<tr("下映时间")<<tr("票价")<<tr("电影介绍");
    model->setHorizontalHeaderLabels(header);

    QJsonArray data;
    data = respon.value("data").toArray();


    qDebug() << data.size();

    for(int i = 0 ; i < data.size() ; i ++ )
    {
        QJsonObject sub = data.at(i).toObject();
        QString studioName = sub.value("studioName").toString();

        model->setItem(i,0,new QStandardItem(studioName));
        model->setItem(i,0,new QStandardItem(studioName));
        model->setItem(i,0,new QStandardItem(studioName));
        model->setItem(i,0,new QStandardItem(studioName));


    }

    //获取成功，展示电影

}

//修改电影信息
void accept::modify_movie(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //修改失败
        qDebug() << "修改失败";
        return ;
    }
}

//添加电影厅
void accept::add_studio(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //添加失败
        qDebug() << "添加失败";
        return ;
    }

    //添加失败
}

//删除电影厅
void accept::delete_studio(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //删除失败
        qDebug() << "删除失败";
        return ;
    }

    //删除失败
}

//获取所有影厅
void accept::get_studio(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //获取失败
        qDebug() << "获取失败";
        return ;
    }

    qDebug() << "获取影厅";
    QStandardItemModel* model = new QStandardItemModel();
    model->setColumnCount(4);

    QStringList header;
    header<<tr("影厅名")<<tr("行")<<tr("列")<<tr("影厅介绍");
    model->setHorizontalHeaderLabels(header);

    QJsonArray data;
    data = respon.value("data").toArray();


    qDebug() << data.size();

    for(int i = 0 ; i < data.size() ; i ++ )
    {
        QJsonObject sub = data.at(i).toObject();
        QString studioName = sub.value("studioName").toString();
        model->setItem(i,0,new QStandardItem(studioName));


    }

    //获取成功，展示电影
  /*  ui->stackedWidget->setCurrentWidget(ui->get_theater_ui);
    ui->tableWidget_studio->setRowCount(5);
    ui->tableWidget_studio->setColumnCount(4);
    ui->tableWidget_studio->setAlternatingRowColors(true);*/

}

//修改电影信息
void accept::modify_studio(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //修改失败
        qDebug() << "修改失败";
        return ;
    }

    //修改成功
}

void accept::modify_seat(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //修改失败
        qDebug() << "修改失败";
        return ;
    }

    //修改成功
}

void accept::get_seat(QJsonObject respon)
{

}
