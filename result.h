#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QGraphicsDropShadowEffect>
#include "mainmenu.h"

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(int loseCount, QWidget *parent = nullptr);
    ~Result();

private slots:
    void on_pushButtonMenu_clicked();

private:
    Ui::Result *ui;
    int loseCount;
    QAudioOutput *happyoutput;
    QMediaPlayer *happysound;
    QAudioOutput *sadoutput;
    QMediaPlayer *sadsound;
};

#endif // RESULT_H
