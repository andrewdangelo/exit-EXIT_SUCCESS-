#include "Veggie.h"

Veggie::Veggie(string symbol, string name, int points) : FieldInahbitant(symbol){
	this -> points = points;
	this -> name = name;
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
