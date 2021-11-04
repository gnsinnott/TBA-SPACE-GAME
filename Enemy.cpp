#include <iostream>
#include"Enemy.h"
#include"time.h"
using namespace std;

Enemy::Enemy() {

}
Enemy::Enemy(string n, string d, string t, int h, int att, int attr, int def){
    name = n;
    description = d;
    type = t;
    hp = h;
    baseAttack = att;
    attackRange = attr;
    defense = def;
}
void Enemy::setName(string n){
    name = n;
}
void Enemy::setDescription(string d){
    description = d;
}
void Enemy::setType(string t){
    type = t;
}
void Enemy::setHp(int h){
    hp = h;
}
void Enemy::setBaseAttack(int a){
    baseAttack = a;
}
void Enemy::setAttackRange(int r){
    attackRange = r;
}
void Enemy::setDefense(int d){
    defense = d;
}

string Enemy::getName() const{
    return name;
}
string Enemy::getDescription() const{
    return description;
}
string Enemy::getType() const{
    return type;
}
int Enemy::getHp() const{
    return hp;
}
int Enemy::getbaseAttack() const{
    return baseAttack;
}
int Enemy::getAttackRange() const{
    return attackRange;
}
int Enemy::getDefense() const{
    return defense;
}
int Enemy::attack() const{
    int offset;
    srand(time(NULL));
    offset = rand() % attackRange;
    return (baseAttack-attackRange+offset);
}