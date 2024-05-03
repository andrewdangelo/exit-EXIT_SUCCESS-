/* Author: Sean Melone
Date: 4/29
Description: file with definitions of veggie functions
*/

#include "Veggie.h"

Veggie::Veggie(string name, string symbol, int points) : FieldInhabitant(symbol){
	this -> points = points;
	this -> name = name;
	this -> symbol = symbol;
}

string Veggie::getName(){
	return name;
}

int Veggie::getPoints(){
	return points;
}

void Veggie::setPoints(int points){
	this -> points = points;
}