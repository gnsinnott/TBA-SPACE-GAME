//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3  
#include"Location.h"
#include"Map.h"
#include<iostream>
#include<fstream>

using namespace std;

Location::Location(){

}
// Setters
void Location::setName(string n){
    name = n;
}
void Location::setDescription(string d){
    description = d;
}
void Location::setMapFile(string f){
    mapFile = f;
}
void Location::setDiscovered(bool d){
    discovered = d;
}
void Location::setCoordinates(int x, int y){
    xLoc = x;
    yLoc = y;
}
// Generate location from text file
void Location::generateLocation(string filename){
    ifstream locationFile;
    string line;
    locationFile.open("locations/" + filename); // Open file for location
    if (locationFile.is_open()){ // Check if file can be opened, sets location variables from file lines
        // Go through file line by line assigning to location variables in specified order
        getline(locationFile, name);
        getline(locationFile, description);
        getline(locationFile, mapFile);
        getline(locationFile, line);
        if (line == "true") {
            discovered = true;
        } else {
            discovered = false;
        }
        getline(locationFile, line);
        xLoc = stoi(line);
        getline(locationFile, line);
        yLoc = stoi(line);
        getline(locationFile, line);
        mapKey = line[0];
    }
    explored = false;
}

void Location::setExploredStatus(bool e){
    explored = e;
}
// Getters
string Location::getName() const{
    return name;
}
string Location::getDescription() const{
    return description;
}
bool Location::getDiscoveryStatus() const{
    return discovered;
}
int Location::getXLoc() const{
    return xLoc;
}
int Location::getYLoc() const{
    return yLoc;
}
char Location::getMapKey() const{
    return mapKey;
}
string Location::getMapFile() const{
    return mapFile;
}
bool Location::getExploredStatus() const{
    return explored;
}