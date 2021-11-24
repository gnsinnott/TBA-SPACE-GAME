//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3 
#include <iostream>
#include "spaceShip.h"
#include "Enemy.h"
#include "Player.h"
#include <random>

using namespace std;
/* This function takes a player object and and Enemy object and has the two objects battle. The Player attacks first. This the player 
attack reduces the enemy Hp (Health Points) below zero, the players wins and the player gains a point on their base attack rate. Next The Enemy attacks, if the enemy attack reduces the player health points 
below zero the player loses resulting in a loss of 1 year on their lifespan. 
inputs- player object, enemy object
return void
*/ 
void attackPlayer(Player player, Enemy enemy)
{
while(player.getHp() > 0 && enemy.getHp() > 0)
{
   enemy.setHp(enemy.getHp() - player.attack() + enemy.getDefense()); //Enemy HP = Enmey HP  + enemy defense - player attack 
   if(enemy.getHp() <= 0)
   {
    int playerBaseAttack = player.getbaseAttack();
    player.setBaseAttack(playerBaseAttack ++);
    cout << "You have won this battle" << endl;
    return;
   } 
   player.setHp(player.getHp() - enemy.attack() + player.getDefense()); // Player HP = Player HP + player defense - enemy attack. 
   if(player.getHp() <= 0)
   {
    int playerAge = player.getAge();
    player.setAge(playerAge ++);
    cout << "You have lost this battle, it will take you one year to recover." << endl;
    return;
   }  
}
player.setHp(20); //Player HP returns to preset value

}
/* This function takes a player object, SpaceShip object, and Enemy object and has the spaceship object and enmey object battle. The enemy attacks first. This the enemy
attack reduces the spaceship Hp (Health Points) below zero, the enemys wins and the player loses money (between ($0-$50)). Next The SpaceShip attacks, if the spaceship attack reduces the enemy health points 
below zero the player wins resulting in a gain of a random amount of money between ($1-$100). 
inputs- player object, enemy object
return void
*/ 
void attackPlayer(Player player, Enemy enemy, SpaceShip ship)
{
while(ship.getHp() > 0 && enemy.getHp() > 0)
{
   srand(time(0));
   int money = rand();
   enemy.setHp(enemy.getHp() - ship.attack() + enemy.getDefense());
   if(enemy.getHp() < 0)
   {
    cout << "You have won this battle and scavanged $"<< money <<" from the enemies ship." << endl;
    player.setMoney(player.getMoney() + money);
    return;
   } 
   ship.setHp(ship.getHp() - enemy.attack() + ship.getDefense());
   if(ship.getHp() < 0)
   {
    cout << "You have lost this battle and $" << money/2 << " was stolen from your ship" <<  endl;
    player.setMoney(player.getMoney() - money/2);
    return;
   }  
}
ship.setHp(20);
}

int main()
{
Player player1;
player1.setName("player1");
player1.setHp(20);
player1.setBaseAttack(5);
player1.setDefense(0);
player1.setAttackRange(2);

Enemy enemy1;
enemy1.setHp(18);
enemy1.setBaseAttack(4);
enemy1.setDefense(1);
enemy1.setAttackRange(2);

SpaceShip spaceShip1; 
spaceShip1.setBaseAttack(5);
spaceShip1.setDefense(1);
spaceShip1.setAttackRange(2);


attackPlayer(player1, enemy1);
attackPlayer(player1,enemy1,spaceShip1);



}

