#include "lose.h"
#include "ui_lose.h"

Lose::Lose(int *currlevel, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Lose)
{
    ui->setupUi(this);
    loseoutput = new QAudioOutput();
    loseoutput->setVolume(20);
    losesound = new QMediaPlayer();
    losesound->setAudioOutput(loseoutput);
    losesound->setSource(QUrl("qrc:/sound/Sound/lose.mp3")); //after QUrl we add ::fromLocalFile(//path) if we want to add music from a local path rather than resource file
    losesound->play();

    QPixmap pix (":/images/textures/losescreen.png");
    int w = ui->labelLosePic->width();
    int h = ui->labelLosePic->height();
    ui->labelLosePic->setPixmap(pix.scaled(w,h));
    this -> currlevel = currlevel;
}

Lose::~Lose()
{
    delete ui;
}

void Lose::on_Retrybutton_clicked()
{
    // qDebug() <<"currlevel: " << *currlevel;
    // close();
    // losesound->stop();
    // Market *w = new Market(2); //we run the market of the current level.
    // w->show();
}


void Lose::on_MainMenubutton_2_clicked()
{
    losesound->stop();
    close();
    MainMenu *menu = new MainMenu;
    menu->show();
}

