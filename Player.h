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
    Player(string n, const int startingAge);
    
    //setters
    void setName(string n); 
    void setStartingAge(string sa);
    
    //getters
    string getName() const; 
    int getStartingAge() const;
    int getAge() const;
    int getMoney();

    private:
    string name;
    const int startingAge;
    int age;
    int money;
};
#endif