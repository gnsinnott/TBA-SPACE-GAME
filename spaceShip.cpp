//CSCI1300 Fall 2021
//Author: Pandora Down and Greg Sinnott
//Recitation 112- Maria Stull
//Project 3  


using namespace std;


    SpaceShip::SpaceShip()
    {
        name = "";
        fuel = 0;
        gasMilage = 0;
        attakPoints = 0;
        defensePoints = 0;
    }
    SpaceShip::SpaceShip(string n, int f, int g, int attakPoints, int defensePoints)
    {
        name = n;
        fuel = f;
        gasMilage = g;
        attakPoints = a;
        defensePoints = d;
    }
    void SpaceShip::setName(string n)
    {
       name = n; 
    } 
    void SpaceShip::setFuel(int f)
    {
        fuel = f;
    }
    void SpaceShip::setGasMiliage(int g)
    {
        gasMiliage = g;
    }
    void SpaceShip::setAttack(int a)
    {
        attackPoints = a;
    }
    void SpaceShip::setDefense(int d)
    {
        attackPoints = d;
    }
    
    //getters
    string SpaceShip::getName()
    {
        return name;
    }
    int SpaceShip::getFuel()
    {
        return fuel;
    }
    int SpaceShip::getGasMiliage()
    {
        return gasMiliage;
    }
    int SpaceShip::getAttack()
    {
        return attakPoints;
    }
    int SpaceShip::getDefense()
    {
        return defensePoints;
    }

