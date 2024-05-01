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
	file >> height >> width;

	// Create 2D dynamic array of FieldInhabitant pointers
	
	FieldInhabitant*** field = new FieldInhabitant**[height];
	for(int i = 0; i < height; i++) {
		field[i] = new FieldInhabitant*[width];
		for(int j = 0; j < width; j++) {
			field[i][j] = nullptr;
		}
	}

	// Read remaining lines in the file to create Veggie objects
	string line;
	getline(file, line); // Skip the first line (header)
	while (getline(file, line)) {
		// Parse the line and create Veggie object
		// Add Veggie object to vector of possible vegetables
	}

	file.close();
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

