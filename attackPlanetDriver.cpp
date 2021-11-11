//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3 
#include <iostream>
#include "spaceShip.h"
#include "Enemy.h"
#include "Player.h"

using namespace std;

void attackPlayer(Player player, Enemy enemy)
{
while(player.getHp() > 0 && enemy.getHp() > 0)
{
   enemy.setHp(enemy.getHp() - player.attack());
   if(enemy.getHp() < 0)
   {
    player.setBaseAttack(player.getbaseAttack() ++);
    cout << "You have won this battle" << endl;
    return;
   } 
   player.setHp(player.getHp() - enemy.attack());
   if(player.getHp() < 0)
   {
    player.setAge(player.getAge() ++);
    cout << "You have lost this battle" << endl;

    return;
   }  
}
}
void attackPlayer(Player player, Enemy enemy, SpaceShip ship)
{
while(player.getHp() > 0 && enemy.getHp() > 0)
{
   enemy.setHp(enemy.getHp() - player.attack());
   if(enemy.getHp() < 0)
   {
    player.setBaseAttack(player.getbaseAttack() ++);
    cout << "You have won this battle" << endl;
    return;
   } 
   player.setHp(player.getHp() - enemy.attack());
   if(player.getHp() < 0)
   {
    player.setAge(player.getAge() ++);
    cout << "You have lost this battle" << endl;

    return;
   }  
}
}

