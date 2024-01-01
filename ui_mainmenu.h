/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QLabel *labelpix;
    QPushButton *pushButtonstart;
    QPushButton *pushButtonmanual;
    QPushButton *pushButtoncredits;
    QPushButton *pushButtonexit;

    void setupUi(QDialog *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(822, 660);
        labelpix = new QLabel(MainMenu);
        labelpix->setObjectName("labelpix");
        labelpix->setGeometry(QRect(0, 0, 831, 661));
        pushButtonstart = new QPushButton(MainMenu);
        pushButtonstart->setObjectName("pushButtonstart");
        pushButtonstart->setGeometry(QRect(250, 90, 311, 101));
        pushButtonmanual = new QPushButton(MainMenu);
        pushButtonmanual->setObjectName("pushButtonmanual");
        pushButtonmanual->setGeometry(QRect(250, 240, 311, 101));
        pushButtoncredits = new QPushButton(MainMenu);
        pushButtoncredits->setObjectName("pushButtoncredits");
        pushButtoncredits->setGeometry(QRect(250, 400, 311, 101));
        pushButtonexit = new QPushButton(MainMenu);
        pushButtonexit->setObjectName("pushButtonexit");
        pushButtonexit->setGeometry(QRect(310, 560, 191, 61));

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QDialog *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "Dialog", nullptr));
        labelpix->setText(QString());
        pushButtonstart->setText(QString());
        pushButtonmanual->setText(QString());
        pushButtoncredits->setText(QString());
        pushButtonexit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
