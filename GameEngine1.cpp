
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
#include "Captain.h"


global NUMBEROFRABBITS;
srand(0);
void initCaptain()
{

// pointer object type for field
int field[10][10],test;
int captain_x,captain_y;
int f_rows=10;
int f_cols=10;

captain_x= rand() % f_rows;
captain_y= rand() % f_cols;
test=field[captain_x][captain_y];

while (test.getsymbol())
{
    captain_x= rand() % f_rows;
captain_y= rand() % f_cols;
test=field[captain_x][captain_y];

}

Captain newCap(captain_x,captain_y,"V");
field[rabx][raby]=&newCap;
Captainptr=&newCap;
}

void initRabbits()
{
    for (int i = 0; i < NUMBEROFRABBITS; i++)
    {
        // pointer object type for field
        int field[10][10],test;
        int rabx,raby;
        int f_rows=10;
        int f_cols=10;

        rabx= rand() % f_rows;
        raby= rand() % f_cols;
        test=field[rabx][raby];

        while (test.getsymbol())
        {
            rabx= rand() % f_rows;
            raby= rand() % f_cols;
            test=field[rabx][raby];
        }
        Rabit newrab(rabx,raby,"R");
        vectorofrabits<Rabbit*>.push_back(&newrab);
        field[rabx][raby]=&newrab;
    }
    
}

void moveCptHorizontal()
{
    captainOBJ=*Captainptr;
    if(field[captainOBJ.getx()][captainOBJ.gety()])

}

void moveCaptain()
{
    char move;
    cout<<" Which direction to move the Captain?"<<endl;
    cin>>move;

}