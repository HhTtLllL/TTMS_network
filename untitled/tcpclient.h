#ifndef TCPCLIENT_H
#define TCPCLIENT_H

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

/*    static QTcpSocket* get_tcpSocket()
    {
        return tcpSocket;
    }
*/
private:
   // QTcpSocket * tcpSocket;

    tcpClient()
    {
        tcpSocket = new QTcpSocket();
        qDebug() << "创建";
    }

};

#endif // TCPCLIENT_H
