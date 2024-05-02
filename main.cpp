#include "GameEngine.h"
int main(){
	GameEngine game;
	game.initializeGame();
	game.intro();
	while (game.remainingVeggies() != 0)

	{
		// todo print veggie ct and score
		game.getScore();
		game.printField();
		game.moveRabbits();
		game.moveCaptain();
		if(game.remainingVeggies() == 0){
			game.gameOver();
		}
		game.timerTick();
		cout << "Veggies remaining: " << game.remainingVeggies() << ". Score: " << game.getScore() << endl;
	}
		return 0; 
}