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
    SpaceShip(string n, int f, int g, int hp, int ba, int ar);
    
    //setters
    void setName(string n); 
    void setFuel(int f);
    void setGasMileage(int g);
    void setHp(int hp);
    void setBaseAttack(int attack);
    void setAttackRange(int range); // Damage = baseAttack +- numbers in range
    //getters
    string getName(); 
    int getFuel();
    int getGasMileage();
    int getHp() const;
    int getbaseAttack() const;
    int getAttackRange() const;
    int attack() const;
    void displayStats();

    private:
    string name;
    int fuel;
    int gasMileage;
    int hp;
    int baseAttack;
    int attackRange;
    

};
#endif