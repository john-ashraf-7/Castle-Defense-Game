/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QLabel *errorMsg;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLineEdit *passwordLE;
    QLineEdit *usernameLE;
    QLabel *label;
    QLabel *labelMadeAcc;
    QLabel *labelpix;
    QLabel *label_3;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(830, 664);
        errorMsg = new QLabel(RegisterWindow);
        errorMsg->setObjectName("errorMsg");
        errorMsg->setGeometry(QRect(240, 400, 401, 51));
        pushButton = new QPushButton(RegisterWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 540, 301, 91));
        pushButton_2 = new QPushButton(RegisterWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(460, 540, 311, 91));
        label_2 = new QLabel(RegisterWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 280, 131, 51));
        passwordLE = new QLineEdit(RegisterWindow);
        passwordLE->setObjectName("passwordLE");
        passwordLE->setGeometry(QRect(320, 280, 411, 71));
        usernameLE = new QLineEdit(RegisterWindow);
        usernameLE->setObjectName("usernameLE");
        usernameLE->setGeometry(QRect(320, 200, 411, 71));
        label = new QLabel(RegisterWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 200, 131, 61));
        labelMadeAcc = new QLabel(RegisterWindow);
        labelMadeAcc->setObjectName("labelMadeAcc");
        labelMadeAcc->setGeometry(QRect(140, 420, 581, 91));
        labelpix = new QLabel(RegisterWindow);
        labelpix->setObjectName("labelpix");
        labelpix->setGeometry(QRect(-10, -10, 841, 681));
        label_3 = new QLabel(RegisterWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 0, 611, 171));
        labelpix->raise();
        errorMsg->raise();
        pushButton->raise();
        pushButton_2->raise();
        label_2->raise();
        passwordLE->raise();
        usernameLE->raise();
        label->raise();
        labelMadeAcc->raise();
        label_3->raise();

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        errorMsg->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; color:#aa0000;\">Invalid username or password</span></p></body></html>", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label_2->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">Password</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">Username</span></p></body></html>", nullptr));
        labelMadeAcc->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700; color:#00aa00;\">Successfully made an account.</span></p></body></html>", nullptr));
        labelpix->setText(QString());
        label_3->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:36pt; font-weight:700; font-style:italic;\">Up for the challenge?</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
