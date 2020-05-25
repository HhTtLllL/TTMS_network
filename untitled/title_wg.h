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

private:
    Ui::title_wg *ui;
};

#endif // TITLE_WG_H
