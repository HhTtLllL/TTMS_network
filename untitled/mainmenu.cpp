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
#include "accept.h"
#include "acceptdeal.h"
#include <QMessageBox>

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

//买票


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

    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonObject limit;

    QJsonArray what;
    what.append("*");
    obj.insert("what",QJsonValue(what));



    limit.insert("limit",QJsonValue("0,5"));

    obj.insert("tableName",QJsonValue("movie"));

    obj.insert("data",QJsonValue(limit));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::QUERYMOVIE;
    post.sprintf("POST /?%d \r\n",num);
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());

/*
    ui->stackedWidget->setCurrentWidget(ui->get_movie_ui);
    ui->tableWidget_movie->setRowCount(5);
    ui->tableWidget_movie->setColumnCount(5);
    ui->tableWidget_movie->setAlternatingRowColors(true);


    QStringList header;
    header<<tr("电影名")<<tr("上映时间")<<tr("下映时间")<<tr("票价")<<tr("电影介绍");
    ui->tableWidget_movie->setHorizontalHeaderLabels(header);

*/

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
    get_studio();
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
    ui->stackedWidget->setCurrentWidget(ui->delete_schedule_ui);
}
//修改电影计划
void Mainmenu::on_modify_movie_plan_triggered()
{

}
//获取电影计划
void Mainmenu::on_search_movie_plan_triggered()
{
    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonObject limit;

    QJsonArray what;
    what.append("*");
    obj.insert("what",QJsonValue(what));



    obj.insert("limit",QJsonValue("0,5"));

    obj.insert("tableName",QJsonValue("view_schedule"));

    //obj.insert("data",QJsonValue(limit));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::QUERYSCHEDULE;
    post.sprintf("POST /?%d \r\n",num);
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());







    //先发送网络请求

   /* ui->stackedWidget->setCurrentWidget(ui->get_movie_plan_ui);
    ui->tableWidget_movie_plan->setRowCount(5);
    ui->tableWidget_movie_plan->setColumnCount(4);
    ui->tableWidget_movie_plan->setAlternatingRowColors(true);


    QStringList header;
    header<< tr("sid") << tr("所在演出厅") << tr("电影名") << tr("放映时间");
    ui->tableWidget_movie_plan->setHorizontalHeaderLabels(header);*/


}

//修改用户密码
void Mainmenu::on_pushButton_clicked()
{
    qDebug() << "修改密码";

    tcpClient& tcpsocket = tcpClient::get_tcpclient();
    User& user = User::get_user();

    //首先判断旧密码 == 用户密码
   /* if(QString::compare(user.passWord,QString(ui->lineEdit_old_password->text())))
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
*/


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
    int num = accept::UPDATEUSER;
    post.sprintf("POST /?%d \r\n",num);
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());
    qDebug() <<" post = " <<  post;


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

    QString sex = "'";
    sex += ui->lineEdit_sex->text();
    sex += "'";
    set.insert("sex",QJsonValue(sex));
    QString phone = "'";


    phone += ui->lineEdit_phone->text();
    phone += "'";
    set.insert("phoneNumber",QJsonValue(phone));

    QString mibao = "'";
    mibao += ui->lineEdit_mibao->text();
    mibao += "'";
    set.insert("mibao",QJsonValue(mibao));



    data.insert("uid",QJsonValue(user.uid));

    obj.insert("set",QJsonValue(set));
    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::UPDATEUSER;
    post.sprintf("POST /?%d \r\n",num);
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
    int num = accept::DELETEUSER;
    post.sprintf("POST /?%d \r\n",num);
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
    QString name = "'";
    name += ui->lineEdit_delete_moviename->text();
    name += "'";
    data.insert("movieName",QJsonValue(name));

    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);
    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::DELETEMOVIE;
    post.sprintf("POST /?%d \r\n",num);
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
    QString name = "'";
    name += ui->lineEdit_movie_name->text();
    name += "'";
    set.insert("movieName",QJsonValue(name));
    set.insert("releaseTime",QJsonValue(ui->dateEdit_releaseTime->text()));
    set.insert("projectionTime",QJsonValue(ui->dateEdit_projectionTime->text()));
    set.insert("price",QJsonValue(ui->lineEdit_movie_price->text()));
    QString introduce  = "'";
    introduce += ui->textEdit_movie_introduce->toPlainText();
    introduce += "'";


    set.insert("introduce",QJsonValue(introduce));

    data.append(set);

    obj.insert("tableName",QJsonValue("movie"));

    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::INSERTMOVIE;
    post.sprintf("POST /?%d \r\n",num);
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

    QString newname = "'";
    newname += ui->lineEdit_modify_movie->text();
    newname += "'";
    set.insert("movieName",QJsonValue(newname));

    set.insert("releaseTime",QJsonValue(ui->dateEdit_modify_releaseTime->text()));
    set.insert("projectionTime",QJsonValue(ui->dateEdit_modify_projectionTme->text()));
    set.insert("price",QJsonValue(ui->lineEdit_modify_price->text()));

    QString introuce = "'";
    introuce += ui->textEdit_modify_introduce->toPlainText();
    introuce += "'";
    set.insert("introduce",QJsonValue(introuce));

    obj.insert("tableName",QJsonValue("movie"));
    obj.insert("op",QJsonValue(op));
    obj.insert("set",QJsonValue(set));

    QString name = "'";
    name += ui->lineEdit_old_moveiname->text();
    name += "'";
    data.insert("movieName",QJsonValue(name));

    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::UPDATEMOVIE;
    post.sprintf("POST /?%d \r\n",num);
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
    QString name = "'";
    name += ui->lineEdit_studioname->text();
    name += "'";
    set.insert("studioName",QJsonValue(name));
    set.insert("row",QJsonValue(ui->lineEdit_row->text()));
    set.insert("col",QJsonValue(ui->lineEdit_col->text()));
    QString introduce = "'";
    introduce += ui->textEdit_studio_introduce->toPlainText();
    introduce += "'";
    set.insert("introduce",QJsonValue(introduce));

    data.append(set);

    obj.insert("tableName",QJsonValue("studio"));

    obj.insert("data",QJsonValue(data));

    qDebug() << obj;
    QJsonDocument doc(obj);
    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::INSERTSTUDIO;
    post.sprintf("POST /?%d \r\n",num);
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

    QString name = "'";
    name += ui->lineEdit_delete_studioName->text();
    name += "'";

    data.insert("studioName",QJsonValue(name));


    obj.insert("tableName",QJsonValue("studio"));
    obj.insert("op",QJsonValue(op));
    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);
    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::DELETESTUDIO;
    post.sprintf("POST /?%d \r\n",num);
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

    QString newname = "'";
    newname += ui->lineEdit_modify_studioname->text();
    newname += "'";


    set.insert("studioName",QJsonValue(newname));
    set.insert("row",QJsonValue(ui->lineEdit_modify_row->text()));
    set.insert("col",QJsonValue(ui->lineEdit_modify_col->text()));

    QString introduce = "'";
    introduce += ui->textEdit_modify_studiointrouduce->toPlainText();
    introduce += "'";
    set.insert("introduce",QJsonValue(introduce));


    obj.insert("tableName",QJsonValue("studio"));
    obj.insert("op",QJsonValue(op));

    QString name = "'";
    name += ui->lineEdit_modify_old_studioname->text();
    name += "'";

    qDebug() << "name = " << name;
    data.insert("studioName",QJsonValue(name));

    obj.insert("set",QJsonValue(set));
    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);
    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::UPDATESTUDIO;
    post.sprintf("POST /?%d \r\n",num);
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

   /* QString studioname = "'";
    studioname += ui->lineEdit_schedule_studio->text();
    studioname += "'";*/
    set.insert("studioid",QJsonValue(ui->lineEdit_schedule_studio->text()));


   /* QString moviename = "'";
    moviename += ui->lineEdit_schedule_movieName->text();
    moviename += "'";*/

    set.insert("movieid",QJsonValue(ui->lineEdit_schedule_movieName->text()));

    QString date = "'";
    date += ui->dateEdit_add_sch->text();
    date += "'";
    set.insert("datetime",QJsonValue(date));

    data.append(set);

    obj.insert("tableName",QJsonValue("schedule"));

    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::INSERTSCHEDULE;
    post.sprintf("POST /?%d \r\n",num);
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

    obj.insert("op",QJsonValue(op));



    set.insert("status",QJsonValue(ui->lineEdit_modify_seat_status->text().toInt()));
    obj.insert("set",QJsonValue(set));

    data.insert("seatid",QJsonValue(ui->lineEdit_modify_seatid->text()));

    obj.insert("tableName",QJsonValue("seat"));

    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::UPDATESEAT;
    post.sprintf("POST /?%d \r\n",num);
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());

}


//获取座位
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


     data.insert("studioid",QJsonValue(ui->lineEdit_get_seat_studioid->text().toInt()));

     obj.insert("tableName",QJsonValue("seat"));

     obj.insert("data",QJsonValue(data));

     QJsonDocument doc(obj);

     QString json = doc.toJson(QJsonDocument::Compact);

     int size = json.length();

     QString post;
     int num = accept::QUERYSEAT;
     post.sprintf("POST /?%d \r\n",num);
     post.append("Content-Length: ");
     post.append(QString::number(size));
     post.append("\r\n\r\n");

     post.append(json);

     tcpsocket.tcpSocket->write(post.toUtf8().data());

}

//获取演出厅
void Mainmenu::get_studio()
{
    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonObject limit;

    QJsonArray what;
    what.append("*");
    obj.insert("what",QJsonValue(what));



    limit.insert("limit",QJsonValue("0,5"));

    obj.insert("tableName",QJsonValue("studio"));

    obj.insert("data",QJsonValue(limit));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::QUERYSTUDIO;
    post.sprintf("POST /?%d \r\n",num);
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());

}

//删除电影计划ID
/*
void Mainmenu::on_pushButton_42_clicked()
{

    qDebug() << "点击删除电影计划";
    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonObject data;

    QJsonArray op;
    op.append("=");
    obj.insert("op",QJsonValue(op));

    data.insert("uid",QJsonValue(ui->lineEdit_delete_movieID->text().toInt()));




    obj.insert("tableName",QJsonValue("schedule"));

    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::DELETESCHEDULE;
    post.sprintf("POST /?%d \r\n",num);
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());


    qDebug() << "发送";

}*/


void Mainmenu::on_pushButton_43_clicked()
{


    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    QJsonObject obj;
    QJsonObject set;  //子对象
    QJsonObject data;

    QJsonArray op;
    op.append("=");
    obj.insert("op",QJsonValue(op));

    data.insert("schid",QJsonValue(ui->lineEdit_delete_scheduleid->text().toInt()));




    obj.insert("tableName",QJsonValue("schedule"));

    obj.insert("data",QJsonValue(data));

    QJsonDocument doc(obj);

    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::DELETESCHEDULE;
    post.sprintf("POST /?%d \r\n",num);
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);

    tcpsocket.tcpSocket->write(post.toUtf8().data());


    qDebug() << "发送";
    qDebug() << "点击删除电影计划";
}

void Mainmenu::on_action_buy_triggered()
{
        ui->stackedWidget->setCurrentWidget(ui->buy_tick);
}

void Mainmenu::on_action_refund_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->return_tick);
}

void Mainmenu::on_pushButton_44_clicked()
{
    qDebug() << "确认购买";

    ui->stackedWidget->setCurrentWidget(ui->tick_id);
}






void Mainmenu::on_pushButton_47_clicked()
{
    qDebug() << "点击";
}

void Mainmenu::on_pushButton_46_clicked()
{
    QMessageBox::information(NULL, "退票", "成功退票");
}
