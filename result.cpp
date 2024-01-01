#include "result.h"
#include "ui_result.h"

Result::Result(int loseCount, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Result)
{
    ui->setupUi(this);

    this -> loseCount = loseCount;
    QPixmap pix(":/images/textures/result.jpeg");
    ui->labelpix->setPixmap(pix.scaled(ui->labelpix->width(),ui->labelpix->height()));
    ui->pushButtonMenu->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(20);
    shadow->setColor(QColor(0, 0, 0, 180));
    shadow->setOffset(0, 0);
    ui->pushButtonMenu->setGraphicsEffect(shadow);

    QFont bigfont;
    bigfont.setFamily("Arial");
    bigfont.setPointSize(45);
    bigfont.setWeight(QFont::Bold);

    QFont smallfont;
    smallfont.setFamily("Arial");
    smallfont.setPointSize(25);
    smallfont.setWeight(QFont::Bold);
    ui->labelfate->setFont(bigfont);
    ui->labeltext->setFont(smallfont);

    ui->labeltext->setStyleSheet("QLabel { color : white; }");

    if(loseCount<1) //happy ending
    {
        happyoutput = new QAudioOutput();
        happyoutput->setVolume(1);
        happysound = new QMediaPlayer();
        happysound->setAudioOutput(happyoutput);
        happysound->setSource(QUrl("qrc:/sound/Sound/happy.mp3")); //after QUrl we add ::fromLocalFile(//path) if we want to add music from a local path rather than resource file
        happysound->play();
        ui->labelfate->setStyleSheet("QLabel { color : green; }");
        ui -> labelfate->setText("Happy Ending");
        ui->labeltext ->setText("You did it! You saved the princess from the bloodthirsty\n wicked troops. Brave people like you are the ones\n who go unforgotten throughout history.\n play again, and may your legacy for saving princesses\n from the bad guys go unshaken");
    }
    else //sad ending
    {
        sadoutput = new QAudioOutput();
        sadoutput->setVolume(1);
        sadsound = new QMediaPlayer();
        sadsound->setAudioOutput(sadoutput);
        sadsound->setSource(QUrl("qrc:/sound/Sound/sad.mp3")); //after QUrl we add ::fromLocalFile(//path) if we want to add music from a local path rather than resource file
        sadsound->play();
        ui->labelfate->setStyleSheet("QLabel { color : red; }");
        ui -> labelfate->setText("Sad Ending");
        ui->labeltext ->setText("Too bad! The princess is now under the mercy of \nthe merciless troops, anticipating her death.\n Make sure to never let her down again!");
    }

}

Result::~Result()
{
    delete ui;
}

void Result::on_pushButtonMenu_clicked()
{
    if(loseCount<1)
    {
        happysound->stop();
    }
    else
    {
        sadsound->stop();
    }
    close();
    //stop music
    MainMenu *menu = new MainMenu();
    menu->show();
}
