#ifndef LEVELS_H
#define LEVELS_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QFile>
#include <QTextStream>
#include <Qvector>
#include <QChar>
#include "troops.h"
#include "cannon.h"
#include "fences.h"
#include <QTimer>
#include "castle.h"
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QTime>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "win.h"

class Troops;

class Levels:public QObject
{
    //Q_OBJECT
private:
    QVector<QVector<QChar>> Boarddata;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QTimer timer;
    QTimer cdtimer;
    QTimer timertest;
    Castle *castle;
    Cannon *cannon;
    Troops *troops;
    QGraphicsTextItem *cddisplay;
    int timerem;
    QAudioOutput *mainthemeoutput;
    QMediaPlayer *maintheme;
    QString hitpath;
    bool terminateCollision; //terminates bullet collision when time is 1 second to prevent crash
    int troophealth;
    int troopdamage;
    int troopmovedelayms;
    QString troopmoveleft1path, troopmoveleft2path, troopmoveleft3path, troopmoveleft4path,troopmoveleft5path, troopmoveright1path,  troopmoveright2path, troopmoveright3path,  troopmoveright4path, troopmoveright5path;
    QString troopattackright1path,troopattackright2path,troopattackright3path,troopattackright4path,troopattackright5path,troopattackleft1path,troopattackleft2path,troopattackleft3path,troopattackleft4path,troopattackleft5path;
public:
    Levels(int fencehealth, QString fencepath, int castlehealth, QString castlepath, QString levelthemepath, QString textfilepath, QString backgroundpath, QString cannonpath, QString shootpath, int shootdelayms, int bulletdamage, int bulletspeed, QString bulletpath, int spawntroopdelayms, int troopdamage, int troophealth, QString troopmoveleft1path, QString troopmoveleft2path,QString troopmoveleft3path, QString troopmoveleft4path,QString troopmoveleft5path, QString troopmoveright1path, QString troopmoveright2path, QString troopmoveright3path, QString troopmoveright4path, QString troopmoveright5path, QString troopattackright1path,QString troopattackright2path,QString troopattackright3path,QString troopattackright4path,QString troopattackright5path,QString troopattackleft1path,QString troopattackleft2path,QString troopattackleft3path,QString troopattackleft4path,QString troopattackleft5path,int troopmovedelayms, QString hitpath, int timerem);

    ~Levels();

    QString timeslot(int sec);

    QVector<QVector<QChar>> getBoarddata();
    void setBoarddata(QVector<QVector<QChar>>& boardData);

    QGraphicsScene* getScene();
    void setScene(QGraphicsScene* scn);

    QGraphicsView* getView();
    void setView(QGraphicsView* vw);

    Castle* getCastle() ;

    bool getTerminateCollision();

    Troops *getTroops() const;

    int getTroophealth() const;

    int getTroopDamage();

public slots:
    void spawnTroop();
    void updatetime();

};

#endif // LEVELS_H
