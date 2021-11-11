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
    int choice; 
    game.newGame();
    string title = "Final Frontier";
    string choices[] = {"Run", "Hide", "Explore"};
    choice = game.printMenu(title, choices, 3);
    cout << "You chose to " << choices[choice] << " good luck!" << endl;
    return 0;
}