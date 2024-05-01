#include "GameEngine.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void GameEngine::initializeGame(){
	//initVeggies() called
	initVeggies();

	//initCaptain() called
	//initCaptain();
	score = 0;
	timer = 0;
}

void GameEngine::initVeggies(){
	string filename;
	ifstream file;

	// Prompt user for veggie file name
	cout << "Enter the name of the veggie file: ";
	cin >> filename;

	// Check if file exists
	file.open(filename);
	while (!file.is_open()) {
		cout << "File not found. Enter a valid veggie file name: ";
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
	//game.initializeGame();
	//game.printField();
	return 0;
}