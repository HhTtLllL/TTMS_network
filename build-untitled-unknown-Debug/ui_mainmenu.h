/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mainmenu
{
public:
    QAction *modify_password;
    QAction *modify_information;
    QAction *logout;
    QAction *delete_movie;
    QAction *add_movie;
    QAction *modify_movie;
    QAction *get_movie;
    QAction *add_theater;
    QAction *delete_theater;
    QAction *get_theater;
    QAction *modify_theater;
    QAction *add_seat;
    QAction *delete_seat;
    QAction *modify_seat;
    QAction *get_seat;
    QAction *add_movie_plan;
    QAction *delete_movie_plan;
    QAction *modify_movie_plan;
    QAction *search_movie_plan;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *movie_operation;
    QMenu *theater_operation;
    QMenu *seat_operation;
    QMenu *movie_plan_opeartion;
    QMenu *system_set;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Mainmenu)
    {
        if (Mainmenu->objectName().isEmpty())
            Mainmenu->setObjectName(QStringLiteral("Mainmenu"));
        Mainmenu->resize(800, 600);
        modify_password = new QAction(Mainmenu);
        modify_password->setObjectName(QStringLiteral("modify_password"));
        modify_information = new QAction(Mainmenu);
        modify_information->setObjectName(QStringLiteral("modify_information"));
        logout = new QAction(Mainmenu);
        logout->setObjectName(QStringLiteral("logout"));
        delete_movie = new QAction(Mainmenu);
        delete_movie->setObjectName(QStringLiteral("delete_movie"));
        add_movie = new QAction(Mainmenu);
        add_movie->setObjectName(QStringLiteral("add_movie"));
        modify_movie = new QAction(Mainmenu);
        modify_movie->setObjectName(QStringLiteral("modify_movie"));
        get_movie = new QAction(Mainmenu);
        get_movie->setObjectName(QStringLiteral("get_movie"));
        add_theater = new QAction(Mainmenu);
        add_theater->setObjectName(QStringLiteral("add_theater"));
        delete_theater = new QAction(Mainmenu);
        delete_theater->setObjectName(QStringLiteral("delete_theater"));
        get_theater = new QAction(Mainmenu);
        get_theater->setObjectName(QStringLiteral("get_theater"));
        modify_theater = new QAction(Mainmenu);
        modify_theater->setObjectName(QStringLiteral("modify_theater"));
        add_seat = new QAction(Mainmenu);
        add_seat->setObjectName(QStringLiteral("add_seat"));
        delete_seat = new QAction(Mainmenu);
        delete_seat->setObjectName(QStringLiteral("delete_seat"));
        modify_seat = new QAction(Mainmenu);
        modify_seat->setObjectName(QStringLiteral("modify_seat"));
        get_seat = new QAction(Mainmenu);
        get_seat->setObjectName(QStringLiteral("get_seat"));
        add_movie_plan = new QAction(Mainmenu);
        add_movie_plan->setObjectName(QStringLiteral("add_movie_plan"));
        delete_movie_plan = new QAction(Mainmenu);
        delete_movie_plan->setObjectName(QStringLiteral("delete_movie_plan"));
        modify_movie_plan = new QAction(Mainmenu);
        modify_movie_plan->setObjectName(QStringLiteral("modify_movie_plan"));
        search_movie_plan = new QAction(Mainmenu);
        search_movie_plan->setObjectName(QStringLiteral("search_movie_plan"));
        centralwidget = new QWidget(Mainmenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Mainmenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Mainmenu);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        movie_operation = new QMenu(menu);
        movie_operation->setObjectName(QStringLiteral("movie_operation"));
        theater_operation = new QMenu(menu);
        theater_operation->setObjectName(QStringLiteral("theater_operation"));
        seat_operation = new QMenu(menu);
        seat_operation->setObjectName(QStringLiteral("seat_operation"));
        movie_plan_opeartion = new QMenu(menu);
        movie_plan_opeartion->setObjectName(QStringLiteral("movie_plan_opeartion"));
        system_set = new QMenu(menubar);
        system_set->setObjectName(QStringLiteral("system_set"));
        Mainmenu->setMenuBar(menubar);
        statusbar = new QStatusBar(Mainmenu);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Mainmenu->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(system_set->menuAction());
        menu->addAction(movie_operation->menuAction());
        menu->addSeparator();
        menu->addAction(theater_operation->menuAction());
        menu->addAction(seat_operation->menuAction());
        menu->addAction(movie_plan_opeartion->menuAction());
        movie_operation->addAction(delete_movie);
        movie_operation->addAction(add_movie);
        movie_operation->addAction(modify_movie);
        movie_operation->addAction(get_movie);
        theater_operation->addAction(add_theater);
        theater_operation->addAction(delete_theater);
        theater_operation->addAction(get_theater);
        theater_operation->addAction(modify_theater);
        seat_operation->addAction(add_seat);
        seat_operation->addAction(delete_seat);
        seat_operation->addAction(modify_seat);
        seat_operation->addAction(get_seat);
        movie_plan_opeartion->addAction(add_movie_plan);
        movie_plan_opeartion->addAction(delete_movie_plan);
        movie_plan_opeartion->addAction(modify_movie_plan);
        movie_plan_opeartion->addAction(search_movie_plan);
        system_set->addAction(modify_password);
        system_set->addAction(modify_information);
        system_set->addAction(logout);

        retranslateUi(Mainmenu);

        QMetaObject::connectSlotsByName(Mainmenu);
    } // setupUi

    void retranslateUi(QMainWindow *Mainmenu)
    {
        Mainmenu->setWindowTitle(QApplication::translate("Mainmenu", "MainWindow", 0));
        modify_password->setText(QApplication::translate("Mainmenu", "\344\277\256\346\224\271\345\257\206\347\240\201", 0));
        modify_information->setText(QApplication::translate("Mainmenu", "\344\277\256\346\224\271\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        logout->setText(QApplication::translate("Mainmenu", "\346\263\250\351\224\200", 0));
        delete_movie->setText(QApplication::translate("Mainmenu", "\345\210\240\351\231\244\347\224\265\345\275\261", 0));
        add_movie->setText(QApplication::translate("Mainmenu", "\346\267\273\345\212\240\347\224\265\345\275\261", 0));
        modify_movie->setText(QApplication::translate("Mainmenu", "\344\277\256\346\224\271\347\224\265\345\275\261\344\277\241\346\201\257", 0));
        get_movie->setText(QApplication::translate("Mainmenu", "\350\216\267\345\217\226\346\211\200\346\234\211\347\224\265\345\275\261", 0));
        add_theater->setText(QApplication::translate("Mainmenu", "\345\242\236\345\212\240\345\275\261\345\216\205", 0));
        delete_theater->setText(QApplication::translate("Mainmenu", "\345\210\240\351\231\244\345\275\261\345\216\205", 0));
        get_theater->setText(QApplication::translate("Mainmenu", "\350\216\267\345\217\226\346\211\200\346\234\211\345\275\261\345\216\205", 0));
        modify_theater->setText(QApplication::translate("Mainmenu", "\344\277\256\346\224\271\345\275\261\345\216\205", 0));
        add_seat->setText(QApplication::translate("Mainmenu", "\345\242\236\345\212\240\345\272\247\344\275\215", 0));
        delete_seat->setText(QApplication::translate("Mainmenu", "\345\210\240\351\231\244\345\272\247\344\275\215", 0));
        modify_seat->setText(QApplication::translate("Mainmenu", "\344\277\256\346\224\271\345\272\247\344\275\215", 0));
        get_seat->setText(QApplication::translate("Mainmenu", "\350\216\267\345\217\226\346\237\220\345\275\261\345\216\205\346\211\200\346\234\211\345\272\247\344\275\215", 0));
        add_movie_plan->setText(QApplication::translate("Mainmenu", "\345\242\236\345\212\240\347\224\265\345\275\261\350\256\241\345\210\222", 0));
        delete_movie_plan->setText(QApplication::translate("Mainmenu", "\345\210\240\351\231\244\347\224\265\345\275\261\350\256\241\345\210\222", 0));
        modify_movie_plan->setText(QApplication::translate("Mainmenu", "\344\277\256\346\224\271\347\224\265\345\275\261\350\256\241\345\210\222", 0));
        search_movie_plan->setText(QApplication::translate("Mainmenu", "\346\237\245\350\257\242\347\224\265\345\275\261\350\256\241\345\210\222", 0));
        menu->setTitle(QApplication::translate("Mainmenu", "\350\217\234\345\215\225", 0));
        movie_operation->setTitle(QApplication::translate("Mainmenu", "\347\224\265\345\275\261\346\223\215\344\275\234", 0));
        theater_operation->setTitle(QApplication::translate("Mainmenu", "\345\275\261\345\216\205\346\223\215\344\275\234", 0));
        seat_operation->setTitle(QApplication::translate("Mainmenu", "\345\272\247\344\275\215\346\223\215\344\275\234", 0));
        movie_plan_opeartion->setTitle(QApplication::translate("Mainmenu", "\347\224\265\345\275\261\350\256\241\345\210\222\346\223\215\344\275\234", 0));
        system_set->setTitle(QApplication::translate("Mainmenu", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class Mainmenu: public Ui_Mainmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
