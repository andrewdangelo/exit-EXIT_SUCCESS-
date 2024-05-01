#include "GameEngine.h"


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

