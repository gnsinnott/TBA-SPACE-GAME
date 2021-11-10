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
void Game::printMenu(string title, string choices[], int size){
    string choice;
    cout << title << endl;
    cout << "What would you like to do?" << endl;
    for (int i = 0; i < size; i++){
        cout << i << ") " << choices[i] << endl; 
    }

}