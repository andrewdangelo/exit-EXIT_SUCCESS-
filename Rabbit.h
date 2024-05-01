#ifndef RABBIT_H
#define RABBIT_H

#include "Creature.h"

class Rabbit : public Creature {
public:
    Rabbit(int x, int y);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
private:
    int x;
    int y;
};

#endif 