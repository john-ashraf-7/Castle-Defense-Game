#include "win.h"
#include "ui_win.h"
#include <QDebug>

int Win::levelunlocked = 1;
int Win::loseCount = 0;

Win::Win(bool validation, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Win)
{
    ui->setupUi(this);


    gameWon = validation; //if validation true, game won. if false, game lost.


    if(validation) //game won
    {
        ui->labelLosePic->setVisible(false);
        levelunlocked +=1;
        qDebug() << "Level unlocked: " << levelunlocked;
        winoutput = new QAudioOutput();
        winoutput->setVolume(1);
        winsound = new QMediaPlayer();
        winsound->setAudioOutput(winoutput);
        winsound->setSource(QUrl("qrc:/sound/Sound/win.mp3")); //after QUrl we add ::fromLocalFile(//path) if we want to add music from a local path rather than resource file
        winsound->play();

        QPixmap pix (":/images/textures/winscreen.png");
        int w = ui->labelWinPic->width();
        int h = ui->labelWinPic->height();
        ui->labelWinPic->setPixmap(pix.scaled(w,h));
        ui->labelprogress->setStyleSheet("QLabel { color : green; font-size: 30px; }");
        if(levelunlocked != 1)
        {
            ui->labelprogress->setText("Level " + QString::number(levelunlocked)+ " Unlocked!");
        }
        else
        {
            ui->labelprogress->setText("You win all Levels!");
        }
    }
    else //game lost
    {
        loseCount++;
        ui->labelWinPic->setVisible(false);
        ui->continuebutton->setVisible(false);
        loseoutput = new QAudioOutput();
        loseoutput->setVolume(20);
        losesound = new QMediaPlayer();
        losesound->setAudioOutput(loseoutput);
        losesound->setSource(QUrl("qrc:/sound/Sound/lose.mp3")); //after QUrl we add ::fromLocalFile(//path) if we want to add music from a local path rather than resource file
        losesound->play();

        QPixmap pix (":/images/textures/losescreen.png");
        int w = ui->labelLosePic->width();
        int h = ui->labelLosePic->height();
        ui->labelLosePic->setPixmap(pix.scaled(w+10,h+10));
    }

    //win window after level 5 win and level1 lose
    if(levelunlocked==6) //Game Won
    {
        ui->MainMenubutton->setVisible(false);
        ui->Retrybutton->setVisible(false);
        ui->labelprogress->setText("Congratulations!!");
    }

    /* we don't use the modulus operator to reset levelunlocked after the game is won
    because this is handeled by going to main menu on last level.
    where clicking on mainmenu at any point resets levelunlocked to 1.
    this design is better because we can then differentiate between the
    conditions for losing first level and winning final level. */
}

Win::~Win()
{
    delete ui;
}

int *Win::getLevelUnlocked()
{
    return &levelunlocked;
}

void Win::on_continuebutton_clicked()
{
    if(gameWon)
    {
        winsound->stop();
    }
    else
    {
        losesound->stop();
    }
    close();
    if(levelunlocked==6)
    {
        //reset level unlocked to 0
        //open main menu.
        Result *result = new Result(loseCount);
        levelunlocked = 1;
        loseCount = 0;
        result->show();
    }
    else
    {
        Market *market = new Market(levelunlocked, market->getTokens()+700);
        market->show();
    }
}


void Win::on_Retrybutton_clicked()
{
    if(gameWon)
    {
        levelunlocked--; // new line
        winsound->stop();
        close();
        Market *market = new Market(levelunlocked, market->getTokens()+700);
        market->show();
    }
    else
    {
        losesound->stop();
        close();
        Market *market = new Market(levelunlocked, market->getTokens()+0);
        market->show();
    }
}

void Win::on_MainMenubutton_clicked()
{
    if(gameWon)
    {
        winsound->stop();
    }
    else
    {
        losesound->stop();
    }
    levelunlocked = 1;
    loseCount=0;
    close();
    MainMenu *menu = new MainMenu;
    menu->show();
}
