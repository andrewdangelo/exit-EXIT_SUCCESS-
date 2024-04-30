/* Author: Sean Melone
Date: 4/29
Description: file with definitions of FieldInhabitant functions
*/


#include "FieldInhabitant.h"
FieldInahbitant::FieldInahbitant(string symbol){
	this -> symbol = symbol;
}
FieldInahbitant::~FieldInahbitant(){
}
string FieldInahbitant::getSymbol(){
	return symbol;
}

