#ifndef TCPCLIENT_H
#define TCPCLIENT_H

//用来保存 唯一一个 tcpsocket 实例
#include <QTcpSocket>
#include <QDebug>

class tcpClient
{
public:
    ~tcpClient()
    {
        delete tcpSocket;
    }
    QTcpSocket * tcpSocket;

    tcpClient(const tcpClient&)=delete;
    tcpClient& operator=(const tcpClient&)=delete;
    static tcpClient& get_tcpclient()
    {
        static tcpClient tcpclient;

        return tcpclient;
    }
private:
    tcpClient()
    {
        tcpSocket = new QTcpSocket();
        qDebug() << "创建";
    }

};

#endif // TCPCLIENT_H
