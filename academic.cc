#include "academic.h"
#include "player.h"
#include <iostream>

Academic::Academic( std::string name, int purchase, 
        bool mortgaged, std::string block, int improvements, int improveCost, std::vector<int> tuition )
            : Chargeable{ name, purchase,  mortgaged }, block { block }, improvements{ improvements }, 
            improveCost{ improveCost }, tuition{ tuition } {}

Academic::~Academic() {}

void Academic::setOwner(std::shared_ptr<Player> p) {
    owner = p;
}

std::string Academic::getBlock() {
    return block;
}

int Academic::getImprovements() {
    return improvements;
}
int Academic::getImproveCost() {
    return improveCost;
}

std::vector<int> Academic::getTuition() {
    return tuition;
}

std::string Academic::getName() {
    return name;
}

void Academic::mortgage() {
    mortgaged = true;
}
void Academic::unmortgage() {
    mortgaged = false;
}

int Academic::getPurchase() {
    return purchase;
}

std::shared_ptr<Player> Academic::getOwner() {
    return owner;
}

bool Academic::getMortgage() {
    return mortgaged;
}

void Academic::incImprovements() {
    improvements++;
}

void Academic::decImprovements() {
    improvements--;
}

bool Academic::isArts1Mono() {
    auto owner = this->getOwner();
    int count = 0;
    if ( owner != nullptr ) {
        auto property = owner->getProperty();
        int n = property.size();
        for( int i = 0; i < n; i++ ) {
            std::string name = property.at(i)->getName();
            if ( name == "AL" || name == "ML" ) {
                count++;
            }
        }
    }
    return count == 2;
} 

bool Academic::isArts2Mono() {
    auto owner = this->getOwner();
    int count = 0;
    if ( owner != nullptr ) {
        auto property = owner->getProperty();
        int n = property.size();
        for( int i = 0; i < n; i++ ) {
            std::string name = property.at(i)->getName();
            if ( name == "ECH" || name == "PAS" || name == "HH" ) {
                count++;
            }
        }
    }
    return count == 3;
}

bool Academic::isEngMono() {
    auto owner = this->getOwner();
    int count = 0;
    if ( owner != nullptr ) {
        auto property = owner->getProperty();
        int n = property.size();
        for( int i = 0; i < n; i++ ) {
            std::string name = property.at(i)->getName();
            if ( name == "RCH" || name == "DWE" || name == "CPH" ) {
                count++;
            }
        }
    }
    return count == 3;
}

bool Academic::isHealthMono() {
    auto owner = this->getOwner();
    int count = 0;
    if ( owner != nullptr ) {
        auto property = owner->getProperty();
        int n = property.size();
        for( int i = 0; i < n; i++ ) {
            std::string name = property.at(i)->getName();
            if ( name == "LHI" || name == "BMH" || name == "OPT" ) {
                count++;
            }
        }
    }
    return count == 3;
}

bool Academic::isEnvMono() {
    auto owner = this->getOwner();
    int count = 0;
    if ( owner != nullptr ) {
        auto property = owner->getProperty();
        int n = property.size();
        for( int i = 0; i < n; i++ ) {
            std::string name = property.at(i)->getName();
            if ( name == "EV1" || name == "EV2" || name == "EV3" ) {
                count++;
            }
        }
    }
    return count == 3;
}

bool Academic::isSci1Mono() {
    auto owner = this->getOwner();
    int count = 0;
    if ( owner != nullptr ) {
        auto property = owner->getProperty();
        int n = property.size();
        for( int i = 0; i < n; i++ ) {
            std::string name = property.at(i)->getName();
            if ( name == "PHYS" || name == "B1" || name == "B2" ) {
                count++;
            }
        }
    }
    return count == 3;
}

bool Academic::isSci2Mono() {
    auto owner = this->getOwner();
    int count = 0;
    if ( owner != nullptr ) {
        auto property = owner->getProperty();
        int n = property.size();
        for( int i = 0; i < n; i++ ) {
            std::string name = property.at(i)->getName();
            if ( name == "EIT" || name == "ESC" || name == "C2" ) {
                count++;
            }
        }
    }
    return count == 3;
}

bool Academic::isMathMono() {
    auto owner = this->getOwner();
    int count = 0;
    if ( owner != nullptr ) {
        auto property = owner->getProperty();
        int n = property.size();
        for( int i = 0; i < n; i++ ) {
            std::string name = property.at(i)->getName();
            if ( name == "MC" || name == "DC" ) {
                count++;
            }
        }
    }
    return count == 2;
}

int Academic::charge() {
    auto owner = this->getOwner();
    bool mortgaged =  this->getMortgage();
    bool isMono = false;
    if ( !mortgaged && owner != nullptr ) {
        if ( this->block == "Arts1" ) {
            isMono = this->isArts1Mono();
        }
        if ( this->block == "Arts2" ) {
            isMono = this->isArts2Mono();
        }
        if ( this->block == "Eng" ) {
            isMono = this->isEngMono();
        }
        if ( this->block == "Health" ) {
            isMono = this->isHealthMono();
        }
        if ( this->block == "Env" ) {
            isMono = this->isEnvMono();
        }
        if ( this->block == "Sci1" ) {
            isMono = this->isSci1Mono();
        }
        if ( this->block == "Sci2" ) {
            isMono = this->isSci2Mono();
        }
        if ( this->block == "Math" ) {
            isMono = this->isMathMono();
        }
        
        int t = this->tuition.at(0);
        
        if( isMono ) {
            if ( this->improvements == 0 ) { 
                t *= 2;
            } else {
                t = this->tuition.at(this->improvements);
            }
        }
        return t;
    } else {
        return 0;
    }
}

    
