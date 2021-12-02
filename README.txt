HOW TO COMPILE AND RUN
------------------------
Compile: 
you can compile by typing "make" into the command line and then ./game.out

or

you can compile by typing g++ -std=c++11 -o game.out Game.cpp Location.cpp Map.cpp 
player.cpp spaceShip.cpp Enemy.cpp gameDriver.cpp in the command line and then ./game.out

We found an issue where the same compiled program ran differently on two different mac os environments
It worked on OS Monterey(Clang version 13) but not Catalina(Clang version 12)
Even when compiled on Monterey and executed on Catalina the map doesn't work correctly
Since it's not a compilation issue and shouldn't have anything to do with clang I'm not sure how to debug
An example of what the map should look like is included in this zip file "Map Rendered Correctly.zip"
If it doesn't run correctly you will see blank space instead of stars
When maps are initially created they print correctly but when the current map in the game is assigned to a map
from the vector of maps in the game some information such as the display array is "dropped" for lack of a better term
------------------------
DEPENDENCIES
------------------------
The following files  must be in the same directory as the cpp files in 
order to compile:
Enemy.h
Location.h
Game.h
Map.h
Player.h
SpaceShip.h
------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2021 Project 3
Author: Pandora Down and Greg Sinnott
Recitation 112- Maria Stull
November 24th 2021 
------------------------
ABOUT THIS PROJECT
------------------------
This project implements a game that allows a player to travel through space on a spaceship of there choosing 
and discover new planets. The player has a hundred year lifespan to explore space and after aging past that point they retire. 
