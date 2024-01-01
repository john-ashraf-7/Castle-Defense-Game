#include "fences.h"

Fences::Fences(int health, QString fencepath)
{
    //initializing the fences' health and image scale.
    this -> health = health;
    QPixmap fence(fencepath);
    fence = fence.scaled(50,50);
    setPixmap(fence);
}

