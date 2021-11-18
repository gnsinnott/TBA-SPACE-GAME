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
    hp = 10;
    baseAttack = 3;
    attackRange = 1;
    defense = 3;
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
    age = sa;
    money = sa * 100;
    income = sa * 10;
}
void Player::setMoney(int m)
{
    money = m;
}
void Player::setIncome(int a)
{
    income = a * 10;
}
void Player::setHp(int h){
    hp = h;
}
void Player::setBaseAttack(int a){
    baseAttack = a;
}
void Player::setAttackRange(int r){
    attackRange = r;
}
void Player::setDefense(int d){
    defense = d;
}
void Player::setAge(int a)
{
    age = a;
}
bool buy(string item, int price, Player player)
{
    int playerMoney = player.getMoney();
    if(price > playerMoney)
    { 
       cout << "You have $ " << player.getMoney() << "." << endl;
       cout << "You do not have enough money to buy " << item << " \xF0\x9F\x98\x96." << endl;
       return false;
    }
    else
    {
        cout << "You bought " << item << "." << endl;
        player.setMoney(playerMoney - price);
        cout << "You have $ " << player.getMoney() << "." << endl;
        return true;  
    }
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
int Player::getIncome(){
    return income;
}
int Player::getHp()
{
    return hp;
}
int Player::getbaseAttack(){
    return baseAttack;
}
int Player::getAttackRange(){
    return attackRange;
}
int Player::getDefense(){
    return defense;
}
// this function generates the damage points of an attaks randomly based on Damage = baseAttack +- numbers in attack range
int Player::attack(){
    int offset;
    offset = rand() % (2*attackRange+1);
    return (baseAttack-attackRange+offset);
}
 void Player::displayStats(Player player)
 {
     cout << player.getName() << ":" << endl;
     cout << "Player Age: " << player.getAge() << endl;
     cout << "Player Money: $" << player.getMoney() << endl;
     cout << "Player Base Attack: " << player.getbaseAttack() << endl;
 }