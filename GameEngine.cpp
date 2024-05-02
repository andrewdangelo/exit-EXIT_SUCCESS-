#include "GameEngine.h"
#include "Rabbit.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



void GameEngine::initializeGame(){
	//initVeggies() called
	srand(time(0));
	initVeggies();

	initCaptain();
	cout << "After initCaptain()" << endl;
	score = 0;
	timer = 0;
}

void GameEngine::initVeggies(){
	string filename;
	ifstream file;

	// Prompt user for veggie file name
	cout << "Please enter the name of the vegetable point file: ";
	cin >> filename;

	// Check if file exists
	file.open(filename);
	while (!file.is_open()) {
		cout << "VeggieFile does not exist! Please enter the name of the vegetable point file: ";
		cin >> filename;
		file.open(filename);
	}

	// Read height and width from file
	string line;
	getline(file, line);
	
	// Find the position of the comma separator
	size_t commaPos = line.find(',');

	// Extract the height and width from the line
	height = stoi(line.substr(commaPos + 1));
	width = stoi(line.substr(commaPos + 1 + line.substr(commaPos + 1).find(',') + 1));

	// Read veggie lines from file
	while (getline(file, line)) {
		// Find the position of the comma separators
		size_t commaPos1 = line.find(',');
		size_t commaPos2 = line.find(',', commaPos1 + 1);

		// Extract the name, symbol, and points from the line
		string name = line.substr(0, commaPos1);
		string symbol = line.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);
		int points = stoi(line.substr(commaPos2 + 1));

		// Create a new Veggie object and add it to the vector
		veggies.push_back(new Veggie(name, symbol, points));
	}

	file.close();

	// Create 2D dynamic array of FieldInhabitant pointers
	field = new FieldInhabitant**[height];
	for(int i = 0; i < height; i++) {
		field[i] = new FieldInhabitant*[width];
		for(int j = 0; j < width; j++) {
			field[i][j] = nullptr;
			
		}
	}

	// Populate the field with Veggie objects
	int numberOfVeggies = NUMBEROFVEGGIES;
	while (numberOfVeggies > 0) {
		// Generate random coordinates
		int x = rand() % width;
		int y = rand() % height;

		// Check if the location is occupied
		if (field[y][x] == nullptr) {
			// Choose a random Veggie from the vector
			int index = rand() % veggies.size();
			Veggie* chosenVeggie = veggies[index];

			// Create a new Veggie object and add it to the field
			field[y][x] = new Veggie(chosenVeggie->getName(), chosenVeggie->getSymbol(), chosenVeggie->getPoints());

			// Decrease the number of remaining Veggies
			numberOfVeggies--;
		}
	}
	printField();
}


void GameEngine::initCaptain(){

    int x, y;

    // Keep trying random positions until an empty one is found
    do {
        x = rand() % width;
        y = rand() % height;

    } while (field[y][x] != nullptr);  // Continue if the spot is not empty

    // Create a new Captain object and add it to the field
	captain = new Captain(x, y);
    field[y][x] = captain;
}

void GameEngine::spawnRabbits(){
	if (rabbits.size() < MAXNUMBEROFRABBITS) {

		// Seed the random number generator

		bool isSpawned = false;
		while (!isSpawned) {
			// Generate random coordinates
			int x = rand() % width;
			int y = rand() % height;

			// Check if the location is occupied
			if (field[y][x] == nullptr) {
				// Create a new Rabbit object and add it to the field and vector of rabbits
				Rabbit* newRabbit = new Rabbit(x,y);
				field[y][x] = newRabbit;
				rabbits.push_back(newRabbit);
				isSpawned = true;
				cout << "Rabbit spawned\n";
			}
		}
	}
}

int GameEngine::remainingVeggies(){
	int vegetableCount = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			
			// Make sure its a veggie object
			if (dynamic_cast<Veggie*>(field[i][j]) != nullptr) {
				vegetableCount++;
			}
		}
	}
	return vegetableCount;
}

void GameEngine::intro(){
	cout << "Welcome to Captain Veggie!" << endl;
	cout << "The rabbits are invading your garden and you must harvest" << endl;
	cout << "as many vegetables as possible before the rabbits eat them" << endl;
	cout << "all! Each vegetable is worth a different number of points" << endl;
	cout << "so go for the high score!" << endl;

	cout << "Possible Vegetables:" << endl;
	for (auto& veggie : veggies) {
		cout << "Name: " << veggie->getName() << ", Symbol: " << veggie->getSymbol() << ", Points: " << veggie->getPoints() << endl;
	}

	//cout << "Captain Symbol: " << captain->getSymbol() << endl;
	//cout << "Rabbit Symbol: " << rabbits[0].getSymbol() << endl;

	cout << "Catching a rabbit is worth 5 points, but more are always on the way!" << endl;
	cout << "Good luck!" << endl;
}

void GameEngine::printField(){
	for(int i = 0; i < width + 2; i++){
		cout << "# ";
	}
	cout << endl;
	for(int i = 0; i < height; i++){
		cout << "# ";
		for(int j = 0; j < width; j++){
			if(field[i][j] == nullptr){
				cout << " ";
			} else {
				cout << field[i][j]->getSymbol();
			}
			cout << " ";
		}
		cout << "#" << endl;
	}
	for(int i = 0; i < width + 2; i++){
		cout << "# ";
	}
	cout << endl;

}

int GameEngine::getScore() {
	return score;
}

void GameEngine::moveRabbits(){
	for (int i = 0; i < rabbits.size(); i++) {
		// Generate random direction
		int direction = rand() % 8;

		// Get the current position of the rabbit
		int x = rabbits[i]->getX();
		int y = rabbits[i]->getY();

		// Remove the rabbit from the field
		field[y][x] = nullptr;

		// Move the rabbit in the chosen direction
		//todo make sure to check for rabbits
		switch (direction) {
			case 0: // Up
				if (y - 1 >= 0 && dynamic_cast<Rabbit*>(field[y-1][x]) == nullptr) {
					rabbits[i]->setY(y - 1);
				}
				break;
			case 1: // Down
				if (y + 1 < height && dynamic_cast<Rabbit*>(field[y+1][x]) == nullptr) {
					rabbits[i]->setY(y + 1);
				}
				break;
			case 2: // Left
				if (x - 1 >= 0 && dynamic_cast<Rabbit*>(field[y][x-1]) == nullptr) {
					rabbits[i]->setX(x - 1);
				}
				break;
			case 3: // Right
				if (x + 1 < width && dynamic_cast<Rabbit*>(field[y][x+1]) == nullptr) {
					rabbits[i]->setX(x + 1);
				}
				break;
			case 4: // Up-Left
				if (y - 1 >= 0 && x - 1 >= 0 && dynamic_cast<Rabbit*>(field[y-1][x-1]) == nullptr) {
					rabbits[i]->setY(y - 1);
					rabbits[i]->setX(x - 1);
				}
				break;
			case 5: // Up-Right
				if (y - 1 >= 0 && x + 1 < width && dynamic_cast<Rabbit*>(field[y-1][x+1]) == nullptr) {
					rabbits[i]->setY(y - 1);
					rabbits[i]->setX(x + 1);
				}
				break;
			case 6: // Down-Left
				if (y + 1 < height && x - 1 >= 0 && dynamic_cast<Rabbit*>(field[y+1][x-1]) == nullptr) {
					rabbits[i]->setY(y + 1);
					rabbits[i]->setX(x - 1);
				}
				break;
			case 7: // Down-Right
				if (y + 1 < height && x + 1 < width && dynamic_cast<Rabbit*>(field[y+1][x+1]) == nullptr) {
					rabbits[i]->setY(y + 1);
					rabbits[i]->setX(x + 1);
				}
				break;
		}

		// Check if the rabbit has landed on a Captain or Veggie
		if (dynamic_cast<Captain*>(field[y][x]) != nullptr) {
			// Remove the Captain from the field
			field[y][x] = nullptr;

			// Add the rabbit to the field
			field[rabbits[i]->getY()][rabbits[i]->getX()] = rabbits[i];

			// Update the score
			score -= RABBITPOINTS;
		} else if (dynamic_cast<Veggie*>(field[y][x]) != nullptr) {
			// Remove the Veggie from the field
			field[y][x] = nullptr;

			// Add the rabbit to the field
			field[rabbits[i]->getY()][rabbits[i]->getX()] = rabbits[i];
		} else {
			// Add the rabbit to the field
			field[rabbits[i]->getY()][rabbits[i]->getX()] = rabbits[i];
		}
	}
}


void  GameEngine::timerTick()
{
    //Every 5 ticks or when timer is 0, a Rabbit spawns
	if (timer % 5 == 0){
	spawnRabbits();
	}
    timer=timer+1;
}

void GameEngine::moveCptVertical(int direction){
	// Get the current position of the Captain
	int x = captain->getX();
	int y = captain->getY();

	// Calculate the new position based on the direction
	int newX = x;
	int newY = y;
	switch (direction) {
		case 0: // Up
			newY = y - 1;
			break;
		case 1: // Down
			newY = y + 1;
			break;
	}

	// Check if the new position is within the field boundaries
	if (newY >= 0 && newY < height) {
		// Check if the new position is empty
		if (field[newY][newX] == nullptr) {
			// Update the Captain's position
			captain->setY(newY);

			// Assign the Captain to the new location in the field
			field[newY][newX] = captain;

			// Set the previous location in the field to nullptr
			field[y][x] = nullptr;
		} else if (dynamic_cast<Veggie*>(field[newY][newX]) != nullptr) {
			// Update the Captain's position
			captain->setY(newY);

			// Output that a delicious vegetable has been found
			Veggie* veggie = dynamic_cast<Veggie*>(field[newY][newX]);
			cout << "Yummy! A delicious " << veggie->getName()<< endl;

			// Add the Veggie to the Captain's vector of Veggies
			captain->addVeggie(veggie);

			// Increment the player's score
			score += veggie->getPoints();

			// Assign the Captain to the new location in the field
			field[newY][newX] = captain;

			// Set the previous location in the field to nullptr
			field[y][x] = nullptr;
		} else if (dynamic_cast<Rabbit*>(field[newY][newX]) != nullptr) {
			//The rabbit is in this location
			// Update the Captain's position
			captain->setY(newY);

			// Output that the Captain has caught a rabbit
			cout << "The Captain has caught one of the rabbits!" << endl;

			// Remove the Rabbit from the vector of Rabbit pointers
			Rabbit* rabbit = dynamic_cast<Rabbit*>(field[newY][newX]);
			rabbits.erase(remove(rabbits.begin(), rabbits.end(), rabbit), rabbits.end());

			// Increment the player's score
			score += RABBITPOINTS;

			// Assign the Captain to the new location in the field
			field[newY][newX] = captain;

			// Set the previous location in the field to nullptr
			field[y][x] = nullptr;
		}
	}
}

void GameEngine::moveCptHorizontal(int direction){
	// Get the current position of the Captain

	int x = captain->getX();
	int y = captain->getY();

	// Calculate the new position based on the direction
	int newX = x;
	int newY = y;
	switch (direction) {
		case 0: // Left
			newX = x - 1;
			break;
		case 1: // Right
			newX = x + 1;
			break;
	}

	// Check if the new position is within the field boundaries
	if (newX >= 0 && newX < width) {
		// Check if the new position is empty
		if (field[newY][newX] == nullptr) {
			// Update the Captain's position
			captain->setX(newX);

			// Assign the Captain to the new location in the field
			field[newY][newX] = captain;

			// Set the previous location in the field to nullptr
			field[y][x] = nullptr;
		} else if (dynamic_cast<Veggie*>(field[newY][newX]) != nullptr) {
			// Update the Captain's position
			captain->setX(newX);

			// Output that a delicious vegetable has been found
			Veggie* veggie = dynamic_cast<Veggie*>(field[newY][newX]);
			cout << "Yummy! A delicious " << veggie->getName()<< endl;

			// Add the Veggie to the Captain's vector of Veggies
			captain->addVeggie(veggie);

			// Increment the player's score
			score += veggie->getPoints();

			// Assign the Captain to the new location in the field
			field[newY][newX] = captain;

			// Set the previous location in the field to nullptr
			field[y][x] = nullptr;
		} else if (dynamic_cast<Rabbit*>(field[newY][newX]) != nullptr) {
			//The rabbit is in this location
			// Update the Captain's position
			captain->setX(newX);

			// Output that the Captain has caught a rabbit
			cout << "The Captain has caught one of the rabbits!" << endl;

			// Remove the Rabbit from the vector of Rabbit pointers
			Rabbit* rabbit = dynamic_cast<Rabbit*>(field[newY][newX]);
			rabbits.erase(remove(rabbits.begin(), rabbits.end(), rabbit), rabbits.end());
			// Increment the player's score
			score += RABBITPOINTS;

			// Assign the Captain to the new location in the field
			field[newY][newX] = captain;

			// Set the previous location in the field to nullptr
			field[y][x] = nullptr;
		}
	}
}

void GameEngine::moveCaptain(){
	// Get the current position of the Captain
	int x = captain->getX();
	int y = captain->getY();

	// Remove the Captain from the field
	

	// Move the Captain based on user input
	char direction;
	cout << "Enter a direction (WASD): ";
	cin >> direction;
	direction = tolower(direction); // Convert input to lowercase

	switch (direction) {
		case 'w': // Up
			if (y > 0) {
				moveCptVertical(0);
			} else {
				cout << "Invalid move! You cannot move up. Captain Veggie ran into the wall and hit his head!" << endl;
			}
			break;
		case 's': // Down
			if (y < height - 1) {
				moveCptVertical(1);
			} else {
				cout << "Invalid move! You cannot move down. Captain Veggie ran into the wall and hit his head!" << endl;
			}
			break;
		case 'a': // Left
			if (x > 0) {
				moveCptHorizontal(0);
			} else {
				cout << "Invalid move! You cannot move left. Captain Veggie ran into the wall and hit his head!" << endl;
			}
			break;
		case 'd': // Right
			if (x < width - 1) {
				moveCptHorizontal(1);
			} else {
				cout << "Invalid move! You cannot move right. Captain Veggie ran into the wall and hit his head!" << endl;
			}
			break;
	}
}

void GameEngine::gameOver(){
	cout << "Game Over!" << endl;
	cout << "You managed to harvest the following vegetables:" << endl;
	// iterate through veggie pointers in vector
	for (auto& veggie : captain->getCaptainVegs()) {
		cout << veggie->getName() << endl;
	}
	cout << "Your score was: " << score << endl;
	cout << "Remaining Veggies: " << remainingVeggies() << endl;
	cout << "Thank you for playing Captain Veggie!" << endl;
}
