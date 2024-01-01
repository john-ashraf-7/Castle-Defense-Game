/********************************************************************************
** Form generated from reading UI file 'win.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_H
#define UI_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Win
{
public:
    QLabel *labelWinPic;
    QPushButton *continuebutton;
    QLabel *labelprogress;
    QLabel *labelLosePic;
    QPushButton *MainMenubutton;
    QPushButton *Retrybutton;

    void setupUi(QDialog *Win)
    {
        if (Win->objectName().isEmpty())
            Win->setObjectName("Win");
        Win->resize(620, 430);
        labelWinPic = new QLabel(Win);
        labelWinPic->setObjectName("labelWinPic");
        labelWinPic->setGeometry(QRect(-10, -10, 631, 441));
        continuebutton = new QPushButton(Win);
        continuebutton->setObjectName("continuebutton");
        continuebutton->setGeometry(QRect(210, 350, 101, 31));
        labelprogress = new QLabel(Win);
        labelprogress->setObjectName("labelprogress");
        labelprogress->setGeometry(QRect(190, 80, 291, 51));
        labelLosePic = new QLabel(Win);
        labelLosePic->setObjectName("labelLosePic");
        labelLosePic->setGeometry(QRect(-10, 0, 631, 461));
        MainMenubutton = new QPushButton(Win);
        MainMenubutton->setObjectName("MainMenubutton");
        MainMenubutton->setGeometry(QRect(270, 390, 101, 31));
        Retrybutton = new QPushButton(Win);
        Retrybutton->setObjectName("Retrybutton");
        Retrybutton->setGeometry(QRect(340, 350, 101, 31));
        labelWinPic->raise();
        labelprogress->raise();
        labelLosePic->raise();
        continuebutton->raise();
        MainMenubutton->raise();
        Retrybutton->raise();

        retranslateUi(Win);

        QMetaObject::connectSlotsByName(Win);
    } // setupUi

    void retranslateUi(QDialog *Win)
    {
        Win->setWindowTitle(QCoreApplication::translate("Win", "Dialog", nullptr));
        labelWinPic->setText(QString());
        continuebutton->setText(QCoreApplication::translate("Win", "Continue", nullptr));
        labelprogress->setText(QString());
        labelLosePic->setText(QString());
        MainMenubutton->setText(QCoreApplication::translate("Win", "MainMenu", nullptr));
        Retrybutton->setText(QCoreApplication::translate("Win", "Retry Level", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Win: public Ui_Win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_H
