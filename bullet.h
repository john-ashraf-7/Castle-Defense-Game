#ifndef BULLET_H
#define BULLET_H
#include "object.h"
#include <QCursor>
#include <QPoint>
#include <QGraphicsScene>
#include <QtMath>

class Bullet:public Object, public QObject
{
private:
    QGraphicsScene *main_scene;
    qreal x_initial;
    qreal y_initial;
    float increment_x;
    float increment_y;
    int damage;
    float speed;


public:
    Bullet(QGraphicsScene *main_scene, qreal x_initial, qreal y_initial, int damage, int speed, QString bulletpath);
    QPoint getMousePosition();
    int getDamage();
    void setDamage(int damage);

public slots:
    void makeMove();
};

#endif // BULLET_H
