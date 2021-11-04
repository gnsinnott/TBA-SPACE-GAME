//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3  

#ifndef ENEMY_H
#define ENEMY_H

#include<string>

class Enemy {

    public:

    // constructors
    Enemy(); // Default Constructor


    // mutators/setters
    void setName(std::string n);
    void setDescription(std::string d);
    void setType(std::string t);
    void setHp(int hp);
    void setBaseAttack(int attack);
    void setAttackRange(int range); // Damage = baseAttack +- numbers in range
    void setDefense(int defense);

    // accessors/getters
    std::string getName() const;
    std::string getDescription() const;
    std::string getType() const;
    int getHp() const;
    int getbaseAttack() const;
    int getAttackRange() const;
    int getDefense() const;
    int attack() const;

    private:
    std::string name;
    std::string description;
    std::string type; // ship or alien
    int hp;
    int baseAttack;
    int attackRange;
    int defense;

};

#endif