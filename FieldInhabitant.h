/* Author: Dev Shah
 Date: 4/25/24
 Description: The program makes FieldInhabitant class.*/


#ifndef FIELDINHABITANT_H
#define FIELDINHABITANT_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class FieldInhabitant {
private:
    string symbol;

public:
    FieldInhabitant(string symbol);

    string getSymbol();
    void setSymbol(string symbol);

    virtual ~FieldInhabitant();
};

#endif 
