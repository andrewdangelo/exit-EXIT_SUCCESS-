/* Author: Dev
Date: 4/29/2024
Description: Creature function definitions
*/


#include "Creature.h"
#include <iostream>
#include <string>

using namespace std;

Creature::Creature(int x, int y, const string& symbol) : FieldInhabitant(symbol) {
    this -> x = x;
    this -> y = y;
    this -> symbol = symbol;
}

int Creature::getX() const {
    return x;
}

void Creature::setX(int x) {
    this -> x = x;
}

int Creature::getY() const {
    return y;
}

void Creature::setY(int y) {
    this -> y = y;
}

string Creature::getSymbol() const {
    return symbol;
}

void Creature::setSymbol(const string& symbol) {
    this -> symbol = symbol;
}