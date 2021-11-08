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
    string filename = "cs.txt";
    string destination;
    string nexLoc;
    Map map = Map();
    bool playerMarked;
    int column = 0;
    int row = 0;
    bool validLocation = false;
    map.setFile(filename);
    map.generateMap(filename);
    playerMarked = map.setPlayerLoc(column,row);
    do {
        map.printMap();
        map.printLegend(playerMarked);
        do {
            cout << "What map would you like to go?" << endl << "You can enter a location legend key or a custom coordinate. (i.e. A2)" << endl;
            cin >> destination;
            if (1 == map.travelTo(destination)){
                validLocation = true;

            }
        }
        while(!validLocation);

    }
    while(destination != "Q");
    return 0;
}