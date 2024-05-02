/* Author: Dev Shah
 Date: 4/25/24
 Description: The program defines Captain class.*/

#include "Captain.h"
#include "Veggie.h"
#include <iostream>
#include <string>

Captain::Captain(int x, int y) : Creature(x, y, "V") {
 }

    vector<Veggie*> Captain::getCaptainVegs()
        {return veggies;}
   void Captain::addVeggie(Veggie* veg){
        veggies.push_back(veg);
    };