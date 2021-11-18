//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3 
#include <iostream>
#include "spaceShip.h"

using namespace std;
//constructors
SpaceShip::SpaceShip(){
    name = "";
    fuel = 0;
    gasMileage = 0;
    hp = 0;
    baseAttack = 0;
    attackRange = 0;
    defense = 0;
    
}
SpaceShip::SpaceShip(string n, int f, int g, int hp, int ba, int ar, int d){
    name = n;
    fuel = f;
    gasMileage = g;
    hp = hp;
    baseAttack = ba;
    attackRange = ar;
    defense = d;   
}
//setters
void SpaceShip::setName(string n){
    name = n; 
} 
void SpaceShip::setFuel(int f){
    fuel = f;
}
void SpaceShip::setGasMileage(int g){
    gasMileage = g;
}
void SpaceShip::setHp(int h){
    hp = h;
}
void SpaceShip::setBaseAttack(int a){
    baseAttack = a;
}
void SpaceShip::setAttackRange(int r){
    attackRange = r;
}
void SpaceShip::setDefense(int d){
    defense = d;
}
    
//getters
string SpaceShip::getName(){
    return name;
}
int SpaceShip::getFuel(){
    return fuel;
}
int SpaceShip::getGasMileage(){
    return gasMileage;
}
int SpaceShip::getHp() const{
return hp;
}
int SpaceShip::getbaseAttack() const{
    return baseAttack;
}
int SpaceShip::getAttackRange() const{
    return attackRange;
}
int SpaceShip::getDefense() const{
    return defense;
}
// this function generates the damage points of an attaks randomly based on Damage = baseAttack +- numbers in attack range
int SpaceShip::attack() const{
    int offset;
    offset = rand() % (2*attackRange+1);
    return (baseAttack-attackRange+offset);
}
void SpaceShip::displayStats(){
     cout << name << ":" << endl;
     cout << "Ship Fuel (gallons): " << fuel << endl;
     cout << "Ship Base Attack: " << baseAttack << endl;
 }

