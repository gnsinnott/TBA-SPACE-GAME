//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3  
#ifndef LOCATION_H
#define LOCATION_H

#include<string>

class Location {

    public:

    // constructors
    Location(); // Default Constructor

    // mutators/setters
    void setName(std::string n);
    void setDescription(std::string d);
    void setMapFile(std::string f);
    void setDiscovered(bool d);
    void setShopStatus(bool s);
    void setCombatStatus(bool c);
    void generateLocation(std::string);
    void setCoordinates(int x, int y);
    void setMapKey(char c);
    void setExploredStatus(bool);

    // accessors/getters
    std::string getName() const;
    std::string getDescription() const;
    bool getDiscoveryStatus() const;
    int getXLoc() const;
    int getYLoc() const;
    char getMapKey() const;
    std::string getMapFile() const;
    bool getExploredStatus() const;

    private:
    std::string name;
    std::string description;
    char mapKey;
    std::string mapFile;
    bool discovered;
    bool shop;
    bool combat;
    int xLoc;
    int yLoc;
    bool explored;
    std::string items[5];
    std::string enemies[5];
    std::string events[5];
};

#endif