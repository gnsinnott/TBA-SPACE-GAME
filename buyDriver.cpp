//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3  
#include <iostream>
#include "Player.h"

using namespace std;

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