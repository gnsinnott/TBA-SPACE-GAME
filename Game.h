#ifndef GAME_H
#define GAME_H

#include"Player.h"
#include"spaceShip.h"
#include"Map.h"
#include"Location.h"
#include"Enemy.h"
#include<string>

class Game {

    public:

    // constructors
    Game(); // Default constructor
    Game(std::string n, Location l); // Paramaterized Constructor

    // mutators/setters
    void newGame(std::string n, std::string s);

    // accessors/getters
    void mainMenu();
    void printMenu(std::string t, std::string c[], int s);
    void newLocation(Location l);

    private:
    std::string playerName;
    Location youAreHere;
    Player player;
    SpaceShip ship;
};

#endif