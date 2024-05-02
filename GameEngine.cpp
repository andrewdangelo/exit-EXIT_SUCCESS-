#include "GameEngine.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void GameEngine::initializeGame(){
	//initVeggies() called
	initVeggies();

	//initCaptain() called
	initCaptain();
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

	// Create vector to store Veggie objects
	vector<Veggie> veggies;

	// Read veggie lines from file
	while (getline(file, line)) {
		// Find the position of the comma separators
		size_t commaPos1 = line.find(',');
		size_t commaPos2 = line.find(',', commaPos1 + 1);

		// Extract the name, symbol, and points from the line
		string symbol = line.substr(0, commaPos1);
		string name = line.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);
		int points = stoi(line.substr(commaPos2 + 1));

		// Create a new Veggie object and add it to the vector
		veggies.push_back(Veggie(name, symbol, points));
	}

	// Print the vector of veggies (for testing)
	for (auto& veggie : veggies) {
		cout << "Name: " << veggie.getName() << ", Symbol: " << veggie.getSymbol()<< ", Points: " << veggie.getPoints() << endl;
	}

	// Create 2D dynamic array of FieldInhabitant pointers
	FieldInhabitant*** field = new FieldInhabitant**[height];
	for(int i = 0; i < height; i++) {
		field[i] = new FieldInhabitant*[width];
		for(int j = 0; j < width; j++) {
			field[i][j] = nullptr;
		}
	}

	// Seed the random number generator
	srand(time(0));

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
			Veggie chosenVeggie = veggies[index];

			// Create a new Veggie object and add it to the field
			field[y][x] = new Veggie(chosenVeggie.getName(), chosenVeggie.getSymbol(), chosenVeggie.getPoints());

			// Decrease the number of remaining Veggies
			numberOfVeggies--;
		}
	}

	file.close();
}

void GameEngine::initCaptain(){
	// Create a new Captain object
	// Generate random coordinates for the Captain

	srand(time(0));

	int x = rand() % width;
	int y = rand() % height;

	// Check if the location is occupied
	while (field[y][x] != nullptr) {
		// Choose a new random location
		x = rand() % width;
		y = rand() % height;
	}

	// Create a new Captain object and add it to the field
	field[y][x] = new Captain(x, y);
}


void GameEngine::spawnRabbits(){
	if (rabbits.size() < MAXNUMBEROFRABBITS) {

		// Seed the random number generator
		srand(time(0));

		int numberOfRabbits = MAXNUMBEROFRABBITS - rabbits.size();
		while (numberOfRabbits > 0) {
			// Generate random coordinates
			int x = rand() % width;
			int y = rand() % height;

			// Check if the location is occupied
			if (field[y][x] == nullptr) {
				// Create a new Rabbit object and add it to the field and vector of rabbits
				Rabbit newRabbit(x, y);
				field[y][x] = &newRabbit;
				rabbits.push_back(newRabbit);

				// Decrease the number of remaining rabbits
				numberOfRabbits--;
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

/* void GameEngine::intro(){

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

/*int GameEngine::getScore(){
	return score;
} */

int main(){
	GameEngine game;
	game.initializeGame();
	//game.initCaptain();
	//game.initializeGame();
	//game.printField();
	return 0;
}