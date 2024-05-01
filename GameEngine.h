#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "FieldInhabitant.h"
#include "Veggie.h"
#include "Captain.h"
#include "Rabbit.h"

class GameEngine {

private:
	const int NUMBEROFVEGGIES = 30;
	const int MAXNUMBEROFRABBITS = 5;
	const int RABBITPOINTS = 5;

	FieldInhabitant*** field;
	int height, width, score, timer;
	Captain* captain;
	vector<Rabbit> rabbits;

	void initVeggies(); //Andrews
	void initCaptain(); 
	void spawnRabbits();
	void moveCptVertical(int);
	void moveCptHorizontal(int);

public:
	void initializeGame();
	void intro();
	void printField();
	void moveRabbits();
	void moveCaptain();
	void timerTick();
	void gameOver();
	int getScore();
	int remainingVeggies();

};

#endif





