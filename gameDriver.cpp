#include"Game.h"
#include"Player.h"
#include"spaceShip.h"
#include"Map.h"
#include"Location.h"
#include"Enemy.h"
#include<iostream>
#include<string>

using namespace std;

int main(){
    Game game;
    string title = "Final Frontier";
    string choices[] = {"Run", "Hide", "Explore"};
    game.printMenu(title, choices, 3);
    return 0;
}