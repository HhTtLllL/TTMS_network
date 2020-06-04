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
    ui->stackedWidget->setCurrentWidget(ui->get_movie_ui);
    ui->tableWidget_movie->setRowCount(5);
    ui->tableWidget_movie->setColumnCount(5);
    ui->tableWidget_movie->setAlternatingRowColors(true);


    QStringList header;
    header<<tr("电影名")<<tr("上映时间")<<tr("下映时间")<<tr("票价")<<tr("电影介绍");
    ui->tableWidget_movie->setHorizontalHeaderLabels(header);

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
    ui->stackedWidget->setCurrentWidget(ui->get_theater_ui);
    ui->tableWidget_studio->setRowCount(5);
    ui->tableWidget_studio->setColumnCount(4);
    ui->tableWidget_studio->setAlternatingRowColors(true);


    QStringList header;
    header<<tr("影厅名")<<tr("行")<<tr("列")<<tr("影厅介绍");
    ui->tableWidget_studio->setHorizontalHeaderLabels(header);



}
//修改影厅信息
void Mainmenu::on_modify_theater_triggered()
{
     ui->stackedWidget->setCurrentWidget(ui->modify_theater_ui);
}
//增加座位
void Mainmenu::on_add_seat_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->add_seat_ui);
}

//修改座位
void Mainmenu::on_modify_seat_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->modify_seat_ui);
}
//获取座位
void Mainmenu::on_get_seat_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->get_seat_studioName);
}
//增加电影计划
void Mainmenu::on_add_movie_plan_triggered()
{
      ui->stackedWidget->setCurrentWidget(ui->add_movie_plan_ui);
}
//删除电影计划
void Mainmenu::on_delete_movie_plan_triggered()
{

}
//修改电影计划
void Mainmenu::on_modify_movie_plan_triggered()
{

}
//获取电影计划
void Mainmenu::on_search_movie_plan_triggered()
{

    //先发送网络请求
    ui->stackedWidget->setCurrentWidget(ui->get_movie_plan_ui);
    ui->tableWidget_studio->setRowCount(5);
    ui->tableWidget_studio->setColumnCount(4);
    ui->tableWidget_studio->setAlternatingRowColors(true);


    QStringList header;
    header<<tr("所在演出厅")<<tr("电影名")<<tr("放映时间");
    ui->tableWidget_movie_plan->setHorizontalHeaderLabels(header);

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
    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();


    QString post;
    post.append("POST /  \r\n");
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

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

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    post.append("POST / \r\n");
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());

}

//注销
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

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    post.append("POST / \r\n");
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());
}


//搜索电影
void Mainmenu::on_pushButton_4_clicked()
{

}

//删除电影
void Mainmenu::on_pushButton_6_clicked()
{
    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonObject data;

    //op
    QJsonArray op;
    op.append("=");

    obj.insert("op",QJsonValue(op));
    obj.insert("tableName",QJsonValue("movie"));
    data.insert("movieName",QJsonValue(ui->lineEdit_delete_moviename->text()));

    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);
    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    post.append("POST / \r\n");
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());

}

//增加电影
void Mainmenu::on_pushButton_7_clicked()
{
    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonArray data;

    set.insert("mid",QJsonValue("NULL"));
    set.insert("movieName",QJsonValue(ui->lineEdit_movie_name->text()));
    set.insert("releaseTime",QJsonValue(ui->dateEdit_releaseTime->text()));
    set.insert("projectionTime",QJsonValue(ui->dateEdit_projectionTime->text()));
    set.insert("price",QJsonValue(ui->lineEdit_movie_price->text()));
    set.insert("introduce",QJsonValue(ui->textEdit_movie_introduce->toPlainText()));

    data.append(set);

    obj.insert("tableName",QJsonValue("movie"));

    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    post.append("POST / \r\n");
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());


}

//修改电影
void Mainmenu::on_pushButton_8_clicked()
{
    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonObject  data;

    //op
    QJsonArray op;
    op.append("=");
    op.append("=");
    op.append("=");
    op.append("=");
    op.append("=");


    set.insert("movieName",QJsonValue(ui->lineEdit_modify_movie->text()));
    set.insert("releaseTime",QJsonValue(ui->dateEdit_modify_releaseTime->text()));
    set.insert("projectionTime",QJsonValue(ui->dateEdit_modify_projectionTme->text()));
    set.insert("price",QJsonValue(ui->lineEdit_modify_price->text()));
    set.insert("introduce",QJsonValue(ui->textEdit_modify_introduce->toPlainText()));

    obj.insert("tableName",QJsonValue("movie"));
    obj.insert("op",QJsonValue(op));
    obj.insert("set",QJsonValue(set));

    data.insert("movieName",QJsonValue(ui->lineEdit_old_moveiname->text()));

    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    post.append("POST / \r\n");
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());
}


//增加影厅
void Mainmenu::on_pushButton_9_clicked()
{
    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonArray data;

    set.insert("sid",QJsonValue("NULL"));
    set.insert("studioName",QJsonValue(ui->lineEdit_studioname->text()));
    set.insert("row",QJsonValue(ui->lineEdit_row->text()));
    set.insert("col",QJsonValue(ui->lineEdit_col->text()));
    set.insert("introduce",QJsonValue(ui->textEdit_studio_introduce->toPlainText()));

    data.append(set);

    obj.insert("tableName",QJsonValue("studio"));

    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);
    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    post.append("POST / \r\n");
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());
}

//删除影厅
void Mainmenu::on_pushButton_10_clicked()
{
    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonObject data;

    QJsonArray op;
    op.append("=");

    data.insert("studioName",QJsonValue(ui->lineEdit_delete_studioName->text()));


    obj.insert("tableName",QJsonValue("studio"));
    obj.insert("op",QJsonValue(op));
    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);
    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    post.append("POST / \r\n");
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());
}

//修改影厅
void Mainmenu::on_pushButton_11_clicked()
{
    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonObject  data;

    QJsonArray op;
    op.append("=");
    op.append("=");
    op.append("=");
    op.append("=");

    set.insert("studioName",QJsonValue(ui->lineEdit_modify_studioname->text()));
    set.insert("row",QJsonValue(ui->lineEdit_modify_row->text()));
    set.insert("col",QJsonValue(ui->lineEdit_modify_col->text()));
    set.insert("introduce",QJsonValue(ui->textEdit_modify_studiointrouduce->toPlainText()));


    obj.insert("tableName",QJsonValue("studio"));

    data.insert("studioName",QJsonValue(ui->lineEdit_old_moveiname->text()));

    obj.insert("set",QJsonValue(set));
    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);
    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    post.append("POST / \r\n");
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());
}

//增加电影计划
void Mainmenu::on_pushButton_12_clicked()
{
    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonArray data;

    set.insert("schid",QJsonValue("NULL"));
    set.insert("studioName",QJsonValue(ui->lineEdit_schedule_studio->text()));
    set.insert("movieName",QJsonValue(ui->lineEdit_schedule_movieName->text()));
    set.insert("datetime",QJsonValue(ui->dateTimeEdit_schedule_datatime->text()));

    data.append(set);

    obj.insert("tableName",QJsonValue("schedule"));

    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    post.append("POST / \r\n");
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());
}

//增加座位
void Mainmenu::on_pushButton_13_clicked()
{

}

//修改座位
void Mainmenu::on_pushButton_15_clicked()
{
    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonObject data;

    QJsonArray op;
    op.append("=");
    op.append("=");
    op.append("=");
    obj.insert("op",QJsonValue(op));



    set.insert("status",QJsonValue(ui->lineEdit_modify_seat_status->text().toInt()));
    obj.insert("set",QJsonValue(set));

    data.insert("studioName",QJsonValue(ui->lineEdit_modify_seat_studioName->text()));
    data.insert("row",QJsonValue(ui->lineEdit_modify_seat_row->text().toInt()));
    data.insert("col",QJsonValue(ui->lineEdit_modify_seat_col->text().toInt()));

    obj.insert("tableName",QJsonValue("seat"));

    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    post.append("POST / \r\n");
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());

}

void Mainmenu::on_pushButton_41_clicked()
{
     tcpClient& tcpsocket = tcpClient::get_tcpclient();

     QJsonObject obj;
     QJsonObject set;  //子对象
     QJsonObject data;

     QJsonArray what;
     what.append("*");

     QJsonArray op;
     op.append("=");

     obj.insert("op",QJsonValue(op));
     obj.insert("what",QJsonValue(what));


     data.insert("studioName",QJsonValue(ui->lineEdit_get_seat_studioName->text()));

     obj.insert("tableName",QJsonValue("seat"));

     obj.insert("data",QJsonValue(data));

     QJsonDocument doc(obj);

     QString json = doc.toJson(QJsonDocument::Compact);

     int size = json.length();

     QString post;
     post.append("POST / \r\n");
     post.append("Content-Length: ");
     post.append(QString::number(size));
     post.append("\r\n\r\n");

     post.append(json);

     tcpsocket.tcpSocket->write(post.toUtf8().data());

}
