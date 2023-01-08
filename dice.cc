#include "dice.h"
#include <cstdlib> 
#include <ctime>

Dice::Dice() : num { -1 } {}

int Dice::roll() {
    srand (time(NULL));
    num = rand() % 6 + 1;
    return num;
}
