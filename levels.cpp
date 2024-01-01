#include "levels.h"
#include <QDebug>
#include <QGraphicsScene>

Levels::Levels(int fencehealth, QString fencepath, int castlehealth, QString castlepath, QString levelthemepath, QString textfilepath, QString backgroundpath, QString cannonpath, QString shootpath, int shootdelayms, int bulletdamage, int bulletspeed, QString bulletpath, int spawntroopdelayms, int troopdamage, int troophealth, QString troopmoveleft1path, QString troopmoveleft2path,QString troopmoveleft3path, QString troopmoveleft4path,QString troopmoveleft5path, QString troopmoveright1path, QString troopmoveright2path, QString troopmoveright3path, QString troopmoveright4path, QString troopmoveright5path, QString troopattackright1path,QString troopattackright2path,QString troopattackright3path,QString troopattackright4path,QString troopattackright5path,QString troopattackleft1path,QString troopattackleft2path,QString troopattackleft3path,QString troopattackleft4path,QString troopattackleft5path,int troopmovedelayms, QString hitpath, int timerem)
{
    //mapping specific arguments to attributes.
    this -> troopdamage = troopdamage;
    this -> troophealth = troophealth;
    this -> troopmovedelayms = troopmovedelayms;
    this -> troopmoveleft1path = troopmoveleft1path;
    this -> troopmoveleft2path = troopmoveleft2path;
    this -> troopmoveleft3path = troopmoveleft3path;
    this -> troopmoveleft4path = troopmoveleft4path;
    this -> troopmoveleft5path = troopmoveleft5path;
    this -> troopmoveright1path = troopmoveright1path;
    this -> troopmoveright2path = troopmoveright2path;
    this -> troopmoveright3path = troopmoveright3path;
    this -> troopmoveright4path = troopmoveright4path;
    this -> troopmoveright5path = troopmoveright5path;
    this->troopattackleft1path=troopattackleft1path;
    this->troopattackleft2path=troopattackleft2path;
    this->troopattackleft3path=troopattackleft3path;
    this->troopattackleft4path=troopattackleft4path;
    this->troopattackleft5path=troopattackleft5path;
    this->troopattackright1path=troopattackright1path;
    this->troopattackright2path=troopattackright2path;
    this->troopattackright3path=troopattackright3path;
    this->troopattackright4path=troopattackright4path;
    this->troopattackright5path=troopattackright5path;
    this -> hitpath = hitpath;
    this -> timerem = timerem;
    terminateCollision = false;

    //sound block
    mainthemeoutput = new QAudioOutput();
    mainthemeoutput->setVolume(50);
    maintheme = new QMediaPlayer();
    maintheme->setAudioOutput(mainthemeoutput);
    maintheme->setSource(QUrl(levelthemepath)); //after QUrl we add ::fromLocalFile(//path) if we want to add music from a local path rather than resource file
    maintheme->play();

    //view and scene
    view = new QGraphicsView();
    scene = new QGraphicsScene();
    view->setScene(scene);
    view->setWindowTitle("Save The Princess");
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //reads the boarddata from a dynamic file (any size and separated by commas).
    QFile file(textfilepath);
    QTextStream stream(&file);
    QChar chartemp;
    QVector<QChar> data;
    if (file.open(QIODevice::ReadOnly)) {
        while(!stream.atEnd())
        {
            stream >> chartemp;
            if(chartemp == '0' || chartemp == '1' || chartemp == '2' || chartemp == '3'||  chartemp == '4')
                data.push_back(chartemp);
            // qDebug() << data;
            if(chartemp == '\n')
            {
                Boarddata.push_back(data);
                data.clear();
            }
        }
        file.close();
    }

    //setting up scene and view dimension based on the size of the vectors that read from the file(Making it applicable to change).
    scene->setSceneRect(0,0,Boarddata[0].size()*50,Boarddata.size()*50);
    view->setFixedSize(Boarddata[0].size()*50,Boarddata.size()*50);

    //initialize two 2D arrays for clan and background images.
    QGraphicsPixmapItem** BoardImages=new QGraphicsPixmapItem*[Boarddata.size()];
    QGraphicsPixmapItem** BackgroundImages=new QGraphicsPixmapItem*[Boarddata.size()];
    for(int i=0;i<Boarddata.size();i++)
    {

        BoardImages[i]= new QGraphicsPixmapItem[Boarddata[i].size()];
        BackgroundImages[i]= new QGraphicsPixmapItem[Boarddata[i].size()];

    }

    //render the background images first.
    QPixmap backgroundimg(backgroundpath); //path is taken from the arguments here. to change it from a level to another. (modular code)
    backgroundimg = backgroundimg.scaled(50,50);
    for(int i=0;i<Boarddata.size();i++)
    {
        for(int j=0;j<Boarddata[i].size();j++)
        {
            BackgroundImages[i][j].setPixmap(backgroundimg);
            scene->addItem(&BackgroundImages[i][j]);
            BackgroundImages[i][j].setPos(50*j,50*i);
        }
    }

    //render the rest of the assets
    for(int i=0;i<Boarddata.size();i++)
    {
        for(int j=0;j<Boarddata[i].size();j++)
        {
            BackgroundImages[i][j].setPixmap(backgroundimg);
            scene->addItem(&BackgroundImages[i][j]);
            BackgroundImages[i][j].setPos(50*j,50*i);
            if(Boarddata[i][j]=='1'){
                Fences *fence=new Fences(fencehealth, fencepath);
                fence->setPos(BackgroundImages[i][j].x(),BackgroundImages[i][j].y());
                scene->addItem(fence);

            }
            else if(Boarddata[i][j]=='2'){
                castle=new Castle(castlehealth, castlepath);
                castle->setPos(BackgroundImages[i][j].x(),BackgroundImages[i][j].y());
                scene->addItem(castle);
            }
            else if(Boarddata[i][j]=='3'){
                // adding a cannon. QGraphicsScene *main_scene, qreal x_initial, qreal y_initial, QString cannonpath, QString shootpath, int shootdelayms, int bulletdamage, int bulletspeed, QString bulletpath
                cannon=new Cannon(scene, BackgroundImages[i][j].x(), BackgroundImages[i][j].y(), cannonpath, shootpath, shootdelayms, bulletdamage, bulletspeed, bulletpath); //we pass scene because bullet is instantiated inside the cannon function and we want to add cannon to the scene before bullet. we pass the positions of cannon to set these postions before setting the bullet posiition since the position of the bullet will be the position of the cannon.
            }
            scene->addItem(&BoardImages[i][j]);
        }
    }

    //Procces for displaying the main timer in the screen.
    cddisplay=new QGraphicsTextItem();
    cddisplay->setFont(QFont("Arial",16));
    scene->addItem(cddisplay);
    cddisplay->setPos(0,0);
    QFont font("Arial", 30);
    cddisplay->setFont(font);
    QColor textColor(Qt::white);
    cddisplay->setDefaultTextColor(textColor);

    //timer-binded functions.
    QObject::connect(&cdtimer,&QTimer::timeout,this,&Levels::updatetime); //updates game time
    cdtimer.start(1000);
    QObject::connect(&timer,&QTimer::timeout,this,&Levels::spawnTroop); //spawns troops (spawn delay varies from one level to another)
    timer.start(spawntroopdelayms);

    view->show();
}

bool Levels::getTerminateCollision()
{
    return terminateCollision;
}

Levels::~Levels()
{
    scene->removeItem(castle);
    scene->removeItem(cannon);
    delete cannon;
    delete castle;
    troops->deletemap();
    cdtimer.stop();
    timer.stop();
}

Castle* Levels::getCastle() {
    return castle;
}

int Levels::getTroopDamage()
{
    return troopdamage;
}

void Levels::spawnTroop()
{
    //we pass the boarddata vector because we want to spawn troops on the '0' positions only.
    troops = new Troops(view,Boarddata,&cdtimer, maintheme, this, troopdamage, troophealth, troopmoveleft1path, troopmoveleft2path, troopmoveleft3path, troopmoveleft4path, troopmoveleft5path, troopmoveright1path, troopmoveright2path, troopmoveright3path, troopmoveright4path, troopmoveright5path,troopattackright1path,troopattackright2path,troopattackright3path,troopattackright4path,troopattackright5path,troopattackleft1path,troopattackleft2path,troopattackleft3path,troopattackleft4path,troopattackleft5path ,troopmovedelayms, hitpath);
    scene->addItem(troops);
}

//this is the function responsible for displaying the timer in the form of mins:secs.
QString Levels::timeslot(int sec)
{
    QTime time(0, sec /60,sec%60);
    return time.toString("mm:ss");
}

//function to update the remaining time.
void Levels::updatetime()
{
    timerem--;
    if(timerem==1)
    {
        qDebug() << "time is 1. terminate collision = false";
        terminateCollision=true;
    }
    if(timerem>0) //game running
    {
        cddisplay->setPlainText(timeslot(timerem));
    }
    else //game won
    {
        maintheme->stop();
        view->close();
        Win *win = new Win(true);
        win->show();
        delete this;
    }
}

