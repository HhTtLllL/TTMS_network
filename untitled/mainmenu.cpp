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

Mainmenu::Mainmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mainmenu)
{
    ui->setupUi(this);

}

Mainmenu::~Mainmenu()
{
    delete ui;
}


//切换修改密码的界面
void Mainmenu::on_modify_password_triggered()
{

    //切换界面，切换至 修改密码的界面
    ui->stackedWidget->setCurrentWidget(ui->modify_password_ui);
    //ui->stackedWidget->setCurrentWidget(ui->modifi_password_ui);

}

//切换修改用户信息

void Mainmenu::on_modify_information_triggered()
{
      ui->stackedWidget->setCurrentWidget(ui->modify_information_ui);
}
//切换注销
void Mainmenu::on_logout_triggered()
{
      ui->stackedWidget->setCurrentWidget(ui->logout_ui);
}

//删除电影
void Mainmenu::on_delete_movie_triggered()
{
      ui->stackedWidget->setCurrentWidget(ui->delete_movie_ui);
}

//增加电影
void Mainmenu::on_add_movie_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->add_movie_ui);

}

//修改电影信息
void Mainmenu::on_modify_movie_triggered()
{
     ui->stackedWidget->setCurrentWidget(ui->modify_movie_inforation);
}

// 获取电影
void Mainmenu::on_get_movie_triggered()
{

}
//增加影厅
void Mainmenu::on_add_theater_triggered()
{
      ui->stackedWidget->setCurrentWidget(ui->add_theater_ui);
}
//删除影厅
void Mainmenu::on_delete_theater_triggered()
{
      ui->stackedWidget->setCurrentWidget(ui->delete_theater_ui);
}
//获取全部影厅
void Mainmenu::on_get_theater_triggered()
{

}
//修改影厅信息
void Mainmenu::on_modify_theater_triggered()
{
            ui->stackedWidget->setCurrentWidget(ui->modify_theater_ui);
}
//增加座位
void Mainmenu::on_add_seat_triggered()
{
      ui->stackedWidget->setCurrentWidget(ui->add_movie_plan_ui);
}
//删除座位
void Mainmenu::on_delete_seat_triggered()
{

}
//修改座位
void Mainmenu::on_modify_seat_triggered()
{

}
//获取座位
void Mainmenu::on_get_seat_triggered()
{

}
//增加电影计划
void Mainmenu::on_add_movie_plan_triggered()
{

}
//删除电影计划
void Mainmenu::on_delete_movie_plan_triggered()
{

}
//修改电影计划
void Mainmenu::on_modify_movie_plan_triggered()
{

}
//查询电影计划
void Mainmenu::on_search_movie_plan_triggered()
{

}

//修改用户密码
void Mainmenu::on_pushButton_clicked()
{

    tcpClient& tcpsocket = tcpClient::get_tcpclient();
    User& user = User::get_user();

    //首先判断旧密码 == 用户密码
    if(QString::compare(user.passWord,QString(ui->lineEdit_old_password->text())))
    {
        //错误弹窗
        return ;
    }
    //判断 新密码 == 确认密码

    if(QString::compare(ui->lineEdit_new_password->text(),ui->lineEdit_again_password->text()))
    {
        //错误弹窗

        return ;
    }



    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonObject data;

    //op
    QJsonArray op;
    op.append("=");

    obj.insert("op",QJsonValue(op));
    //tableName
    obj.insert("tableName",QJsonValue("user"));

    set.insert("passWord",QJsonValue(ui->lineEdit_new_password->text()));


    data.insert("uid",QJsonValue(user.uid));

    obj.insert("set",QJsonValue(set));
    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString post;
    post.append("POST /  \r\n");
    post.append(Content_Length);
    post.append(QString::number(sizeof(obj)));
    post.append("\r\n\r\n");

    post.append(doc.toJson());

    tcpsocket.tcpSocket->write(post.toUtf8().data());


}

//修改用户信息
void Mainmenu::on_pushButton_2_clicked()
{
    tcpClient& tcpsocket = tcpClient::get_tcpclient();
    User& user = User::get_user();


    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonObject data;

    //op
    QJsonArray op;
    op.append("=");
    op.append("=");
    op.append("=");

    obj.insert("op",QJsonValue(op));
    //tableName
    obj.insert("tableName",QJsonValue("user"));

    set.insert("sex",QJsonValue(ui->lineEdit_sex->text()));
    set.insert("phone",QJsonValue(ui->lineEdit_phone->text()));
    set.insert("mibao",QJsonValue(ui->lineEdit_mibao->text()));



    data.insert("uid",QJsonValue(user.uid));

    obj.insert("set",QJsonValue(set));
    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString post;
    post.append("POST /  \r\n");
    post.append(Content_Length);
    post.append(QString::number(sizeof(obj)));
    post.append("\r\n\r\n");

    post.append(doc.toJson());

    tcpsocket.tcpSocket->write(post.toUtf8().data());
}

void Mainmenu::on_pushButton_3_clicked()
{
    tcpClient& tcpsocket = tcpClient::get_tcpclient();
    User& user = User::get_user();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonObject data;

    //op
    QJsonArray op;
    op.append("=");
    op.append("=");

    obj.insert("op",QJsonValue(op));
    obj.insert("tableName",QJsonValue("user"));

    data.insert("uid",QJsonValue(user.uid));
    data.insert("passWord",QJsonValue(ui->lineEdit_logout_password->text()));
    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString post;
    post.append("POST /  \r\n");
    post.append(Content_Length);
    post.append(QString::number(sizeof(obj)));
    post.append("\r\n\r\n");

    post.append(doc.toJson());

    tcpsocket.tcpSocket->write(post.toUtf8().data());
}
