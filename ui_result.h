/********************************************************************************
** Form generated from reading UI file 'result.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULT_H
#define UI_RESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Result
{
public:
    QLabel *labelpix;
    QLabel *labelfate;
    QLabel *labeltext;
    QPushButton *pushButtonMenu;

    void setupUi(QDialog *Result)
    {
        if (Result->objectName().isEmpty())
            Result->setObjectName("Result");
        Result->resize(911, 680);
        labelpix = new QLabel(Result);
        labelpix->setObjectName("labelpix");
        labelpix->setGeometry(QRect(0, -20, 911, 701));
        labelfate = new QLabel(Result);
        labelfate->setObjectName("labelfate");
        labelfate->setGeometry(QRect(260, 0, 641, 101));
        labeltext = new QLabel(Result);
        labeltext->setObjectName("labeltext");
        labeltext->setGeometry(QRect(0, 110, 911, 441));
        pushButtonMenu = new QPushButton(Result);
        pushButtonMenu->setObjectName("pushButtonMenu");
        pushButtonMenu->setGeometry(QRect(240, 550, 431, 121));

        retranslateUi(Result);

        QMetaObject::connectSlotsByName(Result);
    } // setupUi

    void retranslateUi(QDialog *Result)
    {
        Result->setWindowTitle(QCoreApplication::translate("Result", "Dialog", nullptr));
        labelpix->setText(QString());
        labelfate->setText(QCoreApplication::translate("Result", "fate", nullptr));
        labeltext->setText(QCoreApplication::translate("Result", "TextLabel", nullptr));
        pushButtonMenu->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Result: public Ui_Result {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULT_H
