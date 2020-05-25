#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

protected:
    //受保护的虚函数
    //是一个画图的事件 ,在窗口上画图，都必须将操作写入到paintevent 函数内部中的，这个函数不需要自己调用
    //这个是一个回调，自动被调用。只需要将刷新的操作写入这里就行
    void paintEvent(QPaintEvent * event);

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
