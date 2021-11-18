//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3  
#ifndef MAP_H
#define MAP_H

#include "Location.h"
#include<string>

class Map {

    public:

    // constructors
    Map(); // Default Constructor
    Map(std::string n, std::string t, std::string f, int w, int h, bool r); // Paramaterized constructor

    // mutators/setters
    void setName(std::string n);
    void setType(std::string t);
    void setFile(std::string f);
    void setSize(int w, int h);
    void setDescription(std::string d);
    void setRandom(bool r);
    void generateMap();
    bool setPlayerLoc(int x, int y);
    void setLocationCount(int c);
    void setLocation(int i, Location location);
    int travelTo(std::string destination, int f);
    int calcFuelCost(int current[2], int next[2]);
    void randomPlayerLoc();


    // accessors/getters
    std::string getName() const;
    std::string getType() const;
    int getWidth() const;
    int getHeight() const;
    bool isRandom() const;
    std::string generateMap() const;
    void printMap() const;
    int getLocationCount() const;
    void printLegend(bool p) const;
    Location getLocation(int i) const;

    private:
    std::string name;
    std::string description;
    std::string type;
    std::string filename;
    int width;
    int height;
    bool random;
    char filler;
    std::string display[20];
    int locationCount;
    Location locations[5];
    int playerLoc[2] = {0,0}; // x y location of player
};

#endif