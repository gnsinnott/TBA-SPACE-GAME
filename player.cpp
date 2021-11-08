//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112 - Maria Stull
//Project 3 
#include <iostream>
#include "Player.h"

using namespace std;

//constructor
Player::Player()
{
name = "";
startingAge = 0;
age = startingAge;
money = 0;
}
Player::Player(string n, int sa)
{
name = "";
startingAge = sa;
age = sa;
money = sa*100;
}

//setters
void Player::setName(string n)
{
name = n;
} 
void Player::setStartingAge(int sa)
{
startingAge = sa;
}
void Player::setMoney(int m)
{
    money = m;
}

//getters
string Player::getName()
{
return name;
} 
int Player::getStartingAge()
{
return startingAge;
}
int Player::getAge()
{
return age;
}
int Player::getMoney()
{
return money;
}