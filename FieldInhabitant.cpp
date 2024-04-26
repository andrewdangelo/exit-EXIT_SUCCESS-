/* Author: Dev Shah
 Date: 4/25/24
 Description: The program defines FieldInhabitant object.*/

#include "FieldInhabitant.h"

FieldInhabitant::FieldInhabitant(string symb) {

 symbol = symb;
 }

    string FieldInhabitant::getSymbol()
    {return symbol;}
    void FieldInhabitant::setSymbol(string symb)
{   symbol=symb;}
    FieldInhabitant::~FieldInhabitant()
    {}