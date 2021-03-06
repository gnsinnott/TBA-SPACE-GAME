#include <iostream>
#include"Enemy.h"
#include"time.h"
using namespace std;

Enemy::Enemy() {

}
//constructor
Enemy::Enemy(string n, string d, string t, int h, int att, int attr){
    name = n;
    description = d;
    type = t;
    hp = h;
    baseAttack = att;
    attackRange = attr;
    
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

/* This function takes a player object and and Enemy object and has the two objects battle. The Player attacks first. This the player 
attack reduces the enemy Hp (Health Points) below zero, the players wins and the player gains a point on their base attack rate. Next The Enemy attacks, if the enemy attack reduces the player health points 
below zero the player loses resulting in a loss of 1 year on their lifespan. 
inputs- player object, enemy object
return void
*/ 
Player Enemy::attackPlayer(Player player){
    while(player.getHp() > 0 && hp > 0)
    {
        int playerAttack = player.attack();
        cout << "You attack the " << name << " and deal " << playerAttack << " damage." << endl;
        hp = (hp - playerAttack); //Enemy HP = Enemy HP   - player attack 
        if(hp <= 0)
        {
            cout << "You have won this battle" << endl;
        } else {
            int enemyAttack = attack();
            cout << "The " << name << " attacks you and deals " << enemyAttack << " damage." << endl;
            player.setHp(player.getHp() - enemyAttack); // Player HP = Player HP  - enemy attack. 
        }
        if(player.getHp() <= 0)
        {
            int playerAge = player.getAge();
            player.setAge(playerAge + 1);
            cout << "You have lost this battle, it will take you one year to recover. \xF0\x9F\x98\xAB" << endl;
        }  
    }
    player.setHp(10); //Player HP returns to preset value
    hp = 10;
    return player;
}
/* This function takes a player object, SpaceShip object, and Enemy object and has the spaceship object and enemy object battle. The enemy attacks first. This the enemy
attack reduces the spaceship Hp (Health Points) below zero, the enemys wins and the player loses money (between ($0-$50)). Next The SpaceShip attacks, if the spaceship attack reduces the enemy health points 
below zero the player wins resulting in a gain of a random amount of money between ($1-$100). 
inputs- player object, enemy object
return void
*/ 
Player Enemy::attackPlayerShip(Player player, SpaceShip ship){

    while(ship.getHp() > 0 && hp > 0)
    {
        srand(time(0));
        int money = rand() % 10 * 100;
        hp = (hp - ship.attack());
        if(hp < 0)
        {
            cout << "You have won this battle and scavenged $"<< money <<" from the enemies ship." << "\xF0\x9F\x92\xB0" << endl;
            player.setMoney(player.getMoney() + money);  
        } 
        ship.setHp(ship.getHp() - attack());
        if(ship.getHp() < 0)
        {
            cout << "You have lost this battle and $" << money/2 << " was stolen from your ship" <<  endl;
            player.setMoney(player.getMoney() - money/2); 
            if (player.getMoney() < 0){
                player.setMoney(0);
            }
        }  
    }
    ship.setHp(10);
    hp = (10);
    return player;
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

int Enemy::attack() const{
    int offset;
    offset = rand() % (2*attackRange+1);
    return (baseAttack-attackRange+offset);
}