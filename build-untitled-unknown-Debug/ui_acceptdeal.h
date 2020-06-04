/********************************************************************************
** Form generated from reading UI file 'acceptdeal.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCEPTDEAL_H
#define UI_ACCEPTDEAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Acceptdeal
{
public:
    QWidget *centralwidget;
    QTableView *tableView_studio;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Acceptdeal)
    {
        if (Acceptdeal->objectName().isEmpty())
            Acceptdeal->setObjectName(QStringLiteral("Acceptdeal"));
        Acceptdeal->resize(800, 600);
        centralwidget = new QWidget(Acceptdeal);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView_studio = new QTableView(centralwidget);
        tableView_studio->setObjectName(QStringLiteral("tableView_studio"));
        tableView_studio->setGeometry(QRect(110, 70, 521, 431));
        Acceptdeal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Acceptdeal);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        Acceptdeal->setMenuBar(menubar);
        statusbar = new QStatusBar(Acceptdeal);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Acceptdeal->setStatusBar(statusbar);

        retranslateUi(Acceptdeal);

        QMetaObject::connectSlotsByName(Acceptdeal);
    } // setupUi

    void retranslateUi(QMainWindow *Acceptdeal)
    {
        Acceptdeal->setWindowTitle(QApplication::translate("Acceptdeal", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class Acceptdeal: public Ui_Acceptdeal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCEPTDEAL_H
