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
        if (game.getCurrentLocation().getMapFile() == "Planet"){ // When on a planet
            string planetChoices[] = {"Explore", "Shop", "Work", "Check Stats", "Return to Space", "Help"};
            choice = game.printMenu("Planet Options", planetChoices, 7);
            switch (choice)
            {
            case 6:
                cout << "Here is an explanation of what you can do on a planet" << endl;
                cout << "Explore: You explore the current planet and you may get the opportunity to gather information such as new planet locations." << endl;
                cout << "Shop: Go to a local shop and spend your money to purchase upgrades to your ship." << endl;
                cout << "Work: Exchange years of your life in exchange for money." << endl;
                cout << "Check Stats: View you and your ships current statistics" << endl;
                cout << "Return to Space: Self explanatory, return to your ship and go back into space." << endl;
                cout << "Help: Um... I'm sure you can figure out what this does." << endl;
                break;
            
            default:
                break;
            }
        }
        else {
            string spaceChoices[] = {"Travel", "Check Stats", "Option 3", "Option 4", "option 5",  "Quit"};
            choice = game.printMenu("Space Options", spaceChoices, 6);
            cout << "You chose to " << spaceChoices[choice] << " good luck!" << endl;
            switch (choice)
            {
            case 0: { // Player wants to travel on map
                bool validLocation = false;
                string destination;
                loadMap(map); // Prints current map and legend
                do {
                    cout << "Where would you like to go?" << endl << "You can enter a location legend key or a custom coordinate. (i.e. A2)" << endl;
                    getline(cin,destination); // Get desired travel destination
                    int fuel[] = {game.getShip().getFuel()}; // Assign current fuel to array variable
                    int travelSuccess = map.travelTo(destination, fuel); // Gets back result of travel and array of fuel is passed by reference so we can update ship fuel after travel
                    if (travelSuccess == 100){ // Travel to map destination if travel to returns 100, (space on current map)
                        game.ship.setFuel(fuel[0]); // Update ship fuel
                        validLocation = true; // Set valid location to true to exit loop
                        loadMap(map); // Print map and legend
                    }
                    if (travelSuccess >= 0 && travelSuccess != 100){ // If travel to returns an integer not 0 or 100 this means they are going to a known destination
                        game.ship.setFuel(fuel[0]-10); // Reduce fuel by 10
                        game.findLocation(map.getLocation(travelSuccess).getName()); // Get new location name
                        map = game.getCurrentMap(); // Assign new map
                        validLocation = true; // Set valid location to true to exit loop
                        cout << map.getName() << endl; // Print new map name
                        loadMap(map); // Print map and legend
                    }   
                }
                while(!validLocation); // Loop until new valid location is set
                break;
            }
            case 1: { // Show player stats
                game.getPlayer().displayStats(); // Print player stats
                game.getShip().displayStats(); // Print ship stats
            }
            case 2: { // Option 3

            }
            case 3: { // Option 4

            }
            case 4: { // Option 5

            }
            case 5: { // Quit game
                // Record player score
            }
            default:
                break;
            }
        }
    }
    while(true);
    return 0;
}