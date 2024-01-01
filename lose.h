#ifndef LOSE_H
#define LOSE_H

#include <QDialog>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "mainmenu.h"

namespace Ui {
class Lose;
}

class Lose : public QDialog
{
    Q_OBJECT

public:
    explicit Lose(int *currlevel, QWidget *parent = nullptr);
    ~Lose();


private slots:
    void on_Retrybutton_clicked();
    void on_MainMenubutton_2_clicked();

private:
    Ui::Lose *ui;
    QAudioOutput *loseoutput;
    QMediaPlayer *losesound;
    int *currlevel;
};

#endif // LOSE_H
