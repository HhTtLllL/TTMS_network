#include "acceptdeal.h"
#include "ui_acceptdeal.h"
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

Acceptdeal::Acceptdeal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Acceptdeal)
{
    ui->setupUi(this);

    connect(tcpsocket.tcpSocket,&QTcpSocket::readyRead,[=]()
    {
        data = tcpsocket.tcpSocket->readAll();
        size = data.size();

        qDebug() <<"接受数据" << data;
        qDebug() << "接受_2";
        deal();

    });

}
void Acceptdeal::deal()
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


    qDebug() << pos.toInt();

    if(pos.toInt() == Acceptdeal::QUERYUSER)  //登录
    {
        qDebug() << "调用登录代码";
        accept_login(obj);
    }
    else if(pos.toInt() == Acceptdeal::DELETEUSER) //注销
    {
        accept_logout(obj);
    }
    else if(pos.toInt() == Acceptdeal::INSERTUSER) //注册
    {
        accept_rep(obj);
    }
    else if(pos.toInt() == Acceptdeal::UPDATEUSER) //修改信息
    {
        accept_modify_information(obj);
    }
    else if(pos.toInt() == Acceptdeal::DELETEMOVIE) //删除电影
    {
        delete_movie(obj);
    }
    else if(pos.toInt() == Acceptdeal::INSERTMOVIE) //增加电影
    {
        add_movie(obj);
    }
    else if(pos.toInt() == Acceptdeal::QUERYMOVIE) //获取电影
    {
        get_movie(obj);
    }
    else if(pos.toInt() == Acceptdeal::UPDATEMOVIE) //修改电影
    {
        modify_movie(obj);
    }
    else if(pos.toInt() == Acceptdeal::INSERTSTUDIO) //增加影厅
    {
        add_studio(obj);
    }
    else if(pos.toInt() == Acceptdeal::DELETESTUDIO)  //删除演出厅
    {
        delete_studio(obj);
    }
    else if(pos.toInt() == Acceptdeal::QUERYSTUDIO) //查询演出厅
    {
        get_studio(obj);
    }
    else if(pos.toInt() == Acceptdeal::UPDATESTUDIO)  //修改演出厅
    {
        modify_studio(obj);
    }
    else if(pos.toInt() == Acceptdeal::UPDATESEAT)  //修改座位
    {

    }
    else if(pos.toInt() == Acceptdeal::QUERYSEAT) //获取座位
    {
        get_seatBystudioid(obj);
    }
    else if(pos.toInt() == Acceptdeal::INSERTSCHEDULE) //增加电影计划
    {
        add_schedule(obj);

    }
    else if(pos.toInt() == Acceptdeal::DELETESCHEDULE) //删除电影计划
    {
        delete_schedule(obj);
    }
    else if(pos.toInt() == Acceptdeal::QUERYSCHEDULE)  //查询演出计划
    {
        get_schedule(obj);
    }


}

//登录
void Acceptdeal::accept_login(QJsonObject respon)
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

//获取所有影厅
void Acceptdeal::get_studio(QJsonObject respon)
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
    header<<tr("影厅ID") <<tr("影厅名")<<tr("行")<<tr("列")<<tr("影厅介绍");
    model->setHorizontalHeaderLabels(header);

    QJsonArray data;
    data = respon.value("data").toArray();


    qDebug() << data.size();

    for(int i = 0 ; i < data.size() ; i ++ )
    {
        QJsonObject sub = data.at(i).toObject();
        model->setItem(i,0,new QStandardItem(sub.value("sid").toString()));
        model->setItem(i,1,new QStandardItem(sub.value("studioName").toString()));
        model->setItem(i,2,new QStandardItem(sub.value("row").toString()));
        model->setItem(i,3,new QStandardItem(sub.value("col").toString()));
        model->setItem(i,4,new QStandardItem(sub.value("introduce").toString()));
    }

    ui->tableView_studio->setModel(model);


    //获取成功，展示电影
  /*  ui->stackedWidget->setCurrentWidget(ui->get_theater_ui);
    ui->tableWidget_studio->setRowCount(5);
    ui->tableWidget_studio->setColumnCount(4);
    ui->tableWidget_studio->setAlternatingRowColors(true);*/


}
Acceptdeal::~Acceptdeal()
{
    delete ui;
}

/*
//登录
void Acceptdeal::accept_login(QJsonObject respon)
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



}*/


//注销
void Acceptdeal::accept_logout(QJsonObject respon)
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
void Acceptdeal::accept_rep(QJsonObject respon)
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
void Acceptdeal::accept_modify_information(QJsonObject respon)
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
void Acceptdeal::add_movie(QJsonObject respon)
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
void Acceptdeal::delete_movie(QJsonObject respon)
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
void Acceptdeal::get_movie(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //获取失败
        qDebug() << "获取失败";
        return ;
    }
    qDebug() << "获取成功";
    QStandardItemModel* model = new QStandardItemModel();
    model->setColumnCount(6);

    QStringList header;
    header<<tr("电影ID")<< tr("电影名")<<tr("上映时间")<<tr("下映时间")<<tr("票价")<<tr("电影介绍");
    model->setHorizontalHeaderLabels(header);

    QJsonArray data;
    data = respon.value("data").toArray();


    qDebug() << data.size();

    for(int i = 0 ; i < data.size() ; i ++ )
    {
        QJsonObject sub = data.at(i).toObject();

        model->setItem(i,0,new QStandardItem(sub.value("mid").toString()));
        model->setItem(i,1,new QStandardItem(sub.value("movieName").toString()));
        model->setItem(i,2,new QStandardItem(sub.value("releaseTime").toString()));
        model->setItem(i,3,new QStandardItem(sub.value("projectionTime").toString()));
        model->setItem(i,4,new QStandardItem(sub.value("price").toString()));
        model->setItem(i,5,new QStandardItem(sub.value("introduce").toString()));
    }

    ui->tableView_studio->setModel(model);



    //获取成功，展示电影

}

//修改电影信息
void Acceptdeal::modify_movie(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //修改失败
        qDebug() << "修改失败";
        return ;
    }

    //修改成功
}

//添加电影厅
void Acceptdeal::add_studio(QJsonObject respon)
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
void Acceptdeal::delete_studio(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //删除失败
        qDebug() << "删除失败";
        return ;
    }

    //删除失败
}

/*
//获取所有影厅
void Acceptdeal::get_studio(QJsonObject respon)
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
    ui->tableWidget_studio->setAlternatingRowColors(true);








}*/

//修改电影信息
void Acceptdeal::modify_studio(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //修改失败
        qDebug() << "修改失败";
        return ;
    }

    //修改成功
}

//修改座位
void Acceptdeal::modify_seat(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //修改失败
        qDebug() << "修改失败";
        return ;
    }

    //修改成功
}

void Acceptdeal::get_seat(QJsonObject respon)
{

}



//获取演出计划
void Acceptdeal::get_schedule(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //获取失败
        qDebug() << "获取失败";
        return ;
    }
    qDebug() << "获取成功";
    QStandardItemModel* model = new QStandardItemModel();
    model->setColumnCount(4);

    QStringList header;
    header<<tr("schid")<<tr("所在演出厅")<<tr("所播电影")<<tr("上映时间");
    model->setHorizontalHeaderLabels(header);

    QJsonArray data;
    data = respon.value("data").toArray();


    qDebug() << data.size();

    for(int i = 0 ; i < data.size() ; i ++ )
    {
        QJsonObject sub = data.at(i).toObject();

        model->setItem(i,0,new QStandardItem(sub.value("schid").toString()));
        model->setItem(i,1,new QStandardItem(sub.value("studioName").toString()));
        model->setItem(i,2,new QStandardItem(sub.value("movieName").toString()));
        model->setItem(i,3,new QStandardItem(sub.value("datetime").toString()));
    }

    ui->tableView_studio->setModel(model);
}

void Acceptdeal::add_schedule(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //修改失败
        qDebug() << "修改失败";
        return ;
    }

    //修改成功
}

void Acceptdeal::delete_schedule(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //修改失败
        qDebug() << "修改失败";
        return ;
    }

    //修改成功
}

void Acceptdeal::get_seatBystudioid(QJsonObject respon)
{
    if( respon.value("state").toInt() == 400 )
    {
        //获取失败
        qDebug() << "获取失败";
        return ;
    }

    //先获取行和列
    QJsonArray data;
    data = respon.value("data").toArray();

    int max = data.size();

    QJsonObject sub = data.at(max-1).toObject();
    QString srow = sub.value("row").toString();
    QString scol = sub.value("col").toString();


  /*  for(int i = 0 ; i < max ; i ++ )
    {
         QJsonObject sub = data.at(i).toObject();
         qDebug() << sub.value("row").toString() << " " << sub.value("row").toString();

         QString row = sub.value("row").toString();

         qDebug() << "row_int = " << row.toInt();

    }*/



    int maxRow = srow.toInt();
    int maxCol = scol.toInt();


    qDebug() << "获取成功" << maxRow << " " << maxCol;
    QStandardItemModel* model = new QStandardItemModel();
    model->setColumnCount(maxCol);
    model->setRowCount(maxRow);

    qDebug() << data.size();

    int num = 0;

    for(int i = 0 ; i < maxCol ; i ++ )
    {
        for(int j = 0 ; j < maxRow ; j ++ )
        {
            QJsonObject sub = data.at(num).toObject();
            QStandardItem* item = new QStandardItem(sub.value("seatid").toString());
            if(sub.value("status").toString() == "1")
            {
                 item->setFont(QFont("song",14));
                 qDebug() << " 状态";
            }

            model->setItem(i,j,item);


            num++;
        }
    }

    ui->tableView_studio->setModel(model);
}
