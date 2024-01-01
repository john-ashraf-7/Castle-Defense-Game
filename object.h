#ifndef OBJECT_H
#define OBJECT_H
#include <QGraphicsPixmapItem>

class Object:public QGraphicsPixmapItem //Object is the base class that fences, castle, troops inheret from
//these class all share the attribute of health and they have a QPixmap
{
protected:
    int health;
public:
    Object();
    int getHealth();
    void setHealth(int health);
};

#endif // OBJECT_H
