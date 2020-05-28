#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

namespace Ui {
class Mainmenu;
}

class Mainmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mainmenu(QWidget *parent = nullptr);
    ~Mainmenu();

private:
    Ui::Mainmenu *ui;
};

#endif // MAINMENU_H
