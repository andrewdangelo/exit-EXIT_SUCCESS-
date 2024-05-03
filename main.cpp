// Main function

#include "GameEngine.h"
int main(){
	GameEngine game;
	game.initializeGame();
	game.intro();
	while (game.remainingVeggies() != 0)

	{
		game.getScore();
		game.printField();
		game.moveRabbits();
		game.moveCaptain();
		// game.moveSnake(); unfinished function: leaving this here to finish later after the class for fun
		if(game.remainingVeggies() == 0){
			game.gameOver();
			break;
		}
		game.timerTick();
		cout << "Veggies remaining: " << game.remainingVeggies() << ". Score: " << game.getScore() << endl;
	}
		return 0; 
}