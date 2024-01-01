#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QGraphicsDropShadowEffect>

MainMenu::MainMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    //setting main picture
    QPixmap pix(":/images/textures/mainmenupix.jpg");
    int w = ui->labelpix->width();
    int h = ui->labelpix->height();
    ui->labelpix->setPixmap(pix.scaled(w,h));

    //setting sound
    menuthemeoutput = new QAudioOutput();
    menuthemeoutput->setVolume(50);
    menutheme = new QMediaPlayer();
    menutheme->setAudioOutput(menuthemeoutput);
    menutheme->setSource(QUrl("qrc:/sound/Sound/menutheme.mp3"));
    menutheme->play();

    //designing buttons
    ui->pushButtonstart->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    ui->pushButtoncredits->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    ui->pushButtonexit->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    ui->pushButtonmanual->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(20);
    shadow->setColor(QColor(0, 0, 0, 180));
    shadow->setOffset(0, 0);
    ui->pushButtonstart->setGraphicsEffect(shadow);
    ui->pushButtoncredits->setGraphicsEffect(shadow);
    ui->pushButtonexit->setGraphicsEffect(shadow);
    ui->pushButtonmanual->setGraphicsEffect(shadow);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButtonstart_clicked()
{
    close();
    menutheme->stop();
    Market *w = new Market(1, 250);
    w->MarketReset(); //resets the items bought before to the free items u begin the game with.
    w->show();
}


void MainMenu::on_pushButtonexit_clicked()
{
    close();
}


void MainMenu::on_pushButtonmanual_clicked()
{
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView();
    view->setScene(scene);
    scene->setSceneRect(0,0,500,500);
    view->setWindowTitle("Manual");
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QGraphicsTextItem *textItem = new QGraphicsTextItem();
    textItem->setHtml("<h1>Welcome to the Manual</h1><p></p><p>Protect the princess from the bad guys! You are the clan; </p><p> using the fences and defense unit, make sure to</p><p> kill the troops that are spawning. </p><p> The defense unit auto-shoots, and using the mouse,</p><p> bullets are directed toward the troops. </p><p>Think you are up to level 1? There are still 4 more levels!</p><p> Each level gets more</p><p> challenging than the one before it. Do not worry though,</p><p> you can purchase new items from the</p><p> market after each level using the tokens</p><p> you received from shooting the troops. As you advance</p><p> each level, you get closer and closer to the princess.</p><p> Every time you lose a level, you keep her</p><p> waiting longer. Did you win? Hurray! You saved </p><p>the princess from the troops! Did you lose? The</p><p> frightened and disappointed princess is now under the troops’ mercy. You let her down.");
    scene->addItem(textItem);
    view->show();
}


void MainMenu::on_pushButtoncredits_clicked()
{
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView();
    view->setScene(scene);
    scene->setSceneRect(0,0,500,500);
    view->setWindowTitle("Credits");
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QGraphicsTextItem *textItem = new QGraphicsTextItem();
    textItem->setHtml("<h1>Game created by</h1></p><p>John Ibrahim.</p><p>Omar Ganna.</p><p>Tony Yohana</p>");
    scene->addItem(textItem);
    view->show();
}
