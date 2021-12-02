#include"Game.h"
#include"Player.h"
#include"spaceShip.h"
#include"Map.h"
#include"Location.h"
#include"Enemy.h"
#include<fstream>
#include<iostream>
#include<string>
#include<random>
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
        string file = locations[i].getMapFile(); // Get file name of map
        if (file != "Planet") { // Verify location is not a planet
            temp.setFile(file);
            temp.generateMap(); // Generate the map
            maps.push_back(temp); // Add map to vector of maps in game
        }
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
    player.setNumPlanets(0);
    cout << "Welcome " << player.getName() << " in this game your age matters. You have limited time to complete this game, roughly 100 years." << endl;
    cout << "To earn money you will have to spend time working, the older you start the more money you will make for each year worked. Choose wisely!" << endl;
    do {
        cout << "How old are you?" << endl;
        getline(cin, input);
        try // Try to convert string to integer
        {
            age = stoi(input);
            if (age > 24 && age < 96){ // Verify age is in appropriate range
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
        catch(const std::out_of_range& e) // Catch error if number is too large
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
        ship.setAttackRange(10);
        ship.setFuel(100);
        ship.setGasMileage(1);
        ship.setHp(50);
    }
    else if (ship.getName() == "Serenity"){
        ship.setBaseAttack(15);
        ship.setAttackRange(2);
        ship.setFuel(70);
        ship.setGasMileage(2);
        ship.setHp(40);
    }
    else if (ship.getName() == "Enterprise"){
        ship.setBaseAttack(12);
        ship.setAttackRange(0);
        ship.setFuel(70);
        ship.setGasMileage(1);
        ship.setHp(60);
    }
    else if (ship.getName() == "Atlantia"){
        ship.setBaseAttack(15);
        ship.setAttackRange(3);
        ship.setFuel(200);
        ship.setGasMileage(1);
        ship.setHp(100);
    }
    findLocation("C++ System");
}
// Prints menu from array of strings, takes title, array of choices and array size
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
            cout << "Invalid input." << endl;
        }
        catch(const std::out_of_range& e) // Catch error if number is too large
        {
            cout << "Invalid input." << endl;
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

// Takes a string name of a location and finds it in array, sets youAreHere to specified location and if a system updates current game map
void Game::findLocation(string n){
    for (int i = 0; i < locations.size(); i++){
        if (locations[i].getName() == n){
            if (locations[i].getMapFile() == "Planet"){
                youAreHere = locations[i];
            }
            else {
                for (int j = 0; j < maps.size(); j++){
                    if (maps[j].getName() == n){
                        map = maps[j];
                        youAreHere = locations[i];
                    }
                }
            }
        }
    }
}

// Unlocks a random location on current map when exploring a planet
int Game::unlockLocation(){
    player.setAge(player.getAge() + 1); // Increment age of player by 1
    srand(time(0));
    vector <int> undiscoveredLocations; // Vector for undiscovered locations
    cout << "MORTAL COMBAT!!!!" << endl;
    Enemy enemy("Blob", "Ugly", "Space", 20, 3, 3);
    player = enemy.attackPlayer(player);
    for (int i = 0; i < locations.size(); i++){ // Iterate over locations and any that are undiscovered get added to undiscoveredLocations vector
        if (locations[i].getDiscoveryStatus() == false){
            undiscoveredLocations.push_back(i);
        }
    }
    if (undiscoveredLocations.size() == 0 || youAreHere.getExploredStatus()){ // If no locations are left undiscovered reward player with money
        int money = 100 * ((rand() % 10) +1); // Random amount of money between 100 and 1000
        cout << "No new information was discovered but you did find artifacts that you were able to sell for " << money << " credits" << endl;
        player.setMoney(player.getMoney() + money); // Increase player money
        return 0;
    }
    else { // Discover location
        int newLocation = rand() % undiscoveredLocations.size(); // Random location from array
        locations[undiscoveredLocations[newLocation]].setDiscovered(true); // Set new location to discovered
        youAreHere.setExploredStatus(true); // Set current planet to explored
        
        cout << "You discovered the location of the " << locations[newLocation].getName() << " planet in this system. \xF0\x9F\x94\xAD" << endl;
        for (int j = 0; j < maps.size(); j++){
                if (maps[j].getName() == getCurrentMap().getName()){
                    maps[j].revealLocation(locations[newLocation]);
                    player.setNumPlanets(player.getNumPlanets() + 1);
                    map = maps[j];
                }
            }
        return 1;
    }
}
SpaceShip Game::getShip(){
    return ship;
}
Player Game::getPlayer(){
    return player;
}
Location Game::getCurrentLocation(){
    return youAreHere;
}
Map Game::getCurrentMap(){
    return map;
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
/*  This fuction numDelimiters takes a string with delimitersand counts the number of  delimiters, 
-input string input, char delimiter
-output number of Deliminator.  
*/
int numDelimiters(string input, char delimiter) // Finds the number of delimiters in a string, returns number of delimiters
{
 int length = input.length();
 int count = 0;
 for(int i = 0; i < length; i++)
    {
       if(input[i]== delimiter)
       {
           count ++;
       } 
    }
return count;
}
/*  This fuction (split()) takes a string with delimiters, and breaks the string pieces based on the delimiters, 
placing each piece sequentially in an array. 
-input string input, char delimiter, string array, integer array size
-output size of the array 
*/
int split(string input, char delimiter, string array[], int size) // splits string into string array at delimiter character  
{
    int num_delimiter = numDelimiters(input, delimiter);
    int input_length = input.length();
    
    if(input != "") //If input string is not empty
    {
        int array_enteries = num_delimiter +1;
            int i = 0;
            for(int j = 0; j < array_enteries; j++)
            {
                string str1 = "";
                while(input[i] != delimiter && i < input_length)
                {
                    char char1 = input[i];
                    str1 = str1 + char1; //str1 = all values up to delimiter
                    array[j] = str1; //array j = str1 
                    i ++; 
                }   
            //cout << array[j] << endl;
            i ++; //moves i past delimiter 
            }
        if(size > num_delimiter && num_delimiter != 0) 
        {
           size =  num_delimiter+1;     
        }
        else if(num_delimiter == 0) // if no delimiters size = 1
        {
            size = 1;
        }  
        else // if number of delimiters is greater than or equal to array indices size = -1
        {
            size = -1;
        }
    }
    else //if empty size equals zero
    {
        size = 0; 
    }
    
return size;
}
/*  This fuction records player scores to highScores.txt and prints out the scores and player names to terminal in descending order. 
*/
void Game::endGame(){
    if (player.getAge() >= 100){
        cout << "You've reached old age and it's time to retire!" << " \xF0\x9F\x8F\x86" << endl;
    }
    if (ship.getFuel() <= 0){
        cout << "You've run out of fuel and are stranded in space." << endl;
    }
    cout << "Game over, you discovered " << player.getNumPlanets() << " planet(s) on your journey." << endl;
    ofstream fout;
    fout.open("highScores.txt", ios::app);
    string line;
        if(!fout.is_open())
        {
            cout << "Could not open high scores file" << endl;
        }
        fout << player.getName() << ", " << player.getNumPlanets() << endl; 
    ifstream fin;
    fout.close(); // close file
    vector<string> playerNames;
    vector<int> numPlanets;
    fin.open("highScores.txt");
        if(fin.fail())
        {
        cout << "Could not open high scores file" << endl;  
        } 
    const int SIZE = 2;
    string array[SIZE];
    char delimiter = ',';
    while(getline(fin,line))//As long as there is data to read from file loop will execute
        {
            if(!isspace(line[0]) && line.length() > 1)
            {
                split(line, delimiter, array, SIZE);
                playerNames.push_back(array[0]);
                numPlanets.push_back(stoi(array[1]));
            } 
        }
    fin.close(); //close file
    int tempInt = 0;
    string tempString; 
    bool flag = true;
        while (flag == true) //sorts integer array smallest to leargest 
        {
            flag = false;
            for (int i = 0; i < size-1; i++)
            {
                if (numPlanets[i] < numPlanets[i+1])
                {
                    tempInt = numPlanets[i];
                    tempString = playerNames[i];
                    numPlanets[i] = numPlanets[i+1];
                    playerNames[i] = playerNames[i+1];
                    numPlanets[i+1] = tempInt;
                    playerNames[i+1] = tempString;
                    flag = true;
                }
            }
        }
    cout << "High Scores" << endl;
    cout << "-----------" << endl;
    for(int i = 0; i < playerNames.size(); i++)
    {
        cout << playerNames[i] << ", " << numPlanets[i] << endl;
    }
}
// Function that allows player to buy things when on planets
void Game::buy()
{
    string choices[] ={"gas...$100 per gallon", "dynamite...$5000", "beer...$10,000"}; // Items to buy
    int option = printMenu("What would you like to buy?", choices, 3); // Generate menu to get player choice
    int money = player.getMoney();
    string input;
    bool validChoice = false;
    if(option == 0){
        do { 
            int numGallons = 0;
            cout << "How many Gallons would you like to buy?" << endl;
            getline(cin, input);
            try // Try to convert string to integer
                {
                    numGallons = stoi(input);
                    if (numGallons < 0){
                        cout << "You can't buy negative fuel." << endl;
                    }
                    else if(money <= 100 * numGallons){ // Check if player does not have enough money
                        cout << "You have $ " << money << "." << "You do not have enough credits to buy this much gas" << " \xF0\x9F\x98\x96." << endl;  
                    }
                    else {
                        cout << "You have bought " << numGallons << " of gas, enjoy your journey!" << endl;
                        ship.setFuel(ship.getFuel() + numGallons); // Update fuel
                        player.setMoney(money - 100 * numGallons); // Update player credits
                        validChoice = true; // Confirm valid choice
                    }
                }
                catch(const std::invalid_argument& e) // Catch error if string cannot become an integer
                {
                    cout << "Invalid input." << endl;
                    validChoice = false;
                }
                catch(const std::out_of_range& e) // Catch error if number is too large
                {
                    cout << "Invalid input." << endl;
                    validChoice = false;
                }
        } while(!validChoice); // Loops until valid purchase amount is entered
    } else if(option == 1){
        if(money >= 5000){
            cout << "You have bought dynamite, destroy your enemies! \xF0\x9F\x92\xA3 " << endl; 
            ship.setBaseAttack(ship.getbaseAttack() + 1); 
            player.setMoney(player.getMoney() - 5000); 
        }
        else{
            cout << "You don't have enough money for this transaction!" << endl; 
        }
        } else if(option == 2){
            if(money >= 10000){
            cout << "You have beer, feel refreshed!" <<" \xF0\x9F\x8D\xBB" << endl;
            player.setBaseAttack(player.getbaseAttack() + 1);
            player.setAttackRange(player.getAttackRange() + 2); 
            player.setMoney(player.getMoney() - 10000);
        }
        else{
            cout << "You don't have enough money for this transaction!" << endl;   
        } 
    }
}