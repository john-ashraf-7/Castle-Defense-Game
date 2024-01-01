#include "object.h"

Object::Object()
{

}

int Object::getHealth()
{
    return health;
}

void Object::setHealth(int health)
{
    this -> health = health;
}

