#ifndef MARKET_H
#define MARKET_H
#include "levels.h"
#include <QMainWindow>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QGraphicsDropShadowEffect>


QT_BEGIN_NAMESPACE
namespace Ui { class Market; }
QT_END_NAMESPACE

class Market : public QMainWindow
{
    Q_OBJECT

public:
    Market(int currlevel, int tokens, QWidget *parent = nullptr);
    ~Market();
void MarketReset();
    void delay(int sec);
    static int getTokens();
    static void setTokens(int newTokens);
    void checkTimer();
private slots:
    void on_pushButtonContinue_clicked();

    void on_pushButtonBuy1_clicked();

    void on_pushButtonBuy2_clicked();

    void on_pushButtonBuy3_clicked();

    void on_pushButtonBuy4_clicked();

    void on_pushButtonBuy5_clicked();

    void on_pushButtonBuy6_clicked();

    void on_pushButtonBuy7_clicked();

    void on_pushButtonBuy8_clicked();

private:
    Ui::Market *ui;

    //sound
    QAudioOutput *marketthemeoutput;
    QMediaPlayer *markettheme;
    QMediaPlayer *buysuccessful;
    QAudioOutput *buysuccessfuloutput;
    QMediaPlayer *buyfailed;
    QAudioOutput *buyfailedoutput;
    QTimer moneyTimer;

    //info holders
    static int boughtHealth;
    static QString boughtFence;
    static int boughtSpeed;
    static int boughtDamage;
    static QString boughtWeapon;
    static QString boughtBullet;
    static int boughtRecoil;
    static QString bulletSound;

    //current level receiver from win.h and money handler
    int currlevel;
    static int tokens;
};
#endif // MARKET_H
