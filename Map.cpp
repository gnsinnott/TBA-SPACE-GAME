//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3  
#include"Map.h"
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

// constructors
Map::Map(){
    name = "Unknown";
    type = "Planet";
    width = 5;
    height = 5;
    random = true;
}
// Paramaterized constructor
Map::Map(string n, string t, string f, int w, int h, bool r){
    name = n;
    type = t;
    filename = f;
    width = w;
    height = h;
    random = r;
}
// Set name of map
void Map::setName(string n){
    name = n;
}
// Set description of map
void Map::setDescription(string d){
    description = d;
}
// Set type of map
void Map::setType(string t){
    type = t;
}
// Set filename for map info
void Map::setFile(std::string f){
    filename = f;
    random = false;
}
// Set width and height of map
void Map::setSize(int w, int h){
    width = w;
    height = h;
}
// Set map status to random generation
void Map::setRandom(bool r){
    random = r;
}
// Set number of locations on map
void Map::setLocationCount(int c){
    locationCount = c;
}
// Add location to location array on map
void Map::setLocation(int i, Location location){
    locations[i] = location;
}
// Travel to destination on map, either Location key or coordinate
int Map::travelTo(string destination, int fuel[], int efficiency, int time[]){
    if (destination.size() == 1){ // If destination is location key
        for (int i = 0; i < locationCount; i++){ // Find key in location array
            if (getLocation(i).getMapKey() == destination[0]){
                //filename = getLocation(i).getMapFile(); // Send location to somewhere, not sure yet how to move between maps
                return i;
            }
        }
        cout << "Invalid destination" << endl;
            return -1;
    } else { // Get coordinates from destination 
        if (int(destination[0]) >= 65 && int(destination[0]) <= 90) { // Verify first character is a capital letter
            try { // Try and cast destination string to integers
                int tempColumn = int(destination[0])-65; // Set temp column to first char
                int tempRow = stoi(destination.substr(1)); // Set temp row to remainding chracters in destination string
                // cout << "Column: " << tempColumn << endl << "Row: " << tempRow << endl;
                if (tempColumn < width && tempRow < height){ // Verify coordinates are in range of map
                    int next[] = {tempColumn, tempRow};
                    int distance = calcDistance(playerLoc, next);
                    time[0] = distance * 1;
                    int fuelCost = (distance*2) / efficiency; // Gets distance and divides by fuel efficiency
                    if (fuelCost <= fuel[0]){ // Verify enough fuel is left
                        fuel[0] = fuel[0] - fuelCost; // Update ships fuel
                        setPlayerLoc(tempColumn, tempRow); // Update player location
                        return 100;
                    } else {
                        cout << "Not enough fuel" << endl;
                        return -1;
                    }
                }
                else {
                    cout << "Entry out of bounds, try again." << endl;
                    return -1;
                }
            }catch (const std::invalid_argument& e) { // Catch error if can't cast to integer
                cout << "Invalid entry." << endl; 
                return -1;
            } catch (const std::out_of_range& e) { // Catch error if number is too large
                cout << "Invalid entry." << endl;
                return -1;
            }
        }
        else {
            cout << "Invalid column or row." << endl;
            return -1;
        }
    }
}
// Takes current and destination arrays and calculates distance using pythagorean theorem, return integer
int Map::calcDistance(int curr[2], int dest[2]){
    int x = abs(curr[0] - dest[0]); // x distance
    int y = abs(curr[1] - dest[1]); // y distance
    int distance = sqrt(pow(x,2) + pow(y,2)); // Pythagorean theorem
    return distance;
}

// Generate map from file
void Map::generateMap(){
    ifstream mapFile; // Create filestream
    std::string line;
    if(random){ // Not used, scrapped idea
        // display = "";
    }
    else {
        mapFile.open("maps/" + filename); // Open specified file in maps folder
    }
    if (mapFile.is_open()){ // If file opens
        // string splitArray[3];
        getline(mapFile, name); // First line in file is name
        getline(mapFile, description); // 2nd line in file is description
        getline(mapFile, line); // 3rd line is height
        height = stoi(line); // Convert to int
        getline(mapFile, line); // 4th line is width
        width = stoi(line); // Convert to int
        getline(mapFile, line); // 5th line is number of locations on map
        locationCount = stoi(line); // Convert to int
        getline(mapFile, line); // 6th line is filler character
        filler = line[0];
        for (int i = 0; i < locationCount; i++){ // Iterate over remaining lines and and create location from each line and add to location array on map
            getline(mapFile, line);
            locations[i].generateLocation(line); // Generate location from line
        }
    }
    mapFile.close();
    // Iterate over display array and add filler character to every value in range
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            display[i][j] = filler;
        }
    }
    // Iterate over locations and add location marker to map at location coordinates
    for (int i = 0; i < locationCount; i++){
        if (locations[i].getDiscoveryStatus()) { // Only add visible locations
            int x = locations[i].getXLoc();
            int y = locations[i].getYLoc();
            display[y][x] = locations[i].getMapKey();
        }
    }
    randomPlayerLoc();
} 
// Starts player at random location on map
void Map::randomPlayerLoc(){
    srand(time(0));
    bool flag = false;
    do
    {
        int x = rand()% width;
        int y = rand()% height;
        flag = setPlayerLoc(x, y); // Returns true if valid location
    } while (!flag);
}

// Takes a location and sets the location on the map to discovered
int Map::revealLocation(Location l){
    display[l.getYLoc()][l.getXLoc()] = l.getMapKey(); // Character that represents location on map set at specified coordinates
    for (int i = 0; i < 20; i++){ // Find location by name and set discovered to true
        if (locations[i].getName() == l.getName()){
            locations[i].setDiscovered(true);
        }
    }
    printMap(); // Print new explored map
    return 0;
}
    
// Takes x location integer and y location integer and sets player location on map to xy coordinates
bool Map::setPlayerLoc(int x, int y){
    if (display[y][x] == filler){ // Check if specified destination is empty space and not a marked location
        display[playerLoc[1]][playerLoc[0]] = filler; // Fill in previous player coordinates with filler character 
        display[y][x] = '$'; // Set new location to $
        // Update new player location coordinates
        playerLoc[0]=x; 
        playerLoc[1]=y; 
        playerMarked = true;
        return 1;
    } else{
        return 0;
    }
}
// Return bool status if player is marked on map
bool Map::getPlayerMarked(){
    return playerMarked;
}
// Print map
void Map::printMap() const{
    // Print name of map
    cout << name << endl;
    cout << "    ";
    // Print column headers
    for(int j = 0; j < width; j++){
        cout << char(65+j) << " ";
    }
    cout << endl;
    cout << "   ";
    // Print top border
    for(int j = 0; j < width*2+1; j++){
        cout << "-";
    }
    cout << endl;
    // Print row header, left border, coordinates value, right border, row header
    for (int i = 0; i < height; i++){
        if (i < 10 ){
            cout << "0" << i << "| ";
        } else {
            cout << i << "| "; 
        }
        for(int j = 0; j < width; j++){
            if (display[i][j] == '$'){ // At player location print rocket ship
                cout << "\033[1;31m\xF0\x9F\x9A\x80\033[0m";
            } else {
                cout << display[i][j] << " ";
            }
        }
        if (i < 10){
            cout << "|" << "0" << i << endl;
        } else {
            cout << "|" << i << endl;
        }
    }
    cout << "   ";
    // Print bottom border
    for(int j = 0; j < width*2+1; j++){
        cout << "-";
    }
    cout << endl;
    cout << "    ";
    // Print column headers
    for(int j = 0; j < width; j++){
        cout << char(65+j) << " ";
    }
    cout << endl;
    cout << description << endl;
}
// Print legend for map, takes player visibility as bool
void Map::printLegend(bool playerMarked) const{
    cout << "_______________________" << endl;
    cout << "Map Legend" << endl;
    // Iterate over locations and print name and key
    for (int i = 0; i < locationCount; i++){
        if (locations[i].getDiscoveryStatus()) {
            cout << locations[i].getMapKey() << " = " << locations[i].getName() << endl; // Print visible locations and their map key
        }
    }
    if (playerMarked) { // If player is visible add player to legend
        cout << "\033[1;31m\xF0\x9F\x9A\x80\033[0m= Your Location" << endl;
    }
    cout << "-----------------------" << endl;
}
// Returns number of locations on map
int Map::getLocationCount() const{
    return locationCount;
}
// Get specified location 
Location Map::getLocation(int i) const{
    return locations[i];
}
// Get map width as int
int Map::getWidth() const{
    return width;
}
// Get map height as int
int Map::getHeight() const{
    return height;
}
// Get name of map as string
string Map::getName() const{
    return name;
}
// "\033[1;31m\xF0\x9F\x9A\x80\033[0m"; Rocket
// "\033[1;34m\xF0\x9F\x8C\x8F\033[0m" Planet