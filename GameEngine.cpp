#include "GameEngine.h"


void GameEngine::initializeGame(){
	initVeggies();
	initCaptain();
	score = 0;
	timer = 0;
}

void initVeggies(){

}

void GameEngine::intro(){

}

void GameEngine::printField(){
	// TODO: add border

	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			cout << field[i][j] -> getSymbol();
		}
		cout << '\n';
	}

}

int GameEngine::getScore(){
	return score;
}

