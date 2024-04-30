/* Author: Dev Shah
 Date: 4/25/24
 Description: The program defines Captain class.*/

#include "Captain.h"

Captain::Captain(int x, int y) : Creature(x, y, string "V") {
 }

    vector<Veggie*> Captain::getCaptainVegs()
        {return VegObs;}
   void Captain::addVeggie(Veggie* veg){
        VegObs.push_back(veg);
    };