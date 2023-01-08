#include "dc.h"
#include "player.h"


DC::DC() 
    : Building{"DC Tims Line"} {}

std::string DC::getName() {
    return name;
}

void DC::addTurns(char p, int a) {
    if (turns.count(p)) {
        turns[p] = turns[p] + a;
    } else {
        turns[p] = -1;
    }
    
    
}

int DC::getTurns(char p) {
    return turns[p];
}
    
    