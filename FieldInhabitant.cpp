/* Author: Sean Melone
Date: 4/29
Description: file with definitions of FieldInhabitant functions
*/


#include "FieldInhabitant.h"
#include <iostream>
#include <string>

FieldInhabitant::FieldInhabitant(string symbol){
	this -> symbol = symbol;
}
FieldInhabitant::~FieldInhabitant(){
}
string FieldInhabitant::getSymbol(){
	return symbol;
}

