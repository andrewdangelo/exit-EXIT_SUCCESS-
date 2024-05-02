/* Author: Dev Shah
 Date: 4/25/24
 Description: The program makes Captain class.*/


#ifndef Captain_H
#define Captain_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Veggie.h"

using namespace std;
#include "Creature.h" 

class Captain : public Creature {
    private:
    vector<Veggie*> veggies;
    public:
    Captain(int x,int y);
    
    vector<Veggie*> getCaptainVegs();
    void addVeggie(Veggie* veg);
};

#endif 
