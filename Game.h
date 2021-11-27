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
    void setShipFuel(int f);


    // accessors/getters
    SpaceShip getShip();
    Player getPlayer();
    Location getCurrentLocation();
    Map getCurrentMap();
    void findLocation(string n);
    void loadLocation();
    void mainMenu();
    int printMenu(std::string t, std::string c[], int s);
    void newLocation(string l);
    void play();
    SpaceShip ship;
    Player player;

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