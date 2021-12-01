//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112 - Maria Stull
//Project 3 
#include <iostream>
#include <string>
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
bool Player::buy(string item, int price)
{
    if(price > money)
    { 
       cout << "You have $ " << money << "." << endl;
       cout << "You do not have enough money to buy " << item << " \xF0\x9F\x98\x96." << endl;
       return false;
    }
    else
    {
        cout << "You bought " << item << "." << endl;
        money = (money - price);
        cout << "You have $ " << money << "." << endl;
        return true;  
    }
}
void Player::setNumPlanets(int np){
    numPlanets = np;
}
// Function for player to work and earn credits in exchange for years of their life
void Player::work(){ 
    string input;
    int creditsEarned;
    bool validInput = false;
    int years;
    do {
        years = 0;
        cout << "How long would you like to work for?" << endl << "For each year you work you will earn " << income << " credits." << endl;
        getline(cin, input);
            try // Try to convert string to integer
            {
                years = stoi(input);
                if (years < 0){ // Verify entry is positive integer
                    cout << "You can't work for negative years, we don't have that technology yet" << endl;
                }
                else if(years > 100-age){ // If player will be over 100 by the time they finish working
                    cout << "You don't have that many years left until retirement." << endl << "You are " << age << " years old and you will retire when you reach 100" << endl;
                }
                else {
                    validInput = true;
                }
            }
            catch(const std::invalid_argument& e) // Catch error if string cannot become an integer
            {
                cout << "Invalid input." << endl;
            }
    } while(!validInput); // Loop until valid number that won't put player over 100 is entered
    creditsEarned = years * income; // Calculate earnings
    money = money + creditsEarned; // Increase player money
    age = age + years;
    cout << "You worked for " << years << " years and earned " << creditsEarned << " credits" << endl;
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
 void Player::displayStats()
 {
     cout << name << ":" << endl;
     cout << "Player Age: " << age << endl;
     cout << "Player Money: $" << money << endl;
     cout << "Player Base Attack: " << baseAttack << endl;
 }
 int Player::getNumPlanets(){
 return numPlanets;
 }
