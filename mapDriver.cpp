//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3  
#include <iostream>
#include "Map.h"
#include "Location.h"
using namespace std;

int main(){
    cout << "\033[1;31m\xF0\x9F\x9A\x80\033[0m" << endl;
    string filename = "cs.txt"; // Map file to load
    string destination;
    string nexLoc;
    Map map = Map();
    bool playerMarked;
    int column = 0;
    int row = 0;
    bool validLocation = false;
    map.setFile(filename);
    map.generateMap();
    playerMarked = map.setPlayerLoc(column,row); // Mark player location and set bool to function return
    do {
        map.printMap();
        map.printLegend(playerMarked); // Print legend and pass bool if player is marked so it can be added to legend
        do {
            cout << "What map would you like to go?" << endl << "You can enter a location legend key or a custom coordinate. (i.e. A2)" << endl;
            cin >> destination; // Get destination from user
            if (1 == map.travelTo(destination)){ // Travel to map destination if travel to returns 1, (space on current map)
                validLocation = true;
            }
            if (int x = map.travelTo(destination) > 1){ // If travel to returns a new location
                filename = map.getLocation(x-1).getMapFile(); // Set filename to filename of location in location array on map
                map.setFile(filename);
                map.generateMap();
            }
        }
        while(!validLocation);
    }
    while(destination != "Q"); // Quit if user enters Q
    return 0;
}