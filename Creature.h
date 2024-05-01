#ifndef CREATURE_H
#define CREATURE_H

#include "FieldInhabitant.h"

using namespace std;

class Creature : public FieldInhabitant {
public:
    Creature(int x, int y, const string& symbol);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    string getSymbol() const;
    void setSymbol(const string& symbol);

private:
    int x;
    int y;
    string symbol;
};

#endif