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
    Game game; // create game variable
    int choice; 
    if (game.generateLocations() == -1){ // Generate locations in game, displays error if generate fails
        cout << "Error loading locations" << endl;
        return 0;
    }
    if (game.generateMaps() == -1){ // Generate maps in game, displays error if generate fails
        cout << "Error loading locations" << endl;
        return 0;
    }
    game.newGame(); // Start new game, get's player and ship info
    // Need to implement gameplay loop here
    // Simple menu choice loop test
    string title = "Final Frontier";
    string choices[] = {"Run", "Hide", "Explore"};
    choice = game.printMenu(title, choices, 3);
    cout << "You chose to " << choices[choice] << " good luck!" << endl;
    return 0;
}