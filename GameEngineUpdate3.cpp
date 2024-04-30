
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
        //need field max row and col
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
        Rabbit newrab(rabx,raby,"R");
        vectorofrabits<Rabbit*>.push_back(&newrab);
        field[rabx][raby]=&newrab;
    }
    
}

void moveCptHorizontal(int x)
{
    Captain captainOBJ=*Captainptr;
    if(field[captainOBJ.getx()][captainOBJ.gety()+x]==nullptr)
    {
        captainOBJ.sety(captainOBJ.gety()+1);
        field[captainOBJ.getx()][captainOBJ.gety()]=nullptr;
        field[captainOBJ.getx()][captainOBJ.gety()+x]=Captainptr;
    }
    else if(field[captainOBJ.getx()][captainOBJ.gety()+x]==Veggie*)
    {
        ptr=field[captainOBJ.getx()][captainOBJ.gety()+x];
        captainOBJ.addVeggie(ptr);
        Veggie veg=&ptr;
        cout<<veg.getname()<<", a delicious vegetable, has been found"<<endl;
        playerscore=playerscore+ veg.getpoints();
        field[captainOBJ.getx()][captainOBJ.gety()]=nullptr;
        field[captainOBJ.getx()][captainOBJ.gety()+x]=Captainptr;
    }
     else if(field[captainOBJ.getx()][captainOBJ.gety()+x]==Rabbit*)
    {
     //Update the Captain object’s appropriate member variable?
        //Remove that particular Rabbit object from the vector of Rabbit pointers
        cout<<"A rabbit has been found."<<endl;
        playerscore=playerscore+ RABBITPOINTS;
        field[captainOBJ.getx()][captainOBJ.gety()]=nullptr;
        field[captainOBJ.getx()][captainOBJ.gety()+x]=Captainptr;
    }

    else{}
    

    
}

void moveCaptain()
{
    //need field max row and col
    int f_rows=10;
    int f_cols=10;

    Captain captainOBJ=*Captainptr;
    char move;
    cout<<" Which direction to move the Captain?"<<endl;
    cin>>move;
    move=tolower(move);
    switch (move) {
        case 'w':

            if(captainOBJ.getx()+1 <= f_rows)
            {moveCptVertical(1);} // param
            else
            cout << "Cannot move captain more upward." << endl;
            break;
        case 's':
            if(captainOBJ.getx()-1 >= 0)
            {moveCptVertical(-1);} // param
            else
            cout << "Cannot move captain more down." << endl;
            break;
        case 'a':
            if(captainOBJ.gety()-1 >= 0)
            {moveCptHorizontal(-1);} 
            else
            cout << "Cannot move captain more left." << endl;
            break;
        case 'd':
            if(captainOBJ.gety()+1 <= f_cols)
            {moveCptHorizontal(1);} 
            else
            cout << "Cannot move captain more right." << endl;
            break;
        default:
            cout << "Invalid move." << endl;
    }

}