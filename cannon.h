#ifndef CANNON_H
#define CANNON_H
#include <QObject>
#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>

class Cannon: public Object, public QObject
{
private:
    QGraphicsScene *main_scene;
    qreal x_initial;
    qreal y_initial;
    QAudioOutput *shootoutput;
    QMediaPlayer *shoot;
    Bullet *bullet;
    QTimer timer;
    QTimer bulletmovetimer;
    int bulletdamage;
    int bulletspeed;
    QString bulletpath;
    QString shootpath;
public:
    Cannon(QGraphicsScene *main_scene, qreal x_initial, qreal y_initial, QString cannonpath, QString shootpath, int shootdelayms, int bulletdamage, int bulletspeed, QString bulletpath); //qreal is the type for positions. we pass the x() method as an argument to this parameter in clan.cpp
    ~Cannon();
public slots:
    void spawnBullet();
};

#endif // CANNON_H
