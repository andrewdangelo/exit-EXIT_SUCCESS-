/* Author: Sean Melone
Date: 4/29
Description: Header file with definition of FieldInhabitant superclass
*/


#ifndef FIELDINHABITANT_H
#define FIELDINHABITANT_H


#include <iostream>
#include <string>

using namespace std;


class FieldInhabitant {
	protected:
		string symbol;
	public:
		FieldInhabitant(string);
		string getSymbol();
		virtual ~FieldInhabitant();
};

#endif
