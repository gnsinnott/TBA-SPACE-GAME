//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3  

#ifndef PLAYER_H //preprocessor directives
#define PLAYER_H
#include <string>

using namespace std;

class Player
{
    public:
    //constructor
    Player();
    Player(string n, int sa);
    
    //setters
    void setName(string n); 
    void setStartingAge(int sa);
    void setMoney(int m);
    
    //getters
    string getName(); 
    int getStartingAge();
    int getAge();
    int getMoney();

    private:
    string name;
    int startingAge;
    int age;
    int money;
};
#endif