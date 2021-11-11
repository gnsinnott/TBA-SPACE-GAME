#include"Game.h"
#include"Player.h"
#include"spaceShip.h"
#include"Map.h"
#include"Location.h"
#include"Enemy.h"
#include<iostream>
#include<string>
using namespace std;

Game::Game(){

}

// Main menu
void Game::mainMenu(){
    cout << "TBA SPACE GAME" << endl;
    cout << "--------------" << endl;
}
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
            if (age > 15 && age < 96){
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
    while(!validAge);
    cout << "Name: " << player.getName() << endl;
    cout << "Age: " << player.getAge() << endl;
    cout << "Now it's time to pick your starting ship" << endl;
    string ships[] = {"Falcon", "Serenity", "Enterprise", "Atlantia"};
    ship.setName(ships[printMenu("Ship selection", ships, 4)]);
    cout << "Welcome aboard the " << ship.getName() << endl;
}
int Game::printMenu(string title, string choices[], int size){
    string input;
    int choice = 0;
    cout << title << endl;
    do {
        cout << "What would you like to do?" << endl;
        for (int i = 0; i < size; i++){
            cout << i+1 << ") " << choices[i] << endl; 
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
            return choice-1;
        }
        else{
            cout << "Invalid input." << endl;
        }
    }
    while(true);
}
void Game::play(){
        
}