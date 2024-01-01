#ifndef CASTLE_H
#define CASTLE_H
#include "object.h"

class Castle: public Object
{
private:

public:
    Castle(int health, QString castlepath);
};

#endif // CASTLE_H
