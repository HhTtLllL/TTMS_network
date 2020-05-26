#include "title_wg.h"
#include "ui_title_wg.h"
#include <QMouseEvent>

title_wg::title_wg(QWidget *parent) : //parent 为这个窗口的父窗口
    QWidget(parent),
    ui(new Ui::title_wg)
{
    ui->setupUi(this);
    //logo 图片
    ui->logo->setPixmap(QPixmap(":/Images/Live2D.png").scaled(40,40));
    m_parent = parent;  //因为这个parent 只能在构造函数中获取,所以在这里将父指针保存起来

    //按钮功能实现
    connect(ui->min,&QToolButton::clicked,this,[=]()
    {
        m_parent->showMinimized();
    });

    connect(ui->close,&QToolButton::clicked,this,[=]()
    {
        //发送自定义信号,发送给父窗口
        emit closeWindow();
    });

}

title_wg::~title_wg()
{
    delete ui;
}

void title_wg::mouseMoveEvent(QMouseEvent *event)
{
    //只允许左键拖动
    //buttons  为持续点击，
    //buttons 为 短暂点击
    if(event->buttons() & Qt::LeftButton)
    {
        //窗口跟着鼠标移动
        m_parent->move(event->globalPos() - m_pt);
    }
}

void title_wg::mousePressEvent(QMouseEvent *event)
{
    //如果鼠标左键按下
    if(event->button() == Qt::LeftButton)
    {
        //求差值 = 鼠标当前位置 - 窗口左上角点
        m_pt = event->globalPos() - m_parent->geometry().topLeft();
    }
}
