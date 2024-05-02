#include "Rabbit.h"

Rabbit::Rabbit(int x, int y) : Creature(x, y, "R") {
    // Constructor implementation
    this->x = x;
    this->y = y;
}

int Rabbit::getX() const {
    return x;
}

void Rabbit::setX(int newX) {
    x = newX;
}

int Rabbit::getY() const {
    return y;
}

void Rabbit::setY(int newY) {
    y = newY;
}