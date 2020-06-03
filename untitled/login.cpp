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
    sub.insert("passWord",QJsonValue(ui->lineEdit_password->text()));


    obj.insert("data",QJsonValue(sub));
    QJsonDocument doc(obj);

    int size = sizeof(obj);
    qDebug() << size;

    QString post;
    post.append("POST / 18 \r\n");
    post.append(Content_Length);
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(doc.toJson());

    tcpsocket.tcpSocket->write(post.toUtf8().data());

   /* connect(tcpsocket.tcpSocket,&QTcpSocket::readyRead,[=]()
    {
        qDebug() << "接受_1";

    });*/



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
    qint16 port = 8888;

    tcpClient& tcpsocket = tcpClient::get_tcpclient();

    tcpsocket.tcpSocket->connectToHost(QHostAddress(ip),port);

    QJsonObject obj;
    QJsonObject sub;

    obj.insert("tableName",QJsonValue("user"));
    sub.insert("userName",QJsonValue("NULL"));
    sub.insert("passWord",QJsonValue("NULL"));
    sub.insert("sex",QJsonValue("NULL"));
    sub.insert("phoneNumber",QJsonValue("NULL"));
    sub.insert("mibao",QJsonValue("NULL"));
    sub.insert("power",QJsonValue("NULL"));

    obj.insert("data",QJsonValue(sub));

    QJsonDocument doc(obj);

    int size = sizeof(obj);
    qDebug() << size;

    QString post;
    post.append("POST / 2 \r\n");
    post.append("Content-Length: ");
    post.append(QString::number(size));
    post.append("\r\n\r\n");

    post.append(doc.toJson());

    tcpsocket.tcpSocket->write(post.toUtf8().data());

}
