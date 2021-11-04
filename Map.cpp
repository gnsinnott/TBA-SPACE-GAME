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
Map::Map(string n, string t, string f, int w, int h, bool r){
    name = n;
    type = t;
    filename = f;
    width = w;
    height = h;
    random = r;
}
void Map::setName(string n){
    name = n;
}
void Map::setDescription(string d){
    description = d;
}
void Map::setType(string t){
    type = t;
}
void Map::setFile(std::string f){
    filename = f;
    random = false;
}
void Map::setSize(int w, int h){
    width = w;
    height = h;
}
void Map::setRandom(bool r){
    random = r;
}
void Map::setLocationCount(int c){
    locationCount = c;
}
void Map::setLocation(int i, Location location){
    locations[i] = location;
}
void Map::generateMap(std::string filename){
    ifstream mapFile;
    std::string line;
    if(random){
        // display = "";
    }
    else {
        mapFile.open("maps/" + filename);
    }
    char filler;
    if (mapFile.is_open()){
        string splitArray[3];
        getline(mapFile, name);
        getline(mapFile, description);
        getline(mapFile, line);
        height = stoi(line);
        getline(mapFile, line);
        width = stoi(line);
        getline(mapFile, line);
        locationCount = stoi(line);
        getline(mapFile, line);
        filler = line[0];
        for (int i = 0; i < locationCount; i++){
            getline(mapFile, line);
            locations[i].generateLocation(line);
        }
    }
    mapFile.close();
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            display[i][j] = filler;
        }
    }
    for (int i = 0; i < locationCount; i++){
        if (locations[i].getDiscoveryStatus()) {
            int x = locations[i].getXLoc();
            int y = locations[i].getYLoc();
            display[y][x] = locations[i].getMapKey();
        }
    }
} 
void Map::printMap() const{
    cout << name << endl;
    cout << " ";
    for(int j = 0; j < width+2; j++){
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < height; i++){
        cout << "| ";
        for(int j = 0; j < width; j++){
            cout << display[i][j]; 
        }
        cout << " |" << endl;  
    }
    cout << " ";
    for(int j = 0; j < width+2; j++){
        cout << "-";
    }
    cout << endl;
    cout << description << endl;
}

void Map::printLegend() const{
    cout << "_______________________" << endl;
    cout << "Map Legend" << endl;
    for (int i = 0; i < locationCount; i++){
        if (locations[i].getDiscoveryStatus()) {
            cout << locations[i].getMapKey() << " = " << locations[i].getName() << endl;
        }
    }
    cout << "-----------------------" << endl;
}
int Map::getLocationCount() const{
    return locationCount;
}
Location Map::getLocation(int i) const{
    return locations[i];
}
// "\033[1;31m\xF0\x9F\x9A\x80\033[0m"; Rocket
// "\033[1;34m\xF0\x9F\x8C\x8F\033[0m" Planet