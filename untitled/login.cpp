#include "login.h"
#include "ui_login.h"
#include <QPainter> //唯一一个画图类
#include "tcpclient.h"
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QLineEdit>
#include "common.h"
#include "accept.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //去掉边框
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    //设置当前窗口的所有字体

    //title_wg  信号的处理
    connect(ui->title_widget,&title_wg::closeWindow,[=]()
    {
        //判断当前stackedWidget显示的页面
        if(ui->stackedWidget->currentWidget() == ui->reg_page)
        {
            //切换到登录
            ui->stackedWidget->setCurrentWidget(ui->login_page);
            //清空数据

        }
        else {

            this->close();
        }

    });


}

Login::~Login()
{
    delete ui;
}

void Login::paintEvent(QPaintEvent *event)
{
    //画图操作，给login 画一个背景图
    QPainter p(this); //将p的操作 画到this 上面
    QPixmap pixmap(":/Images/login_bk.jpg");
    p.drawPixmap(0,0,this->width(),this->height(),pixmap);
}


//登录
void Login::on_login_button_clicked()
{
    QString ip = "121.89.171.193";
    qint16 port = 4507;

//121.89.171.193
    //QTcpSocket tcpsocket;


    tcpClient& tcpsocket = tcpClient::get_tcpclient();
    //QTcpSocket* tcpSocket =tcpsocket.get_tcpSocket();

    //qDebug() << tcpsocket.i ;

    tcpsocket.tcpSocket->connectToHost(QHostAddress(ip),port);


    //判断内容是否为空内容是否为空

    QJsonObject obj;
    QJsonObject sub;

    QJsonArray what;
    what.append("*");

    obj.insert("what",QJsonValue(what));

    QJsonArray op;
    op.append("=");
    op.append("=");

    obj.insert("op",QJsonValue(op));

    obj.insert("tableName",QJsonValue("user"));

    sub.insert("uid",QJsonValue(ui->lineEdit_account->text()));
    QString pass = "'";
    pass += ui->lineEdit_password->text();
    pass += "'";
    sub.insert("passWord",QJsonValue(pass));



    obj.insert("data",QJsonValue(sub));

    QJsonDocument doc(obj);
    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::QUERYUSER;
    post.sprintf("POST /?%d \r\n",num);
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(json);
    qDebug() << post;

    tcpsocket.tcpSocket->write(post.toUtf8().data());

}

//切换到注册窗口
void Login::on_reg_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->reg_page);
}

//提交注册信息
void Login::on_pushButton_clicked()
{
    QString ip = "121.89.171.193";
    qint16 port = 4507;

    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    tcpsocket.tcpSocket->connectToHost(QHostAddress(ip),port);

    QJsonObject obj;
    QJsonObject sub;
    QJsonArray data;



    obj.insert("tableName",QJsonValue("user"));


    sub.insert("uid",QJsonValue("NULL"));
    sub.insert("userName",QJsonValue(ui->lineEdit_username->text()));
    sub.insert("passWord",QJsonValue(ui->lineEdit_password_reg->text()));
    sub.insert("sex",QJsonValue(ui->lineEdit_sex->text()));
    sub.insert("phoneNumber",QJsonValue(ui->lineEdit_phonenumber->text()));
    sub.insert("mibao",QJsonValue(ui->lineEdit_mibao->text()));
    sub.insert("power",QJsonValue(ui->lineEdit_power->text().toInt()));


    data.append(sub);

    obj.insert("data",QJsonValue(data));


    QJsonDocument doc(obj);
    QString json = doc.toJson(QJsonDocument::Compact);

    int size = json.length();

    QString post;
    int num = accept::INSERTUSER;
    post.sprintf("POST /?%d \r\n",num);
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(doc.toJson());
       qDebug() << post;
    tcpsocket.tcpSocket->write(post.toUtf8().data());

}
