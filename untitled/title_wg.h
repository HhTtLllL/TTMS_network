#ifndef TITLE_WG_H
#define TITLE_WG_H

#include <QWidget>

namespace Ui {
class title_wg;
}

class title_wg : public QWidget
{
    Q_OBJECT

public:
    explicit title_wg(QWidget *parent = nullptr);
    ~title_wg();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent * event);
private:
    Ui::title_wg *ui;
    QPoint m_pt; //差值 : 鼠标当前位置  - 窗口左上角点
    QWidget* m_parent;
};

#endif // TITLE_WG_H
