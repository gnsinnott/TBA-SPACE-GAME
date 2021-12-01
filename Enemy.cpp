#include <iostream>
#include"Enemy.h"
#include"time.h"
using namespace std;

Enemy::Enemy() {

}
//constructor
Enemy::Enemy(string n, string d, string t, int h, int att, int attr, int def){
    name = n;
    description = d;
    type = t;
    hp = h;
    baseAttack = att;
    attackRange = attr;
    defense = def;
}
//setter
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

/* This function takes a player object and and Enemy object and has the two objects battle. The Player attacks first. This the player 
attack reduces the enemy Hp (Health Points) below zero, the players wins and the player gains a point on their base attack rate. Next The Enemy attacks, if the enemy attack reduces the player health points 
below zero the player loses resulting in a loss of 1 year on their lifespan. 
inputs- player object, enemy object
return void
*/ 
Player Enemy::attackPlayer(Player player){
    while(player.getHp() > 0 && hp > 0)
    {
        hp = (hp - player.attack() + defense); //Enemy HP = Enemy HP  + enemy defense - player attack 
        if(hp <= 0)
        {
            int playerBaseAttack = player.getbaseAttack();
            player.setBaseAttack(playerBaseAttack ++);
            cout << "You have won this battle" << endl;
            return player;
        } 
        player.setHp(player.getHp() - attack() + player.getDefense()); // Player HP = Player HP + player defense - enemy attack. 
        if(player.getHp() <= 0)
        {
            int playerAge = player.getAge();
            player.setAge(playerAge ++);
            cout << "You have lost this battle, it will take you one year to recover." << endl;
            return player;
        }  
    }
    player.setHp(20); //Player HP returns to preset value
    return player;
}
/* This function takes a player object, SpaceShip object, and Enemy object and has the spaceship object and enemy object battle. The enemy attacks first. This the enemy
attack reduces the spaceship Hp (Health Points) below zero, the enemys wins and the player loses money (between ($0-$50)). Next The SpaceShip attacks, if the spaceship attack reduces the enemy health points 
below zero the player wins resulting in a gain of a random amount of money between ($1-$100). 
inputs- player object, enemy object
return void
*/ 
bool Enemy::attackPlayerShip(Player player, SpaceShip ship){


    while(ship.getHp() > 0 && hp > 0)
    {
    srand(time(0));
    int money = rand();
    hp = (hp - ship.attack() + defense);
    if(hp < 0)
    {
        cout << "You have won this battle and scavenged $"<< money <<" from the enemies ship." << endl;
        player.setMoney(player.getMoney() + money);
        return true;
    } 
    ship.setHp(ship.getHp() - attack() + ship.getDefense());
    if(ship.getHp() < 0)
    {
        cout << "You have lost this battle and $" << money/2 << " was stolen from your ship" <<  endl;
        player.setMoney(player.getMoney() - money/2);
        return false;
    }  
    }
    ship.setHp(20);
    return false;
}

//getter
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
    offset = rand() % (2*attackRange+1);
    return (baseAttack-attackRange+offset);
}