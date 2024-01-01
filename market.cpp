#include "market.h"
#include "ui_market.h"
#include <QCoreApplication>
#include <QEventLoop>

//market static variable is initialized from the mainmenu because each time the menu starts, money resets to zero.
int Market::tokens=250;
//if nothing bought from the market on first level. we assign these items.
//if something is bought it overwrites them and continues alongside the entire game.
QString Market::boughtWeapon=":/images/textures/weapon1.png";
QString Market::boughtBullet=":/images/textures/bullet1.png";
QString Market::bulletSound="qrc:/sound/Sound/hit5.mp3";
QString Market::boughtFence=":/images/textures/fence1.png";
int Market::boughtSpeed=2;
int Market::boughtRecoil=600;
int Market::boughtHealth=500;
int Market::boughtDamage=50;

Market::Market(int currlevel, int tokens, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Market)
{
    ui->setupUi(this);

    //initializations
    this -> currlevel = currlevel;
    this -> tokens = tokens;


    //sound
    marketthemeoutput = new QAudioOutput();
    marketthemeoutput->setVolume(50);
    markettheme = new QMediaPlayer();
    markettheme->setAudioOutput(marketthemeoutput);
    markettheme->setSource(QUrl("qrc:/sound/Sound/market.mp3")); //after QUrl we add ::fromLocalFile(//path) if we want to add music from a local path rather than resource file
    markettheme->play();




    //Pictures in Market.
    QPixmap pix(":/images/textures/market.jpg");
    ui->labelpix->setPixmap(pix.scaled(ui->labelpix->width(),ui->labelpix->height()));
    QPixmap pix1(":/images/textures/weapon2.png");
    ui->labelpix1->setPixmap(pix1.scaled(ui->labelpix1->width(),ui->labelpix1->height()));
    QPixmap pix2(":/images/textures/weapon3.png");
    ui->labelpix2->setPixmap(pix2.scaled(ui->labelpix2->width(),ui->labelpix2->height()));
    QPixmap pix3(":/images/textures/weapon4.png");
    ui->labelpix3->setPixmap(pix3.scaled(ui->labelpix3->width(),ui->labelpix3->height()));
    QPixmap pix4(":/images/textures/weapon5.png");
    ui->labelpix4->setPixmap(pix4.scaled(ui->labelpix4->width(),ui->labelpix4->height()));
    QPixmap pix5(":/images/textures/fence2.png");
    ui->labelpix5->setPixmap(pix5.scaled(ui->labelpix5->width(),ui->labelpix5->height()));
    QPixmap pix6(":/images/textures/fence3.png");
    ui->labelpix6->setPixmap(pix6.scaled(ui->labelpix6->width(),ui->labelpix6->height()));
    QPixmap pix7(":/images/textures/fence4.png");
    ui->labelpix7->setPixmap(pix7.scaled(ui->labelpix7->width(),ui->labelpix7->height()));
    QPixmap pix8(":/images/textures/fence5.png");
    ui->labelpix8->setPixmap(pix8.scaled(ui->labelpix8->width(),ui->labelpix8->height()));



    //PushButtons Design
    ui->pushButtonBuy1->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    ui->pushButtonBuy2->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    ui->pushButtonBuy3->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    ui->pushButtonBuy4->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    ui->pushButtonBuy5->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    ui->pushButtonBuy6->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    ui->pushButtonBuy7->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    ui->pushButtonBuy8->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    ui->pushButtonContinue->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(20);
    shadow->setColor(QColor(0, 0, 0, 180));
    shadow->setOffset(0, 0);
    ui->pushButtonBuy1->setGraphicsEffect(shadow);
    ui->pushButtonBuy2->setGraphicsEffect(shadow);
    ui->pushButtonBuy3->setGraphicsEffect(shadow);
    ui->pushButtonBuy4->setGraphicsEffect(shadow);
    ui->pushButtonBuy5->setGraphicsEffect(shadow);
    ui->pushButtonBuy6->setGraphicsEffect(shadow);
    ui->pushButtonBuy7->setGraphicsEffect(shadow);
    ui->pushButtonBuy8->setGraphicsEffect(shadow);
    ui->pushButtonContinue->setGraphicsEffect(shadow);

    //Labels
    ui->labelError->setText("Error");

    QFont bigfont;
    bigfont.setFamily("Arial");
    bigfont.setPointSize(25);
    bigfont.setWeight(QFont::Bold);

    QFont smallfont;
    smallfont.setFamily("Arial");
    smallfont.setPointSize(17);
    smallfont.setWeight(QFont::Bold);


    //Design


    //FenceHealth
    ui->labelHealth5->setFont(smallfont);
    ui->labelHealth5->setStyleSheet("QLabel { color : green; }");
    ui->labelHealth6->setFont(smallfont);
    ui->labelHealth6->setStyleSheet("QLabel { color : green; }");
    ui->labelHealth7->setFont(smallfont);
    ui->labelHealth7->setStyleSheet("QLabel { color : green; }");
    ui->labelHealth8->setFont(smallfont);
    ui->labelHealth8->setStyleSheet("QLabel { color : green; }");

    //BulletDamage
    ui->labelDamage1->setFont(smallfont);
    ui->labelDamage1->setStyleSheet("QLabel { color : red; }");
    ui->labelDamage2->setFont(smallfont);
    ui->labelDamage2->setStyleSheet("QLabel { color : red; }");
    ui->labelDamage3->setFont(smallfont);
    ui->labelDamage3->setStyleSheet("QLabel { color : red; }");
    ui->labelDamage4->setFont(smallfont);
    ui->labelDamage4->setStyleSheet("QLabel { color : red; }");

    //BulletSpeed
    ui->labelSpeed1->setFont(smallfont);
    ui->labelSpeed1->setStyleSheet("QLabel { color : white; }");
    ui->labelSpeed2->setFont(smallfont);
    ui->labelSpeed2->setStyleSheet("QLabel { color : white; }");
    ui->labelSpeed3->setFont(smallfont);
    ui->labelSpeed3->setStyleSheet("QLabel { color : white; }");
    ui->labelSpeed4->setFont(smallfont);
    ui->labelSpeed4->setStyleSheet("QLabel { color : white; }");

    //WeaponRecoil
    ui->labelRecoil1->setFont(smallfont);
    ui->labelRecoil1->setStyleSheet("QLabel { color : cyan; }");
    ui->labelRecoil2->setFont(smallfont);
    ui->labelRecoil2->setStyleSheet("QLabel { color : cyan; }");
    ui->labelRecoil3->setFont(smallfont);
    ui->labelRecoil3->setStyleSheet("QLabel { color : cyan; }");
    ui->labelRecoil4->setFont(smallfont);
    ui->labelRecoil4->setStyleSheet("QLabel { color : cyan; }");

    //Cost
    ui->labelCost1->setFont(smallfont);
    ui->labelCost1->setStyleSheet("QLabel { color : orange; }");
    ui->labelCost2->setFont(smallfont);
    ui->labelCost2->setStyleSheet("QLabel { color : orange; }");
    ui->labelCost3->setFont(smallfont);
    ui->labelCost3->setStyleSheet("QLabel { color : orange; }");
    ui->labelCost4->setFont(smallfont);
    ui->labelCost4->setStyleSheet("QLabel { color : orange; }");
    ui->labelCost5->setFont(smallfont);
    ui->labelCost5->setStyleSheet("QLabel { color : orange; }");
    ui->labelCost6->setFont(smallfont);
    ui->labelCost6->setStyleSheet("QLabel { color : orange; }");
    ui->labelCost7->setFont(smallfont);
    ui->labelCost7->setStyleSheet("QLabel { color : orange; }");
    ui->labelCost8->setFont(smallfont);
    ui->labelCost8->setStyleSheet("QLabel { color : orange; }");

    //Main Labels
    ui->labelError->setFont(bigfont);
    ui->labelSuccessful->setFont(bigfont);
    ui->labelTokens->setFont(bigfont);
    ui->labelTokens->setStyleSheet("QLabel { color : yellow; }");
    ui->labelError->setStyleSheet("QLabel { color : red; }");
    ui->labelSuccessful->setStyleSheet("QLabel { color : green; }");
    ui->labelError->setVisible(false);
    ui->labelSuccessful->setVisible(false);

    QObject::connect(&moneyTimer,&QTimer::timeout,this,&Market::checkTimer); //checks for collision every millisecond.
    moneyTimer.start(1);

}

void Market::MarketReset() //change all initial values from here
{
    tokens=250;
    boughtWeapon=":/images/textures/weapon1.png";
    boughtBullet=":/images/textures/bullet1.png";
    bulletSound="qrc:/sound/Sound/hit1.mp3";
    boughtFence=":/images/textures/fence1.png";
    boughtSpeed=2;
    boughtRecoil=900;
    boughtHealth=500;
    boughtDamage=50;
}
Market::~Market()
{
    delete ui;
}

void Market::delay(int sec)
{
    QTime dieTime=  QTime::currentTime().addSecs(sec);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

//after the user clicks the continue button the market and the clan will display.
void Market::on_pushButtonContinue_clicked()
{
    markettheme->stop();
    hide();
    if (currlevel == 1) {
        Levels *level1 = new Levels(boughtHealth,boughtFence, 2000, ":/images/textures/castle1.png", "qrc:/sound/Sound/theme1.mp3", ":/textfiles/TextFiles/level1.txt", ":/images/textures/grass.jpg",boughtWeapon,bulletSound, boughtRecoil, boughtDamage, boughtSpeed, boughtBullet, 3000, 100, 100, ":/images/textures/vikingwalkleft1.png", ":/images/textures/vikingwalkleft2.png", ":/images/textures/vikingwalkleft3.png", ":/images/textures/vikingwalkleft4.png", ":/images/textures/vikingwalkleft5.png", ":/images/textures/vikingwalkright1.png", ":/images/textures/vikingwalkright2.png", ":/images/textures/vikingwalkright3.png", ":/images/textures/vikingwalkright4.png", ":/images/textures/vikingwalkright5.png",":/images/textures/vikingattackright1.png",":/images/textures/vikingattackright2.png",":/images/textures/vikingattackright3.png",":/images/textures/vikingattackright4.png",":/images/textures/vikingattackright5.png",":/images/textures/vikingattackleft1.png",":/images/textures/vikingattackleft2.png",":/images/textures/vikingattackleft3.png",":/images/textures/vikingattackleft4.png",":/images/textures/vikingattackleft5.png",500, "qrc:/sound/Sound/ah1.mp3", 1*15);
    } else if (currlevel == 2) {
        Levels *level2 = new Levels(boughtHealth,boughtFence, 2000, ":/images/textures/castle2.png", "qrc:/sound/Sound/theme2.mp3", ":/textfiles/TextFiles/level2.txt", ":/images/textures/dust.jpg",boughtWeapon,bulletSound,boughtRecoil, boughtDamage, boughtSpeed, boughtBullet, 2500, 150, 150, ":/images/textures/skeletonwalkleft1.png", ":/images/textures/skeletonwalkleft2.png", ":/images/textures/skeletonwalkleft3.png", ":/images/textures/skeletonwalkleft4.png", ":/images/textures/skeletonwalkleft5.png", ":/images/textures/skeletonwalkright1.png", ":/images/textures/skeletonwalkright2.png", ":/images/textures/skeletonwalkright3.png", ":/images/textures/skeletonwalkright4.png", ":/images/textures/skeletonwalkright5.png",":/images/textures/skeletonattackright1.png",":/images/textures/skeletonattackright2.png",":/images/textures/skeletonattackright3.png",":/images/textures/skeletonattackright4.png",":/images/textures/skeletonattackright5.png",":/images/textures/skeletonattackleft1.png",":/images/textures/skeletonattackleft2.png",":/images/textures/skeletonattackleft3.png",":/images/textures/skeletonattackleft4.png",":/images/textures/skeletonattackleft5.png", 400, "qrc:/sound/Sound/ah2.mp3", 1*20);
    } else if (currlevel == 3) {
        Levels *level3 = new Levels(boughtHealth, boughtFence, 2500, ":/images/textures/castle3.png", "qrc:/sound/Sound/theme3.mp3", ":/textfiles/TextFiles/level3.txt", ":/images/textures/clay.jpg", boughtWeapon, bulletSound, boughtRecoil, boughtDamage, boughtSpeed, boughtBullet, 2300, 200, 200, ":/images/textures/wizwalkleft1.png", ":/images/textures/wizwalkleft2.png", ":/images/textures/wizwalkleft3.png", ":/images/textures/wizwalkleft4.png", ":/images/textures/wizwalkleft5.png", ":/images/textures/wizwalkright1.png", ":/images/textures/wizwalkright2.png", ":/images/textures/wizwalkright3.png", ":/images/textures/wizwalkright4.png", ":/images/textures/wizwalkright5.png",":/images/textures/wizattackright1.png",":/images/textures/wizattackright2.png",":/images/textures/wizattackright3.png",":/images/textures/wizattackright4.png",":/images/textures/wizattackright5.png",":/images/textures/wizattackleft1.png",":/images/textures/wizattackleft2.png",":/images/textures/wizattackleft3.png",":/images/textures/wizattackleft4.png",":/images/textures/wizattackleft5.png", 380, "qrc:/sound/Sound/ah3.mp3", 1*25);
    } else if (currlevel == 4) {
        Levels *level4 = new Levels(boughtHealth,boughtFence, 2500, ":/images/textures/castle4.png", "qrc:/sound/Sound/theme4.mp3", ":/textfiles/TextFiles/level4.txt", ":/images/textures/ice.jpg", boughtWeapon, bulletSound, boughtRecoil, boughtDamage, boughtSpeed, boughtBullet, 1800, 250, 250, ":/images/textures/wolfwalkleft1.png", ":/images/textures/wolfwalkleft2.png", ":/images/textures/wolfwalkleft3.png", ":/images/textures/wolfwalkleft4.png", ":/images/textures/wolfwalkleft5.png", ":/images/textures/wolfwalkright1.png", ":/images/textures/wolfwalkright2.png", ":/images/textures/wolfwalkright3.png", ":/images/textures/wolfwalkright4.png", ":/images/textures/wolfwalkright5.png",  ":/images/textures/wolfattackright1.png", ":/images/textures/wolfattackright2.png", ":/images/textures/wolfattackright3.png", ":/images/textures/wolfattackright4.png", ":/images/textures/wolfattackright5.png", ":/images/textures/wolfattackleft1.png", ":/images/textures/wolfattackleft2.png", ":/images/textures/wolfattackleft3.png", ":/images/textures/wolfattackleft4.png", ":/images/textures/wolfattackleft5.png",350, "qrc:/sound/Sound/ah4.mp3", 1*30);
    } else if (currlevel == 5) {
        Levels *level5 = new Levels(boughtHealth, boughtFence, 4000, ":/images/textures/castle5.png", "qrc:/sound/Sound/theme5.mp3", ":/textfiles/TextFiles/level5.txt", ":/images/textures/rocks.jpg", boughtWeapon, bulletSound, boughtRecoil, boughtDamage, boughtSpeed, boughtBullet, 1500, 500, 500, ":/images/textures/demonwalkleft1.png", ":/images/textures/demonwalkleft2.png", ":/images/textures/demonwalkleft3.png", ":/images/textures/demonwalkleft4.png", ":/images/textures/demonwalkleft5.png", ":/images/textures/demonwalkright1.png", ":/images/textures/demonwalkright2.png", ":/images/textures/demonwalkright3.png", ":/images/textures/demonwalkright4.png", ":/images/textures/demonwalkright5.png", ":/images/textures/demonattackright1.png", ":/images/textures/demonattackright2.png", ":/images/textures/demonattackright3.png", ":/images/textures/demonattackright4.png", ":/images/textures/demonattackright5.png", ":/images/textures/demonattackleft1.png", ":/images/textures/demonattackleft2.png", ":/images/textures/demonattackleft3.png", ":/images/textures/demonattackleft4.png", ":/images/textures/demonattackleft5.png", 350, "qrc:/sound/Sound/ah5.mp3", 1*35);
    }
}

int Market::getTokens()
{
    return tokens;
}

void Market::setTokens(int newTokens)
{
    tokens = newTokens;
}

void Market::checkTimer()
{
    ui->labelTokens->setText("Money: " + QString::number(tokens) + "$");
}

void Market::on_pushButtonBuy1_clicked()
{
    buysuccessfuloutput = new QAudioOutput();
    buysuccessfuloutput->setVolume(50);
    buysuccessful = new QMediaPlayer();
    buysuccessful->setAudioOutput(buysuccessfuloutput);
    buysuccessful->setSource(QUrl("qrc:/sound/Sound/buysuccessful.mp3"));

    buyfailedoutput = new QAudioOutput();
    buyfailedoutput->setVolume(80);
    buyfailed = new QMediaPlayer();
    buyfailed->setAudioOutput(buyfailedoutput);
    buyfailed->setSource(QUrl("qrc:/sound/Sound/buyfailed.mp3"));
    if(boughtWeapon == ":/images/textures/weapon2.png") //Item bought before
    {
        //bought before error.
        buyfailed->stop();
        buyfailed->play();
        ui->labelError->setText("You already own this.");
        ui->labelError->setVisible(true);
        delay(2);
        ui->labelError->setVisible(false);
    }
    else
    {
        if(tokens >= 250)
        {
            buysuccessful->stop();
            buysuccessful->play();
            boughtWeapon = ":/images/textures/weapon2.png";
            boughtDamage = 100;
            boughtBullet = " ";
            boughtSpeed = 2;
            boughtRecoil = 500;
            tokens-=250;
            boughtBullet = ":/images/textures/bullet2.png";
            bulletSound = "qrc:/sound/Sound/hit2.mp3";
            ui->labelError->setVisible(false);
            ui->labelSuccessful->setVisible(true);
            delay(2);
            ui->labelSuccessful->setVisible(false);

        }
        else //insufficient money
        {
            buyfailed->stop();
            buyfailed->play();
            ui->labelError->setText("Insufficient Money.");
            ui->labelError->setVisible(true);
            delay(2);
            ui->labelError->setVisible(false);
        }
    }
}


void Market::on_pushButtonBuy2_clicked()
{
    buysuccessfuloutput = new QAudioOutput();
    buysuccessfuloutput->setVolume(50);
    buysuccessful = new QMediaPlayer();
    buysuccessful->setAudioOutput(buysuccessfuloutput);
    buysuccessful->setSource(QUrl("qrc:/sound/Sound/buysuccessful.mp3"));

    buyfailedoutput = new QAudioOutput();
    buyfailedoutput->setVolume(80);
    buyfailed = new QMediaPlayer();
    buyfailed->setAudioOutput(buyfailedoutput);
    buyfailed->setSource(QUrl("qrc:/sound/Sound/buyfailed.mp3"));
    if(boughtWeapon == ":/images/textures/weapon3.png") //Item bought before
    {
        //bought before error.
        buyfailed->stop();
        buyfailed->play();
        ui->labelError->setText("You already own this.");
        ui->labelError->setVisible(true);
        delay(2);
        ui->labelError->setVisible(false);
    }
    else
    {
        if(tokens >= 500)
        {
            buysuccessful->stop();
            buysuccessful->play();
            boughtWeapon = ":/images/textures/weapon3.png";
            boughtDamage = 150;
            boughtSpeed = 3;
            boughtRecoil = 600;
            tokens-=500;
            boughtBullet = ":/images/textures/bullet3.png";
            bulletSound = "qrc:/sound/Sound/hit3.mp3";
            ui->labelError->setVisible(false);
            ui->labelSuccessful->setVisible(true);
            delay(2);
            ui->labelSuccessful->setVisible(false);


        }
        else //insufficient money
        {
            buyfailed->stop();
            buyfailed->play();
            ui->labelError->setText("Insufficient Money.");
            ui->labelError->setVisible(true);
            delay(2);
            ui->labelError->setVisible(false);

        }
    }
}


void Market::on_pushButtonBuy3_clicked()
{
    buysuccessfuloutput = new QAudioOutput();
    buysuccessfuloutput->setVolume(50);
    buysuccessful = new QMediaPlayer();
    buysuccessful->setAudioOutput(buysuccessfuloutput);
    buysuccessful->setSource(QUrl("qrc:/sound/Sound/buysuccessful.mp3"));

    buyfailedoutput = new QAudioOutput();
    buyfailedoutput->setVolume(80);
    buyfailed = new QMediaPlayer();
    buyfailed->setAudioOutput(buyfailedoutput);
    buyfailed->setSource(QUrl("qrc:/sound/Sound/buyfailed.mp3"));
    if(boughtWeapon == ":/images/textures/weapon4.png") //Item bought before
    {
        //bought before error.
        buyfailed->stop();
        buyfailed->play();
        ui->labelError->setText("You already own this.");
        ui->labelError->setVisible(true);
        delay(2);
        ui->labelError->setVisible(false);
    }
    else
    {
        if(tokens >= 750)
        {
            buysuccessful->stop();
            buysuccessful->play();
            boughtWeapon = ":/images/textures/weapon4.png";
            boughtDamage = 40;
            boughtSpeed = 8;
            boughtRecoil = 80;
            boughtBullet = ":/images/textures/bullet4.png";
            bulletSound = "qrc:/sound/Sound/hit4.mp3";
            tokens-=750;
            ui->labelError->setVisible(false);
            ui->labelSuccessful->setVisible(true);
            delay(2);
            ui->labelSuccessful->setVisible(false);

        }
        else //insufficient money
        {
            buyfailed->stop();
            buyfailed->play();
            ui->labelError->setText("Insufficient Money.");
            ui->labelError->setVisible(true);
            delay(2);
            ui->labelError->setVisible(false);

        }
    }
}


void Market::on_pushButtonBuy4_clicked()
{
    buysuccessfuloutput = new QAudioOutput();
    buysuccessfuloutput->setVolume(50);
    buysuccessful = new QMediaPlayer();
    buysuccessful->setAudioOutput(buysuccessfuloutput);
    buysuccessful->setSource(QUrl("qrc:/sound/Sound/buysuccessful.mp3"));

    buyfailedoutput = new QAudioOutput();
    buyfailedoutput->setVolume(80);
    buyfailed = new QMediaPlayer();
    buyfailed->setAudioOutput(buyfailedoutput);
    buyfailed->setSource(QUrl("qrc:/sound/Sound/buyfailed.mp3"));

    buyfailed->stop();
    buysuccessful->stop();
    if(boughtWeapon == ":/images/textures/weapon5.png") //Item bought before
    {
        //bought before error.
        buyfailed->play();
        ui->labelError->setText("You already own this.");
        ui->labelError->setVisible(true);
        delay(2);
        ui->labelError->setVisible(false);
    }
    else
    {
        if(tokens >= 1250)
        {
            buysuccessful->play();
            boughtWeapon = ":/images/textures/weapon5.png";
            boughtDamage = 250;
            boughtBullet = " ";
            boughtSpeed = 7;
            boughtRecoil = 300;
            boughtBullet = ":/images/textures/bullet5.png";
            bulletSound = "qrc:/sound/Sound/hit1.mp3";
            tokens-=1250;
            ui->labelError->setVisible(false);
            ui->labelSuccessful->setVisible(true);
            delay(2);
            ui->labelSuccessful->setVisible(false);
        }
        else //insufficient money
        {
            buyfailed->play();
            ui->labelError->setText("Insufficient Money.");
            ui->labelError->setVisible(true);
            delay(2);
            ui->labelError->setVisible(false);

        }
    }
}


void Market::on_pushButtonBuy5_clicked()
{
    buysuccessfuloutput = new QAudioOutput();
    buysuccessfuloutput->setVolume(50);
    buysuccessful = new QMediaPlayer();
    buysuccessful->setAudioOutput(buysuccessfuloutput);
    buysuccessful->setSource(QUrl("qrc:/sound/Sound/buysuccessful.mp3"));

    buyfailedoutput = new QAudioOutput();
    buyfailedoutput->setVolume(80);
    buyfailed = new QMediaPlayer();
    buyfailed->setAudioOutput(buyfailedoutput);
    buyfailed->setSource(QUrl("qrc:/sound/Sound/buyfailed.mp3"));

    if(boughtFence == ":/images/textures/fence2.png") //Item bought before
    {
        //bought before error.
        buyfailed->stop();
        buyfailed->play();
        ui->labelError->setText("You already own this.");
        ui->labelError->setVisible(true);
        delay(2);
        ui->labelError->setVisible(false);
    }
    else
    {
        if(tokens >= 250)
        {
            buysuccessful->stop();
            buysuccessful->play();
            boughtFence = ":/images/textures/fence2.png";
            boughtHealth = 1000;
            tokens-=250;
            ui->labelError->setVisible(false);
            ui->labelSuccessful->setVisible(true);
            delay(2);
            ui->labelSuccessful->setVisible(false);

        }
        else //insufficient money
        {
            buyfailed->stop();
            buyfailed->play();
            ui->labelError->setText("Insufficient Money.");
            ui->labelError->setVisible(true);
            delay(2);
            ui->labelError->setVisible(false);

        }
    }
}


void Market::on_pushButtonBuy6_clicked()
{
    buysuccessfuloutput = new QAudioOutput();
    buysuccessfuloutput->setVolume(50);
    buysuccessful = new QMediaPlayer();
    buysuccessful->setAudioOutput(buysuccessfuloutput);
    buysuccessful->setSource(QUrl("qrc:/sound/Sound/buysuccessful.mp3"));

    buyfailedoutput = new QAudioOutput();
    buyfailedoutput->setVolume(80);
    buyfailed = new QMediaPlayer();
    buyfailed->setAudioOutput(buyfailedoutput);
    buyfailed->setSource(QUrl("qrc:/sound/Sound/buyfailed.mp3"));

    if(boughtFence == ":/images/textures/fence3.png") //Item bought before
    {
        //bought before error.
        buyfailed->stop();
        buyfailed->play();
        ui->labelError->setText("You already own this.");
        ui->labelError->setVisible(true);
        delay(2);
        ui->labelError->setVisible(false);
    }
    else
    {
        if(tokens >= 500)
        {
            buysuccessful->stop();
            buysuccessful->play();
            boughtFence = ":/images/textures/fence3.png";
            boughtHealth = 2000;
            tokens-=500;
            ui->labelError->setVisible(false);
            ui->labelSuccessful->setVisible(true);
            delay(2);
            ui->labelSuccessful->setVisible(false);

        }
        else //insufficient money
        {
            buyfailed->stop();
            buyfailed->play();
            ui->labelError->setText("Insufficient Money.");
            ui->labelError->setVisible(true);
            delay(2);
            ui->labelError->setVisible(false);

        }
    }
}


void Market::on_pushButtonBuy7_clicked()
{
    buysuccessfuloutput = new QAudioOutput();
    buysuccessfuloutput->setVolume(50);
    buysuccessful = new QMediaPlayer();
    buysuccessful->setAudioOutput(buysuccessfuloutput);
    buysuccessful->setSource(QUrl("qrc:/sound/Sound/buysuccessful.mp3"));

    buyfailedoutput = new QAudioOutput();
    buyfailedoutput->setVolume(80);
    buyfailed = new QMediaPlayer();
    buyfailed->setAudioOutput(buyfailedoutput);
    buyfailed->setSource(QUrl("qrc:/sound/Sound/buyfailed.mp3"));

    if(boughtFence == ":/images/textures/fence4.png") //Item bought before
    {
        //bought before error.
        buyfailed->stop();
        buyfailed->play();
        ui->labelError->setText("You already own this.");
        ui->labelError->setVisible(true);
        delay(2);
        ui->labelError->setVisible(false);
    }
    else
    {
        if(tokens >= 750)
        {
            buysuccessful->stop();
            buysuccessful->play();
            boughtFence = ":/images/textures/fence4.png";
            boughtHealth = 4000;
            tokens-=750;
            ui->labelError->setVisible(false);
            ui->labelSuccessful->setVisible(true);
            delay(2);
            ui->labelSuccessful->setVisible(false);

        }
        else //insufficient money
        {
            buyfailed->stop();
            buyfailed->play();
            ui->labelError->setText("Insufficient Money.");
            ui->labelError->setVisible(true);
            delay(2);
            ui->labelError->setVisible(false);

        }
    }
}


void Market::on_pushButtonBuy8_clicked()
{
    buysuccessfuloutput = new QAudioOutput();
    buysuccessfuloutput->setVolume(50);
    buysuccessful = new QMediaPlayer();
    buysuccessful->setAudioOutput(buysuccessfuloutput);
    buysuccessful->setSource(QUrl("qrc:/sound/Sound/buysuccessful.mp3"));

    buyfailedoutput = new QAudioOutput();
    buyfailedoutput->setVolume(80);
    buyfailed = new QMediaPlayer();
    buyfailed->setAudioOutput(buyfailedoutput);
    buyfailed->setSource(QUrl("qrc:/sound/Sound/buyfailed.mp3"));

    if(boughtFence == ":/images/textures/fence5.png") //Item bought before
    {
        //bought before error.
        buyfailed->stop();
        buyfailed->play();
        ui->labelError->setText("You already own this.");
        ui->labelError->setVisible(true);
        delay(2);
        ui->labelError->setVisible(false);
    }
    else
    {
        if(tokens >= 1250)
        {
            buysuccessful->stop();
            buysuccessful->play();
            boughtFence = ":/images/textures/fence5.png";
            boughtHealth = 7000;
            tokens-=1250;
            ui->labelError->setVisible(false);
            ui->labelSuccessful->setVisible(true);
            delay(2);
            ui->labelSuccessful->setVisible(false);

        }
        else //insufficient money
        {
            buyfailed->stop();
            buyfailed->play();
            ui->labelError->setText("Insufficient Money.");
            ui->labelError->setVisible(true);
            delay(2);
            ui->labelError->setVisible(false);

        }
    }
}

