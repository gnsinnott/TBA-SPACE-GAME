//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3  

#ifndef SPACESHIP_H //preprocessor directives
#define SPACESHIP_H
#include <string>

using namespace std;

class SpaceShip
{
    public:
    //constructor
    SpaceShip();
    SpaceShip(string n, int f, int g, int a, int d);
    
    //setters
    void setName(string n); 
    void setFuel(int f);
    void setGasMileage(int g);
    void setAttack(int a);
    void setDefense(int d);
    
    //getters
    string getName(); 
    int getFuel();
    int getGasMileage();
    int getAttack();
    int getDefense();

    private:
    string name;
    int fuel;
    int gasMileage;
    int attackPoints;
    int defensePoints;
};
#endif