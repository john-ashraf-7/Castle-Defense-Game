#include "troops.h"
#include <QDebug>
#include <cstdlib>
#include "fences.h"
#include "castle.h"
#include "bullet.h"
#include "astar.h"

QVector<QVector<int>> Troops::map;
Troops::Troops(QGraphicsView *view,QVector<QVector<QChar>> Boarddata,QTimer *timer, QMediaPlayer *maintheme, Levels *thislevel, int damage, int health, QString troopmoveleft1path, QString troopmoveleft2path,QString troopmoveleft3path, QString troopmoveleft4path,QString troopmoveleft5path, QString troopmoveright1path, QString troopmoveright2path, QString troopmoveright3path, QString troopmoveright4path, QString troopmoveright5path,QString troopattackright1path,QString troopattackright2path,QString troopattackright3path,QString troopattackright4path,QString troopattackright5path,QString troopattackleft1path,QString troopattackleft2path,QString troopattackleft3path,QString troopattackleft4path,QString troopattackleft5path, int troopmovedelayms, QString hitpath)
//we are passing the main timer to the troops class to stop it if the troops destroyed the castle,this consequently ends the game.
{
    pix_transition = 0;
    targetfence=nullptr;
    this -> thislevel = thislevel;
    this -> maintheme = maintheme;
    this -> main_view=view;
    this -> health = health;
    this -> damage = damage;
    this -> hitpath = hitpath;

    //find the pointing direction of the troop based on his randomly spawned position.
    castle_x = thislevel->getCastle()->x();
    Boarddata2=Boarddata;

    //sound
    hitsoundoutput = new QAudioOutput();
    hitsoundoutput->setVolume(100);
    hitsound = new QMediaPlayer();
    hitsound->setAudioOutput(hitsoundoutput);
    hitsound->setSource(QUrl(hitpath)); //after QUrl we add ::fromLocalFile(//path) if we want to add music from a local path rather than resource file
    Makemap();

    //Randomly choose a valid initial position on the clan.
    do
    {
        row = rand() % Boarddata.size();
        col = rand() % Boarddata[0].size();

    } while(Boarddata2[row][col] != '0');
    setPos(col*50,row*50);

    //pixmap initializations
    troopmoveleft1pixmap = new QPixmap(troopmoveleft1path);
    *troopmoveleft1pixmap = troopmoveleft1pixmap->scaled(50,50);
    troopmoveleft2pixmap = new QPixmap(troopmoveleft2path);
    *troopmoveleft2pixmap = troopmoveleft2pixmap->scaled(50,50);
    troopmoveleft3pixmap = new QPixmap(troopmoveleft3path);
    *troopmoveleft3pixmap = troopmoveleft3pixmap->scaled(50,50);
    troopmoveleft4pixmap = new QPixmap(troopmoveleft4path);
    *troopmoveleft4pixmap = troopmoveleft4pixmap->scaled(50,50);
    troopmoveleft5pixmap = new QPixmap(troopmoveleft5path);
    *troopmoveleft5pixmap = troopmoveleft5pixmap->scaled(50,50);

    troopmoveright1pixmap = new QPixmap(troopmoveright1path);
    *troopmoveright1pixmap = troopmoveright1pixmap->scaled(50,50);
    troopmoveright2pixmap = new QPixmap(troopmoveright2path);
    *troopmoveright2pixmap = troopmoveright2pixmap->scaled(50,50);
    troopmoveright3pixmap = new QPixmap(troopmoveright3path);
    *troopmoveright3pixmap = troopmoveright3pixmap->scaled(50,50);
    troopmoveright4pixmap = new QPixmap(troopmoveright4path);
    *troopmoveright4pixmap = troopmoveright4pixmap->scaled(50,50);
    troopmoveright5pixmap = new QPixmap(troopmoveright5path);
    *troopmoveright5pixmap = troopmoveright5pixmap->scaled(50,50);

    troopattackright1pixmap =new QPixmap(troopattackright1path);
    *troopattackright1pixmap=troopattackright1pixmap->scaled(50,50);
    troopattackright2pixmap=new QPixmap(troopattackright2path);
    *troopattackright2pixmap=troopattackright2pixmap->scaled(50,50);
    troopattackright3pixmap=new QPixmap(troopattackright3path);
    *troopattackright3pixmap=troopattackright3pixmap->scaled(50,50);
    troopattackright4pixmap=new QPixmap(troopattackright4path);
    *troopattackright4pixmap=troopattackright4pixmap->scaled(50,50);
    troopattackright5pixmap=new QPixmap(troopattackright5path);
    *troopattackright5pixmap=troopattackright5pixmap->scaled(50,50);


    troopattackleft1pixmap =new QPixmap(troopattackleft1path);
    *troopattackleft1pixmap=troopattackleft1pixmap->scaled(50,50);
    troopattackleft2pixmap=new QPixmap(troopattackleft2path);
    *troopattackleft2pixmap=troopattackleft2pixmap->scaled(50,50);
    troopattackleft3pixmap=new QPixmap(troopattackleft3path);
    *troopattackleft3pixmap=troopattackleft3pixmap->scaled(50,50);
    troopattackleft4pixmap=new QPixmap(troopattackleft4path);
    *troopattackleft4pixmap=troopattackleft4pixmap->scaled(50,50);
    troopattackleft5pixmap=new QPixmap(troopattackleft5path);
    *troopattackleft5pixmap=troopattackleft5pixmap->scaled(50,50);

    //timer connections
    QObject::connect(&collisiontimer,&QTimer::timeout,this,&Troops::checkCollision); //checks for collision every millisecond.
    collisiontimer.start(1);
    QObject::connect(&movetimer,&QTimer::timeout,this,&Troops::makemove); //changes position for troops (A* Algorithm)
    movetimer.start(troopmovedelayms);
    QObject::connect(&attacktimer,&QTimer::timeout,this,&Troops::atckAnimation);
    QObject::connect(&animationtimer,&QTimer::timeout,this,&Troops::MoveAnimation); //sets pixmaps
    animationtimer.start(100);

}


// QTimer *Troops::getTimer()
// {
//     return &movetimer;
// }

bool Troops::isempty()
{
    map.resize(Boarddata2.size());
    for (int i = 0; i < Boarddata2.size(); ++i)
    {
        map[i].resize(Boarddata2[i].size());
    }
    for(int i=0;i<Boarddata2.size();i++)
    {
        for(int j=0;j<Boarddata2[0].size();j++)
        {
            if(map[i][j]!=0)
            {
                return false;
            }
        }
    }
    return true;
}

void Troops::Makemap()
{
    if(isempty()){
        map.resize(Boarddata2.size());
        for (int i = 0; i < Boarddata2.size(); ++i)
        {
            map[i].resize(Boarddata2[i].size());
        }
        for (int i = 0; i < Boarddata2.size()/* && i < map.size()*/; ++i)
        {
            for (int j = 0; j < Boarddata2[i].size()/* && j < map[i].size()*/; ++j)
            {
                if(Boarddata2[i][j]=='1') //fence
                {
                    map[i][j]=6;
                }
                else if(Boarddata2[i][j]=='2') //castle
                {
                    map[i][j]=2;
                }
                else if(Boarddata2[i][j]=='3') //cannon
                {
                    map[i][j]=20000;
                }
                else //other
                {
                    map[i][j]=1;
                }
            }
        }
    }

}
void Troops::MoveAnimation()
{
    if(x() > x_prev) //troop pointing right
    {
        switch (pix_transition)
        {
        case 1:
            setPixmap(*troopmoveright1pixmap);
            break;
        case 2:
            setPixmap(*troopmoveright2pixmap);
            break;
        case 3:
            setPixmap(*troopmoveright3pixmap);
            break;
        case 4:
            setPixmap(*troopmoveright4pixmap);
            break;
        case 5:
            setPixmap(*troopmoveright5pixmap);
            break;
        default:
            break;
        }
    }
    else if(x()< x_prev) //troop pointing left
    {
        switch (pix_transition)
        {
        case 1:
            setPixmap(*troopmoveleft1pixmap);
            break;
        case 2:
            setPixmap(*troopmoveleft2pixmap);
            break;
        case 3:
            setPixmap(*troopmoveleft3pixmap);
            break;
        case 4:
            setPixmap(*troopmoveleft4pixmap);
            break;
        case 5:
            setPixmap(*troopmoveleft5pixmap);
            break;
        default:
            break;
        }
    }
    else //troop moving up or down --> point at castle
    {
        if(castle_x >= x())
        {
            switch (pix_transition)
            {
            case 1:
                setPixmap(*troopmoveright1pixmap);
                break;
            case 2:
                setPixmap(*troopmoveright2pixmap);
                break;
            case 3:
                setPixmap(*troopmoveright3pixmap);
                break;
            case 4:
                setPixmap(*troopmoveright4pixmap);
                break;
            case 5:
                setPixmap(*troopmoveright5pixmap);
                break;
            default:
                break;
            }
        }
        else
        {
            switch (pix_transition)
            {
            case 1:
                setPixmap(*troopmoveleft1pixmap);
                break;
            case 2:
                setPixmap(*troopmoveleft2pixmap);
                break;
            case 3:
                setPixmap(*troopmoveleft3pixmap);
                break;
            case 4:
                setPixmap(*troopmoveleft4pixmap);
                break;
            case 5:
                setPixmap(*troopmoveleft5pixmap);
                break;
            default:
                break;
            }
        }
    }
    pix_transition = ((pix_transition % 5) + 1);
}

void Troops::atckAnimation()
{
    if(targetfence){
    if(castle_x >= x())
    {
        switch (atck_transition)
        {
        case 1:
            setPixmap(*troopattackright1pixmap);
            break;
        case 2:
            setPixmap(*troopattackright2pixmap);
            break;
        case 3:
            setPixmap(*troopattackright3pixmap);
            break;
        case 4:
            setPixmap(*troopattackright4pixmap);
            break;
        case 5:
            setPixmap(*troopattackright5pixmap);
            break;
        default:
            break;
        }
    }
    else
    {
        switch (atck_transition)
        {
        case 1:
            setPixmap(*troopattackleft1pixmap);
            break;
        case 2:
            setPixmap(*troopattackleft2pixmap);
            break;
        case 3:
            setPixmap(*troopattackleft3pixmap);
            break;
        case 4:
            setPixmap(*troopattackleft4pixmap);
            break;
        case 5:
            setPixmap(*troopattackleft5pixmap);
            break;
        default:
            break;
        }
    }
    if(targetfence->getHealth()<=0)
    {
        attacktimer.stop();
        animationtimer.start(100);
        targetfence=nullptr;
    }
    else
    {
        QPoint troopPosition(x() / 50, y() / 50);
        if (!path1.isEmpty() && path1.first() != troopPosition)
        {
            attacktimer.stop();
            animationtimer.start(100);
            targetfence = nullptr;
        }
    }
    }
    atck_transition=((atck_transition%5)+1);
}



void Troops::checkCollision()
{
    QList<QGraphicsItem *> list = collidingItems() ;
    for(QGraphicsItem * i : list)
    {
        Fences * fenceitem= dynamic_cast<Fences *>(i);
        if (fenceitem)
        {
            //setPos(x()-movex*3, y()-movey*3);
            fenceitem->setHealth(fenceitem->getHealth()-damage);
            if(fenceitem->getHealth()>0)
            {
                targetfence=fenceitem;
                animationtimer.stop();
                attacktimer.start(100);
                setPos(x_prev, y_prev);
                return;
            }
            else //fence broken
            {
                attacktimer.stop();
                animationtimer.start(60);
                map[y()/50][x()/50]=0; //set weight to zero for A*
                scene()->removeItem(fenceitem);
            }
        }

        Bullet * bulletitem= dynamic_cast<Bullet *>(i);
        if (bulletitem)
        {
            if(thislevel->getTerminateCollision() || thislevel->getCastle()->getHealth() <= thislevel->getTroopDamage()) // this prevents the crash when a bullet hits a troop right before terminating the game.
            {
                qDebug() << "found Bullet collision after termination condition";
                return;
            }
            hitsoundoutput = new QAudioOutput();
            hitsoundoutput->setVolume(100);
            hitsound = new QMediaPlayer();
            hitsound->setAudioOutput(hitsoundoutput);
            hitsound->setSource(QUrl(hitpath));
            hitsound->stop();
            hitsound->play();
            this->setHealth(this->getHealth()-bulletitem->getDamage()); //damage then check

            if(this->getHealth()>0)
            {
                scene()->removeItem(bulletitem);
                delete bulletitem;
                return;
            }
            else
            {
                scene()->removeItem(bulletitem); //you have to put them in this order. if we remove and delete this object first, we can't delete the other then and it will cause a crash.
                scene()->removeItem(this);
                delete bulletitem; //crash
                delete this;
                return; //we have to return here to make sure no other code is executed in this instance's function after it got deleted.
            }
        }

        Castle * castleitem= dynamic_cast<Castle *>(i);
        if (castleitem)
        {
            castleitem->setHealth(castleitem->getHealth()-damage);
            if(castleitem->getHealth()>0)
            {
                setPos(x_prev, y_prev); //this funstion makes the troops move back and forth the castle as if they are tryung to destroy it.
                return;
            }
            else //castle destroyed. Game Lost
            {
                maintheme->stop();
                main_view->close();
                Win *win = new Win(false);
                win->show();
                delete thislevel;
                return;
            }
        }
    }

}

//Function that handles troop movement and detects collision while moving
void Troops::makemove()
{
    // pix_transition = (pix_transition+1) % 2;
    // qDebug() << pix_transition;

    //Find position of castle.
    float castleX;
    float castleY;
    for(int i=0;i<Boarddata2.size();i++){
        for(int j=0;j<Boarddata2[i].size();j++){
            if(Boarddata2[i][j]=='2'){
                castleX=j*50;
                castleY=i*50;
            }
        }
    }

    QPoint start(x()/50,y()/50);
    QPoint end(castleX/50,castleY/50);
    //path is made as an attribute because we want to access it in the function that displays the troop images (image looking left if the next position is on the left for example.)

    Astar astar(map,start,end);
    path1=astar.findpath();
    path1.removeFirst();
    //movement block of code.
    //these equations make the troops find the location of the castle and then move towards it in an Ecludian path

    double movex,movey;
    x_prev=0;
    y_prev=0;

    if(!path1.isEmpty()) //block of code where we dont update the A* vector if it finds a fence or castle.
    {
        QPoint nextCell = path1.first();
        x_prev=x();
        y_prev=y();
        if(map[nextCell.y()][nextCell.x()]==6) //fence
        {
            setPos( nextCell.x()*50 , nextCell.y()*50);
        }
        else if (map[nextCell.y()][nextCell.x()]==2) //castle
        {
            setPos( nextCell.x()*50 , nextCell.y()*50);
        }
        else // normal walking
        {
            path1.removeFirst();
            setPos(nextCell.x()*50,nextCell.y()*50);
        }
    }
}
void Troops::deletemap()
{
    for(int i=0;i<Boarddata2.size();i++)
    {
        for(int j=0;j<Boarddata2[0].size();j++)
        {
            map[i][j]=0;
        }
    }
}
