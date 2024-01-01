#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <QVector>
#include "mainmenu.h"
#include <QCoreApplication>
#include <QEventLoop>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);

    void delay(int sec);
    ~RegisterWindow();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::RegisterWindow *ui;
    QVector<QString> username;
    QVector<QString> passwords;
    QAudioOutput *registeroutput;
    QMediaPlayer *registersound;
};

#endif // REGISTERWINDOW_H
