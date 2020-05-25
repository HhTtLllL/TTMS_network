/********************************************************************************
** Form generated from reading UI file 'title_wg.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLE_WG_H
#define UI_TITLE_WG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_title_wg
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *logo;
    QLabel *title;
    QSpacerItem *horizontalSpacer;
    QToolButton *min;
    QToolButton *close;

    void setupUi(QWidget *title_wg)
    {
        if (title_wg->objectName().isEmpty())
            title_wg->setObjectName(QStringLiteral("title_wg"));
        title_wg->resize(644, 75);
        horizontalLayout = new QHBoxLayout(title_wg);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        logo = new QLabel(title_wg);
        logo->setObjectName(QStringLiteral("logo"));

        horizontalLayout->addWidget(logo);

        title = new QLabel(title_wg);
        title->setObjectName(QStringLiteral("title"));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Mono"));
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        title->setFont(font);

        horizontalLayout->addWidget(title);

        horizontalSpacer = new QSpacerItem(446, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        min = new QToolButton(title_wg);
        min->setObjectName(QStringLiteral("min"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/login_min.png"), QSize(), QIcon::Normal, QIcon::Off);
        min->setIcon(icon);
        min->setIconSize(QSize(32, 32));
        min->setAutoRaise(true);

        horizontalLayout->addWidget(min);

        close = new QToolButton(title_wg);
        close->setObjectName(QStringLiteral("close"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/login_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon1);
        close->setIconSize(QSize(32, 32));
        close->setAutoRaise(true);

        horizontalLayout->addWidget(close);


        retranslateUi(title_wg);

        QMetaObject::connectSlotsByName(title_wg);
    } // setupUi

    void retranslateUi(QWidget *title_wg)
    {
        title_wg->setWindowTitle(QApplication::translate("title_wg", "Form", 0));
        logo->setText(QString());
        title->setText(QApplication::translate("title_wg", "\347\217\221\346\265\267\345\275\261\351\231\242", 0));
        min->setText(QApplication::translate("title_wg", "...", 0));
        close->setText(QApplication::translate("title_wg", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class title_wg: public Ui_title_wg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLE_WG_H
