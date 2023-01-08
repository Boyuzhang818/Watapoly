#include "residences.h"
#include "player.h"

Residences::Residences( std::string name, int purchase, 
        bool mortgaged ) : Chargeable{ name, purchase,  mortgaged } {}
        
Residences::~Residences() {}

void Residences::setOwner(std::shared_ptr<Player> p) {
    owner = p;
}


std::string Residences::getName() {
    return name;
}

void Residences::mortgage() {
    mortgaged = true;
}
void Residences::unmortgage() {
    mortgaged = false;
}

int Residences::getPurchase() {
    return purchase;
}

std::shared_ptr<Player> Residences::getOwner() {
    return owner;
}

bool Residences::getMortgage() {
    return mortgaged;
}


int Residences::charge() {
    auto owner = this->getOwner();
    bool mortgaged =  this->getMortgage();
    int count = 0;
    if ( !mortgaged && owner != nullptr ) {
        auto property = owner->getProperty();
        int n = property.size();
        for( int i = 0; i < n; i++ ) {
            std::string name = property.at(i)->getName();
            if ( name == "MKV" || name == "UWP" || name == "V1" || name == "REV" ) {
                    count++;
                }
        }
    
    
        int rent = 25;
        if ( count == 1 ) {
            rent = 25;
        }
        if ( count == 2 ) {
            rent = 50;
        }
        if ( count == 3 ) {
            rent = 100;
        }
        if ( count == 4 ) {
            rent = 200;
        }
        return rent;
    } else {
        return 0;
    }
}




