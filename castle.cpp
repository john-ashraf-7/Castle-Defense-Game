#include "castle.h"

Castle::Castle(int health, QString castlepath)
{
    //initializing the helth, scale and the image of the castle.
    this -> health=health;
    QPixmap castle(castlepath);
    castle = castle.scaled(100,100);
    setPixmap(castle);
}
