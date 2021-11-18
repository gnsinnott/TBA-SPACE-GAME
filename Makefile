all: gameDriver

gameDriver: 
	g++ -std=c++11 -o game.out Game.cpp Location.cpp Map.cpp player.cpp spaceShip.cpp Enemy.cpp gameDriver.cpp