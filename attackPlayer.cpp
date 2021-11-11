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

void attackPlayer(Player player, Enemy enemy)
{
while(player.getHp() > 0 && enemy.getHp() > 0)
{
   enemy.setHp(enemy.getHp() - player.attack() + enemy.getDefense());
   if(enemy.getHp() < 0)
   {
    int playerBaseAttack = player.getbaseAttack();
    player.setBaseAttack(playerBaseAttack ++);
    cout << "You have won this battle" << endl;
    return;
   } 
   player.setHp(player.getHp() - enemy.attack() + player.getDefense());
   if(player.getHp() < 0)
   {
    int playerAge = player.getAge();
    player.setAge(playerAge ++);
    cout << "You have lost this battle, it will take you one year to recover." << endl;
    return;
   }  
}
player.setHp(20);

}
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

Enemy enemy1;
enemy1.setHp(18);
enemy1.setBaseAttack(6);
enemy1.setDefense(1);

attackPlayer(player1, enemy1);



}

