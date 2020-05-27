#include "login.h"
#include "ui_login.h"
#include <QPainter> //唯一一个画图类
#include "tcpclient.h"
#include <QHostAddress>
#include <QDebug>


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{

    ui->setupUi(this);
    //去掉边框
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    //设置当前窗口的所有字体

    //切换到注册窗口
    connect(ui->reg_button,&QPushButton::clicked,this,[=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->reg_page);
    });

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

void Login::on_login_button_clicked()
{
    QString ip = "127.0.0.1";
    qint16 port = 8888;
    

    //QTcpSocket tcpsocket;


    tcpClient& tcpsocket = tcpClient::get_tcpclient();
    //QTcpSocket* tcpSocket =tcpsocket.get_tcpSocket();

    //qDebug() << tcpsocket.i ;

    tcpsocket.tcpSocket->connectToHost(QHostAddress(ip),port);





}
