#include "title_wg.h"
#include "ui_title_wg.h"

title_wg::title_wg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::title_wg)
{
    ui->setupUi(this);
    //logo 图片
    ui->logo->setPixmap(QPixmap(":/Images/Live2D.png").scaled(40,40));
}

title_wg::~title_wg()
{
    delete ui;
}
