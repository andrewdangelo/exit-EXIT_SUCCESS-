#ifndef SNAKE_H 
#define SNAKE_H

#include "Creature.h"

class Snake : public Creature {
private:
    int fatigueCounter = 0; // keeps track of fatigue turns after eating rabbit
public:
    Snake(int x, int y);
    void incrementCounter();
    void resetCounter();

};

#endif