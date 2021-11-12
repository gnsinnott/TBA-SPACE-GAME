#ifndef GAME_H
#define GAME_H

#include"Player.h"
#include"spaceShip.h"
#include"Map.h"
#include"Location.h"
#include"Enemy.h"
#include<vector>
#include<string>

class Game {

    public:

    // constructors
    Game(); // Default constructor
    Game(std::string n, Location l); // Paramaterized Constructor

    // mutators/setters
    void newGame();
    void setLocation(Location l);
    int generateLocations();
    int generateMaps();


    // accessors/getters
    void mainMenu();
    int printMenu(std::string t, std::string c[], int s);
    void newLocation(string l);
    void play();

    private:
    const int size = 20;
    vector <Location> locations;
    vector <Map> maps;
    Location youAreHere;
    Player player;
    SpaceShip ship;
    Map map;
};
#endif