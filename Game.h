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
    void newGame();

    // accessors/getters
    void mainMenu();
    int printMenu(std::string t, std::string c[], int s);
    void newLocation(Location l);
    void play();

    private:
    Location youAreHere;
    Player player;
    SpaceShip ship;
};
#endif