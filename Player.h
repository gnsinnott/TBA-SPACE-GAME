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
    void setHp(int hp);
    void setAge(int a);
    void setBaseAttack(int attack);
    void setAttackRange(int range); // Damage = baseAttack +- numbers in range
    void setDefense(int defense);
    bool buy(string item, int price, Player player);
    
    
    //getters
    string getName(); 
    int getStartingAge();
    int getAge();
    int getMoney();
    int getHp() const;
    int getbaseAttack();
    int getAttackRange() const;
    int getDefense() const;
    int attack() const;


    private:
    string name;
    int startingAge;
    int age;
    int money;
    int hp;
    int baseAttack;
    int attackRange;
    int defense;
};
#endif