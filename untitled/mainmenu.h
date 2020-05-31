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

private slots:
    void on_modify_password_triggered();

    void on_modify_information_triggered();

    void on_logout_triggered();

    void on_delete_movie_triggered();

    void on_add_movie_triggered();

    void on_modify_movie_triggered();

    void on_get_movie_triggered();

    void on_add_theater_triggered();

    void on_delete_theater_triggered();

    void on_get_theater_triggered();

    void on_modify_theater_triggered();

    void on_add_seat_triggered();

    void on_delete_seat_triggered();

    void on_modify_seat_triggered();

    void on_get_seat_triggered();

    void on_add_movie_plan_triggered();

    void on_delete_movie_plan_triggered();

    void on_modify_movie_plan_triggered();

    void on_search_movie_plan_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Mainmenu *ui;
};

#endif // MAINMENU_H
