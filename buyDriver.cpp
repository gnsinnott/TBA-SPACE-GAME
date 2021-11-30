//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3  
#include <iostream>
#include "Player.h"

using namespace std;
/* This function takes a player object a item name and a price. If the player has enough money to buy the item the players money is reduced by
the price of the item and the functions returns true. If the player Does not have enough money to buy the item the function returns false and the 
players money is unchanged. 
*/ 
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

int main()
{
    Player player1;
    player1.setMoney(100);
    string item = "soap";
    int price = 1000;
    int value = buy(item, price, player1);
return 0;
}