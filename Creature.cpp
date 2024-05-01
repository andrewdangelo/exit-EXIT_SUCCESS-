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
    return m_x;
}

void Creature::setX(int x) {
    m_x = x;
}

int Creature::getY() const {
    return m_y;
}

void Creature::setY(int y) {
    m_y = y;
}

string Creature::getSymbol() const {
    return m_symbol;
}

void Creature::setSymbol(const string& symbol) {
    m_symbol = symbol;
}