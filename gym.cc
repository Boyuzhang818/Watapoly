#include "gym.h"
#include "dice.h"
#include "player.h"

Gym::Gym(  std::string name, int purchase, 
        bool mortgaged ) : Chargeable{ name, purchase,  mortgaged } {}


Gym::~Gym() {}

std::string Gym::getName() {
    return this->name;
}

void Gym::mortgage() {
    mortgaged = true;
}
void Gym::unmortgage() {
    mortgaged = false;
}

int Gym::getPurchase() {
    return purchase;
}

void Gym::setOwner( std::shared_ptr<Player> player ) {
    owner = player;
}

std::shared_ptr<Player> Gym::getOwner() {
    return owner;
}

bool Gym::getMortgage() {
    return mortgaged;
}

int Gym::charge() {
    auto owner = this->getOwner();
    bool mortgaged = this->getMortgage();
    int count = 0;
    if ( !mortgaged && owner != nullptr ) {
        auto property = owner->getProperty();
        int n = property.size();
        for( int i = 0; i < n; i++ ) {
            if ( property.at(i)->getName() == "PAC" || property.at(i)->getName() == "CIF" ) {
                    count++;
                }
        }
    
    
        Dice d = Dice();
        int n1 = d.roll();
        int n2 = d.roll();
        int fee = n1 + n2;
        if ( count == 1 ) {
            fee *= 4;
        }
        if ( count == 2 ) {
            fee *= 10;
        }
        return fee;
    } else {
        return 0;
    }
}

