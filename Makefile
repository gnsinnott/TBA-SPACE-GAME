all: gameDriver

gameDriver: gameDriver.o
	g++ -o  TBA-SPACE-GAME Enemy.cpp Game.cpp Location.cpp Map.cpp player.cpp spaceShip.cpp gameDriver.cpp