#ifndef VEGGIE_H
#define VEGGIE_H

#include "FieldInhabitant.h"

// inherit superclass with public access
class Veggie : public FieldInhabitant {
private:
	string name;
	int points;
public:
	Veggie(string, string, int);
	string getName();
	int getPoints();
	void setPoints(int);

};
#endif