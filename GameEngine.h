/* Author: Sean Melone
Date: 4/27/2024
Description: GameEngine class definition. GameEngine is the driver class of this program
*/


#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "FieldInhabitant.h"
#include "Veggie.h"
#include "Captain.h"
#include "Rabbit.h"
//#include "Snake.h"

class GameEngine {

private:
	const int NUMBEROFVEGGIES = 30;
	const int MAXNUMBEROFRABBITS = 5;
	const int RABBITPOINTS = 5;

	FieldInhabitant*** field;
	int height, width, score, timer;
	Captain* captain;
	// Snake* snake;
	vector<Rabbit*> rabbits;
	vector<Veggie*> veggies;

	void initVeggies(); //Andrews
	void initCaptain(); 
	//void initSnake();
	void spawnRabbits();
	void moveCptVertical(int);
	void moveCptHorizontal(int);
	void moveSnakeVertical(int);
	void moveSnakeHorizontal(int);

public:
	void initializeGame();
	void intro();
	void printField();
	void moveRabbits();
	void moveCaptain();
	//void moveSnake();
	void timerTick();
	void gameOver();
	int getScore();
	int remainingVeggies();

};

#endif