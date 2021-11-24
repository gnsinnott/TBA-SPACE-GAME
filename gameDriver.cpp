#include"Game.h"
#include"Player.h"
#include"spaceShip.h"
#include"Map.h"
#include"Location.h"
#include"Enemy.h"
#include<iostream>
#include<string>

using namespace std;

void loadMap(Map map){
    map.printMap();
    map.printLegend(map.getPlayerMarked());
}

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
    Map map = game.getCurrentMap();
    loadMap(map);
    do{
        // Need to implement gameplay loop here
        // Simple menu choice loop test
        // string destination = "FA";
        // game.getCurrentMap().travelTo(destination, game.getShip().getFuel());
        string title = "Final Frontier";
        string choices[] = {"Travel", "Check Stats"};
        choice = game.printMenu(title, choices, 2);
        cout << "You chose to " << choices[choice] << " good luck!" << endl;
        if (choice == 0){
            bool validLocation = false;
            string destination;
            loadMap(map);
            do {
                cout << "Where would you like to go?" << endl << "You can enter a location legend key or a custom coordinate. (i.e. A2)" << endl;
                getline(cin,destination);
                int travelSuccess = map.travelTo(destination, 45);
                if (travelSuccess == 100){ // Travel to map destination if travel to returns 0, (space on current map)
                    validLocation = true;
                    loadMap(map);
                }
                if (travelSuccess >= 0 && travelSuccess != 100){
                    game.findLocation(map.getLocation(travelSuccess).getName());
                    map = game.getCurrentMap();
                    validLocation = true;
                    loadMap(map);
                }   
            }
            while(!validLocation);
        }
    else if(choice == 1){
        game.getPlayer().displayStats();
        game.getShip().displayStats();
    }
    } while(true);
    return 0;
}