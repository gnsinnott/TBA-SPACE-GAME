//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3  
#include"Map.h"
#include<iostream>
#include<fstream>
using namespace std;

// Function to split character seperated values and return array of strings
int split(string text, char delim, string splitArray[], int size) {
    int start = 0; //Start of first item to split
    int delimCount = 0; // How many delimeters where found
    int length = text.length(); // Total length of text
    if (length == 0) { // If string of length 0 return 0
        return 0;
    }
    for (int i = 0; i < length; i++){ // Iterate over text
        if (text[i] == delim) { // Check if char is delimiter
            splitArray[delimCount] = text.substr(start, i-start); // Set string in array split at location of delimeter count equal to substring from start to length of char location - start location
            start = i+1; // New start location is the char after the delimeter
            delimCount++; // Increase running count of delimiters
        }
    }
    if (delimCount > size-1){ // Delim count is equal to number of split strings -1, if greater than size-1 return -1
        return -1;
    }
    splitArray[delimCount] =  text.substr(start, length - start); // Add string found after last delimeter to the array at final delimCount location
    return delimCount+1; // Returns number of split strings which is 1 more than number of delimiters
}

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
int Map::travelTo(string destination){
    if (destination.size() == 1){ // If destination is location key
        for (int i = 0; i < locationCount; i++){ // Find key in location array
            if (getLocation(i).getMapKey() == destination[0]){
                //filename = getLocation(i).getMapFile(); // Send location to somewhere, not sure yet how to move between maps
                return 1;
            }
        }
        cout << "Invalid destination" << endl;
            return 0;
    } else { // Get coordinates from destination 
        if (int(destination[0]) >= 65 && int(destination[0]) <= 90) { // Verify first character is a capital letter
            try { // Try and cast destination string to integers
                int tempColumn = int(destination[0])-65; // Set temp column to first char
                int tempRow = stoi(destination.substr(1)); // Set temp row to remainding chracters in destination string
                // cout << "Column: " << tempColumn << endl << "Row: " << tempRow << endl;
                if (tempColumn < width && tempRow < height){ // Verify coordinates are in range of map
                    setPlayerLoc(tempColumn, tempRow); // Update player location
                    return 1;
                }
                else {
                    cout << "Entry out of bounds, try again." << endl;
                    return 0;
                }
            }catch (const std::invalid_argument& e) { // Error if can't cast to integer
                cout << "Invalid entry." << endl; 
                return 0;
            }
        }
        else {
            cout << "Invalid column or row." << endl;
            return 0;
        }
    }
}
// Generate map from file
void Map::generateMap(std::string filename){
    ifstream mapFile; // Create filestream
    std::string line;
    if(random){
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
} 
// Set player location on map
bool Map::setPlayerLoc(int x, int y){
    if (display[y][x] == filler){ // Check if specified destination is empty space and not a marked location
        display[playerLoc[1]][playerLoc[0]] = filler; // Fill in previous player coordinates with filler character 
        display[y][x] = '$'; // Set new location to $
        // Update new player location coordinates
        playerLoc[0]=x; 
        playerLoc[1]=y; 
        return 1;
    } else{
        return 0;
    }
}
// Print map
void Map::printMap() const{
    // Print name of map
    cout << name << endl;
    cout << "   ";
    // Print column headers
    for(int j = 0; j < width; j++){
        cout << char(65+j) << " ";
    }
    cout << endl;
    cout << "  ";
    // Print top border
    for(int j = 0; j < width*2+1; j++){
        cout << "-";
    }
    cout << endl;
    // Print row header, left border, coordinates value, right border, row header
    for (int i = 0; i < height; i++){
        cout << i << "| ";
        for(int j = 0; j < width; j++){
            if (display[i][j] == '$'){ // At player location print rocket ship
                cout << "\033[1;31m\xF0\x9F\x9A\x80\033[0m";
            } else {
                cout << display[i][j] << " ";
            }
        }
        cout << "|" << i << endl;  
    }
    cout << "  ";
    // Print bottom border
    for(int j = 0; j < width*2+1; j++){
        cout << "-";
    }
    cout << endl;
    cout << "   ";
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
            cout << locations[i].getMapKey() << " = " << locations[i].getName() << endl;
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
// "\033[1;31m\xF0\x9F\x9A\x80\033[0m"; Rocket
// "\033[1;34m\xF0\x9F\x8C\x8F\033[0m" Planet