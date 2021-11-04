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
    SpaceShip(string n, int fuel, int gasMiliage);
    
    //setters
    void setName(string n); 
    void setFuel(int f);
    void setGasMiliage(int g);
    
    //getters
    string getName(); 
    int getFuel();
    int setGasMiliage();

    private:
    string name;
    int fuel;
    int gasMilage;
};
#endif