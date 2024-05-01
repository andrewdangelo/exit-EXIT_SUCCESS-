/* Author: Sean Melone
Date: 4/29
Description: file with definitions of FieldInhabitant functions
*/


#include "FieldInhabitant.h"
FieldInhabitant::FieldInhabitant(string symbol){
	this -> symbol = symbol;
}
FieldInhabitant::~FieldInhabitant(){
}
string FieldInhabitant::getSymbol(){
	return symbol;
}

