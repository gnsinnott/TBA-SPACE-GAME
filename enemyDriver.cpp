#include <iostream>
#include <random>
#include"Enemy.h"

using namespace std;

int main(){
    srand(time(0));
    Enemy foe = Enemy("Alien", "Scary", "Bipod", 30, 5,2,5); // Enemy with 5 attack plus minus 2
    int damage = 0;
    for (int i = 0; i < 100; i++){
        damage = damage + foe.attack();
    }
    cout << damage/100.0 << endl; // Average attack over 100 attacks, should be close to 5
    cout << "I am " << foe.getName() << " and I am a " << foe.getType() << " with " << foe.getDefense() << " defense and " << foe.getHp() << " HP" << endl;
    foe.setName("Larry");
    foe.setHp(25);
    cout << "Now my name is " << foe.getName() << " and I have " << foe.getHp() << " hp." << endl;
    return 0;
}