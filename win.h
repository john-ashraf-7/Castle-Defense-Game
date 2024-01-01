#ifndef WIN_H
#define WIN_H

#include <QDialog>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsView>
#include <QPixmap>
#include "market.h"
#include "mainmenu.h"
#include "result.h"

namespace Ui {
class Win;
}

class Win : public QDialog
{
    Q_OBJECT

public:
    explicit Win(bool validation, QWidget *parent = nullptr);
    ~Win();
    int *getLevelUnlocked();

private slots:
    void on_continuebutton_clicked();

    void on_Retrybutton_clicked();

    void on_MainMenubutton_clicked();

private:
    Ui::Win *ui;
    QAudioOutput *winoutput;
    QMediaPlayer *winsound;
    QAudioOutput *loseoutput;
    QMediaPlayer *losesound;
    bool gameWon;
    static int levelunlocked;
    static int loseCount;
};

#endif // WIN_H
