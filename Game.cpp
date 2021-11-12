#include"Game.h"
#include"Player.h"
#include"spaceShip.h"
#include"Map.h"
#include"Location.h"
#include"Enemy.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

// Default constructor need to evaluate use
Game::Game(){

}

// Main menu
void Game::mainMenu(){
    cout << "TBA SPACE GAME" << endl;
    cout << "--------------" << endl;
}
// Generate all locations in game and add to vector of locations
int Game::generateLocations(){
    ifstream locationList;
    string line;
    locationList.open("locations/list.txt"); // Master file of locations
    if (locationList.is_open()){
        while(getline(locationList, line)){ // Iterate over lines in file to create locations
            Location temp; 
            temp.generateLocation(line); // pass line which is name of txt file containing location to function
            locations.push_back(temp); // add location to vector of locations in game
        }
    } else {
        return -1; // If can't open file return -1
    }
    locationList.close();
    cout << "Locations loaded: " << locations.size() << endl; // Print out number of locations loaded for testing purposes
    return locations.size(); // Return number of locations
}
// Generate all maps in game and add to vector of maps
int Game::generateMaps(){
    for (int i = 0; i < locations.size(); i++){ // Iterate over locations vector
        Map temp;
        temp.setFile(locations[i].getMapFile()); // Set map file from location
        temp.generateMap(); // Generate the map
        maps.push_back(temp); // Add map to vector of maps in game
    }
    if (maps.size() == 0){ // If no maps added return -1
        return -1; 
    } else {
        cout << "Maps loaded: " << maps.size() << endl; // Print out number of maps loaded for testing purposes
        return maps.size(); // Return number of maps
    }
}
// Begins new game, sets player info
void Game::newGame(){
    string input;
    bool validAge = false;
    int age = 0;
    cout << "Welcome to TBA SPACE GAME" << endl;
    cout << "Please enter your player name: " << endl;
    getline(cin, input);
    player.setName(input);
    cout << "Welcome " << player.getName() << " in this game your age matters. You have limited time to complete this game, roughly 100 years." << endl;
    cout << "To earn money you will have to spend time working, the older you start the more money you will make for each year worked. Choose wisely!" << endl;
    do {
        cout << "How old are you?" << endl;
        getline(cin, input);
        try // Try to convert string to integer
        {
            age = stoi(input);
            if (age > 15 && age < 96){ // Verify age is in appropriate range
                player.setStartingAge(age);
                validAge = true;
            } else {
                cout << "You are outside the age range to have a galactic drivers license (25-95)" << endl;
                validAge = false;
            }
        }
        catch(const std::invalid_argument& e) // Catch error if string cannot become an integer
        {
            cout << "Invalid input." << endl;
        }
    }
    while(!validAge); // Loops until age is set to appropriate value
    cout << "Name: " << player.getName() << endl;
    cout << "Age: " << player.getAge() << endl;
    cout << "Now it's time to pick your starting ship" << endl;
    string ships[] = {"Falcon", "Serenity", "Enterprise", "Atlantia"}; // Array of ship choices
    ship.setName(ships[printMenu("Choose a ship", ships, 4)]); // Create ship choice menu
    cout << "Welcome aboard the " << ship.getName() << endl; // Welcome player aboard ship
    // Set ship stats, will probably be reworked but good enough for testing purposes
    if (ship.getName() == "Falcon"){
        ship.setBaseAttack(5);
        ship.setAttackRange(1);
        ship.setDefense(8);
        ship.setFuel(100);
        ship.setGasMileage(10);
        ship.setHp(50);
    }
    else if (ship.getName() == "Serenity"){
        ship.setBaseAttack(7);
        ship.setAttackRange(2);
        ship.setDefense(5);
        ship.setFuel(70);
        ship.setGasMileage(5);
        ship.setHp(40);
    }
    else if (ship.getName() == "Enterprise"){
        ship.setBaseAttack(7);
        ship.setAttackRange(0);
        ship.setDefense(7);
        ship.setFuel(70);
        ship.setGasMileage(8);
        ship.setHp(60);
    }
    else if (ship.getName() == "Atlantia"){
        ship.setBaseAttack(4);
        ship.setAttackRange(3);
        ship.setDefense(5);
        ship.setFuel(200);
        ship.setGasMileage(3);
        ship.setHp(100);
    }
}
// Prints menu from array of strings
int Game::printMenu(string title, string choices[], int size){
    string input;
    int choice = 0;
    cout << title << endl; // Print menu title
    do {
        for (int i = 0; i < size; i++){ // Iterate over array printing each option
            cout << i+1 << ") " << choices[i] << endl; // Print number of option and option
        }
        getline(cin, input);
        try // Try to convert string to integer
        {
            choice = stoi(input);
        }
        catch(const std::invalid_argument& e) // Catch error if string cannot become an integer
        {
        }
        if(choice != 0 && choice <= size){
            return choice-1; // Return choice indexed back to 0
        }
        else{
            cout << "Invalid input." << endl;
        }
    }
    while(true);
}
// Sets new location, needs to be reworked
void Game::newLocation(string l){ // Takes name of location
    string fileName = l + ".txt"; // add .txt to location to specify file name
    youAreHere.generateLocation(fileName); // Generate location
    map.setFile(youAreHere.getMapFile()); // Set map file name from location
    map.generateMap(); // Generate map from map file

}
// Starts play of game, needs to be reworked
void Game::play(){
    map.setFile("cs.txt");
    map.generateMap();
    
}