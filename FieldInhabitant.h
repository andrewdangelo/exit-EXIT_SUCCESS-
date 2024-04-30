/* Author: Sean Melone
Date: 4/29
Description: Header file with definition of FieldInhabitant superclass
*/


#ifndef FIELDINHABITANT_H
#define FIELDINHABITANT_H


#include <iostream>

using namespace std;


class FieldInahbitant {
protected:
	string symbol;
public:
	FieldInahbitant(string);
	string getSymbol();
	virtual ~FieldInahbitant();
};

#endif
