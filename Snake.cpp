

#include "Snake.h"

Snake::Snake(int x, int y) : Creature(x, y, "S") {
	
}

void Snake::incrementCounter(){
	fatigueCounter++;
}

void Snake::resetCounter(){
	fatigueCounter = 0;
}