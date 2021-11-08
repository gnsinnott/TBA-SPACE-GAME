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
    string location;
    string nexLoc;
    Map map = Map();
    do {
        map.setFile(filename);
        map.generateMap(filename);
        map.printMap();
        map.printLegend();
        cout << "What map would you like to see?" << endl;
        cin >> location;
        for (int i = 0; i < map.getLocationCount(); i++){
            if (map.getLocation(i).getMapKey() == location[0]){
                filename = map.getLocation(i).getMapFile();
            }
        }
    }
    while(location != "Q");
    return 0;
}