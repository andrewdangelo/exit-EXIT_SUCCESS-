#include "GameEngine.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void GameEngine::initializeGame(){
	//initVeggies() called
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
    srand(time(0));

    int x, y;

    // Keep trying random positions until an empty one is found
    do {
        x = rand() % width;
        y = rand() % height;

    } while (field[y][x] != nullptr);  // Continue if the spot is not empty

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
				rabbits.push_back(&newRabbit);

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
	// TODO: add border

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
		switch (direction) {
			case 0: // Up
				if (y - 1 >= 0) {
					rabbits[i]->setY(y - 1);
				}
				break;
			case 1: // Down
				if (y + 1 < height) {
					rabbits[i]->setY(y + 1);
				}
				break;
			case 2: // Left
				if (x - 1 >= 0) {
					rabbits[i]->setX(x - 1);
				}
				break;
			case 3: // Right
				if (x + 1 < width) {
					rabbits[i]->setX(x + 1);
				}
				break;
			case 4: // Up-Left
				if (y - 1 >= 0 && x - 1 >= 0) {
					rabbits[i]->setY(y - 1);
					rabbits[i]->setX(x - 1);
				}
				break;
			case 5: // Up-Right
				if (y - 1 >= 0 && x + 1 < width) {
					rabbits[i]->setY(y - 1);
					rabbits[i]->setX(x + 1);
				}
				break;
			case 6: // Down-Left
				if (y + 1 < height && x - 1 >= 0) {
					rabbits[i]->setY(y + 1);
					rabbits[i]->setX(x - 1);
				}
				break;
			case 7: // Down-Right
				if (y + 1 < height && x + 1 < width) {
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
	if (timer==5 || timer==0)
    { spawnRabbits();}
    timer=timer+1;
}

void  GameEngine::moveCptHorizontal(int x)
{
    //storing the captain object in a variable
	Captain captainOBJ* =captain;
	//if captain moves to empty slot
    if(field[captainOBJ.getX()][captainOBJ.getY()+x]==nullptr)
    {
        captainOBJ.setY(captainOBJ.getY()+1);
        field[captainOBJ.getX()][captainOBJ.getY()]=nullptr;
        field[captainOBJ.getX()][captainOBJ.getY()+x]=captain;
    }
	//if captain moves to a veggie slot
    else if(dynamic_cast<Veggie*>(field[captainOBJ.getX()][captainOBJ.getY()+x])!=nullptr)
    {
        Veggie* ptr=dynamic_cast<Veggie*>(field[captainOBJ.getX()][captainOBJ.getY()+x]);
        captainOBJ.addVeggie(ptr);
        //storing the veggie object from its obtained pointer
		Veggie veg=*ptr;
        cout<<veg.getName()<<", a delicious vegetable, has been found"<<endl;
        score=score+ veg.getPoints();
         //set the Captain object’s previous location in the field to nullptr
		field[captainOBJ.getX()][captainOBJ.getY()]=nullptr;
         //Assign the Captain object to the new location in the field
		field[captainOBJ.getX()][captainOBJ.getY()+x]=captain;
    }
	//if captain moves to rabbit slot
     else if(dynamic_cast<Rabbit*>(field[captainOBJ.getX()][captainOBJ.getY()+x])!=nullptr)
    {
     //Update the Captain object’s appropriate member variable?
	// help here
        //Remove that particular Rabbit object from the vector of Rabbit pointers
		rabbits.pop_back();

        cout<<"A rabbit has been found."<<endl;
        score=score+ RABBITPOINTS;
        //set the Captain object’s previous location in the field to nullptr
		field[captainOBJ.getX()][captainOBJ.getY()]=nullptr;
        //Assign the Captain object to the new location in the field
		field[captainOBJ.getX()][captainOBJ.getY()+x]=captain;
    }

    else{}
    

    
}

void  GameEngine::moveCaptain()
{
    //storing field dimensions
    int f_rows=height;
    int f_cols=width;
	//storing the captain object in a variable
    Captain captainOBJ=*captain;
    char move;
    cout<<" Which direction to move the Captain?"<<endl;
    cin>>move;
	//for using lowercase...
    move=tolower(move);
	//switch case for moving according to user
    switch (move) {
        case 'w':

            if(captainOBJ.getX()+1 <= f_rows)
//{moveCptVertical(1);}
			cout << "Cannot move captain more upward." << endl;
            else
            cout << "Cannot move captain more upward." << endl;
            break;
        case 's':
            if(captainOBJ.getX()-1 >= 0)
			cout << "Cannot move captain more down." << endl;
           // {moveCptVertical(-1);} 
            else
            cout << "Cannot move captain more down." << endl;
            break;
        case 'a':
            if(captainOBJ.getY()-1 >= 0)
            {moveCptHorizontal(-1);} 
            else
            cout << "Cannot move captain more left." << endl;
            break;
        case 'd':
            if(captainOBJ.getY()+1 <= f_cols)
            {moveCptHorizontal(1);} 
            else
            cout << "Cannot move captain more right." << endl;
            break;
        default:
            cout << "Invalid move." << endl;
    }

}



int main(){
	GameEngine game;
	game.initializeGame();
	game.intro();
	/* int remainingVeggies;
	remainingVeggies= game.remainingVeggies();
	while (remainingVeggies!=0)

	{
		game.getScore();
		game.printField();
		game.moveRabbits();
		game.moveCaptain();
		remainingVeggies= game.remainingVeggies();
		// ?? Increment the timer using the appropriate GameEngine function  
	} */
	
	//game.initCaptain();
	//game.initializeGame();
	
	return 0;
}