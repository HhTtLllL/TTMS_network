/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <title_wg.h>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    title_wg *title_widget;
    QStackedWidget *stackedWidget;
    QWidget *login_page;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox;
    QPushButton *reg_button;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *login_button;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QWidget *reg_page;
    QWidget *widget_6;
    QLabel *label_4;
    QWidget *widget_7;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QPushButton *pushButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(756, 569);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        title_widget = new title_wg(Login);
        title_widget->setObjectName(QStringLiteral("title_widget"));

        verticalLayout->addWidget(title_widget);

        stackedWidget = new QStackedWidget(Login);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        login_page = new QWidget();
        login_page->setObjectName(QStringLiteral("login_page"));
        widget = new QWidget(login_page);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 20, 651, 471));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEchoMode(QLineEdit::Normal);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBox = new QCheckBox(widget_4);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_2->addWidget(checkBox);

        reg_button = new QPushButton(widget_4);
        reg_button->setObjectName(QStringLiteral("reg_button"));

        horizontalLayout_2->addWidget(reg_button);


        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        login_button = new QPushButton(widget_5);
        login_button->setObjectName(QStringLiteral("login_button"));

        horizontalLayout_3->addWidget(login_button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(widget_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        stackedWidget->addWidget(login_page);
        reg_page = new QWidget();
        reg_page->setObjectName(QStringLiteral("reg_page"));
        widget_6 = new QWidget(reg_page);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(50, 0, 501, 561));
        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 30, 101, 41));
        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(90, 80, 271, 241));
        lineEdit_3 = new QLineEdit(widget_7);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 0, 221, 31));
        lineEdit_4 = new QLineEdit(widget_7);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(10, 40, 221, 31));
        lineEdit_5 = new QLineEdit(widget_7);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(10, 80, 221, 31));
        lineEdit_5->setEchoMode(QLineEdit::Password);
        lineEdit_6 = new QLineEdit(widget_7);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(10, 120, 221, 31));
        lineEdit_6->setEchoMode(QLineEdit::Password);
        lineEdit_7 = new QLineEdit(widget_7);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(10, 160, 221, 31));
        lineEdit_8 = new QLineEdit(widget_7);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(10, 200, 221, 31));
        pushButton = new QPushButton(widget_6);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 350, 93, 28));
        stackedWidget->addWidget(reg_page);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(Login);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", 0));
        label->setText(QApplication::translate("Login", "\347\224\250\346\210\267\347\231\273\345\275\225", 0));
        label_2->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", 0));
        label_3->setText(QApplication::translate("Login", "\345\257\206\347\240\201", 0));
        checkBox->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
        reg_button->setText(QApplication::translate("Login", "\346\263\250\345\206\214", 0));
        login_button->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
        label_4->setText(QApplication::translate("Login", "\346\263\250\345\206\214", 0));
        lineEdit_3->setPlaceholderText(QApplication::translate("Login", "\350\276\223\345\205\245\345\220\215\347\247\260", 0));
        lineEdit_4->setPlaceholderText(QApplication::translate("Login", "\347\224\265\345\255\220\351\202\256\347\256\261", 0));
        lineEdit_5->setPlaceholderText(QApplication::translate("Login", "\345\257\206\347\240\201", 0));
        lineEdit_6->setPlaceholderText(QApplication::translate("Login", "\347\241\256\350\256\244\345\257\206\347\240\201", 0));
        lineEdit_7->setPlaceholderText(QApplication::translate("Login", "\347\224\265\350\257\235", 0));
        lineEdit_8->setPlaceholderText(QApplication::translate("Login", "\344\275\217\345\235\200", 0));
        pushButton->setText(QApplication::translate("Login", "\346\263\250\345\206\214\345\256\214\346\210\220", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
