#ifndef TROOPS_H
#define TROOPS_H
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include "object.h"
#include "qmediaplayer.h"
#include <QVector>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "levels.h"
#include "win.h"
#include "fences.h"
#include "castle.h"

class Levels; //forward declaration to get a pointer to the clan that the troop is inside.

class Troops: public Object, public QObject
{
private:
    QGraphicsView *main_view;
    QVector<QVector<QChar>> Boarddata2;
    int damage;
    float speed;
    int row;
    int col;
    bool gameover;
    QTimer movetimer;
    QTimer animationtimer;
    QTimer attacktimer;
    QTimer countdown;
    QTimer collisiontimer;
    QMediaPlayer *maintheme;
    QMediaPlayer *hitsound;
    bool gamelost;
    QAudioOutput *hitsoundoutput;
    QString hitpath;
    int castle_x;
    Levels *thislevel;
    QVector<QPoint> path1;     //path is made as an attribute because we want to access it in the function that displays the troop images (image looking left if the next position is on the left for example.)
    static QVector<QVector<int>> map;
    QPixmap *troopattackright1pixmap,*troopattackright2pixmap,*troopattackright3pixmap,*troopattackright4pixmap,*troopattackright5pixmap,*troopattackleft1pixmap,*troopattackleft2pixmap,*troopattackleft3pixmap,*troopattackleft4pixmap,*troopattackleft5pixmap;
    QPixmap *troopmoveleft1pixmap, *troopmoveleft2pixmap, *troopmoveleft3pixmap, *troopmoveleft4pixmap, *troopmoveleft5pixmap, *troopmoveright1pixmap, *troopmoveright2pixmap, *troopmoveright3pixmap, *troopmoveright4pixmap, *troopmoveright5pixmap;
    bool pointing_right; //to indicate the troop's picture direction
    int pix_transition; //to switch between move animations
    int atck_transition;
    int x_prev; //we keep track of x, y previous positions after each movement. Because when they collide with a fence or a castle they basically jump to the castle and apply collision then jump back to this position and repeat this process. damaging the castle each jump.
    int y_prev;
    Fences *targetfence;
    // QAudioOutput *mainthemeoutput;
    // QMediaPlayer *maintheme;
public:
    Troops(QGraphicsView *view,QVector<QVector<QChar>> Boarddata,QTimer *timer, QMediaPlayer *maintheme, Levels *thislevel, int damage, int health, QString troopmoveleft1path, QString troopmoveleft2path,QString troopmoveleft3path, QString troopmoveleft4path,QString troopmoveleft5path, QString troopmoveright1path, QString troopmoveright2path, QString troopmoveright3path, QString troopmoveright4path, QString troopmoveright5path,QString troopattackright1path,QString troopattackright2path,QString troopattackright3path,QString troopattackright4path,QString troopattackright5path,QString troopattackleft1path,QString troopattackleft2path,QString troopattackleft3path,QString troopattackleft4path,QString troopattackleft5path, int troopmovedelayms, QString hitpath);
    bool ifgameover();
    // QTimer *getTimer();
    void MoveAnimation();
    void atckAnimation();
    void checkCollision();
    void Makemap();
    bool isempty();
    void deletemap();
public slots:
    void makemove();
};

#endif // TROOPS_H
