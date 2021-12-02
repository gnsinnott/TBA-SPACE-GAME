//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112 - Maria Stull
//Project 3 
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

//constructor
Player::Player(){
    name = "";
    startingAge = 0;
    age = startingAge;
    money = 0;
    hp = 10;
    baseAttack = 3;
    attackRange = 1;
    
}
Player::Player(string n, int sa){
    name = "";
    startingAge = sa;
    age = sa;
    money = sa*100;
}

//setters
void Player::setName(string n){
    name = n;
} 
void Player::setStartingAge(int sa){
    startingAge = sa;
    age = sa;
    money = sa * 100;
    income = sa * 10;
}
void Player::setMoney(int m){
    money = m;
}
void Player::setIncome(int a){
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
void Player::setAge(int a){
    age = a;
}
void Player::setNumPlanets(int np){
    numPlanets = np;
}
// Function for player to work and earn credits in exchange for years of their life, takes no arguments and returns nothing
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
                    cout << "You can't work for negative years, we don't have that technology yet." << endl;
                }
                else if(years > 100-age){ // If player will be over 100 by the time they finish working
                    cout << "You don't have that many years left until retirement." << endl << "You are " << age << " years old and you will retire when you reach 100" << endl;
                }
                else { // Non negative and small enough number means input is valid
                    validInput = true;
                }
            }
            catch(const std::invalid_argument& e) // Catch error if string cannot become an integer
            {
                cout << "Invalid input." << endl;
            }
            catch (const std::out_of_range& e) // Catch error if number is too large
            {
                cout << "Invalid input." << endl;
            }
    } while(!validInput); // Loop until valid number that won't put player over 100 is entered
    creditsEarned = years * income; // Calculate earnings
    money = money + creditsEarned; // Increase player money
    age = age + years; // Increase player age
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

// this function generates the damage points of an attaks randomly based on Damage = baseAttack +- numbers in attack range
int Player::attack(){
    int offset;
    offset = rand() % (2*attackRange+1);
    return (max(baseAttack-attackRange+offset,0));
}
// Prints player stats
void Player::displayStats(){
    cout << name << ":" << endl;
    cout << "Player Age: " << age << endl;
    cout << "Player Money: $" << money << endl;
    cout << "Player Base Attack: " << baseAttack << endl;
}
// Returns number of planets player has discovered as int
int Player::getNumPlanets(){
    return numPlanets;
}
