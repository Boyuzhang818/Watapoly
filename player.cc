#include "player.h"
#include "academic.h"
#include "building.h"
#include <algorithm>
#include <iostream>

Player::Player( int money, std::string name, char c, int cup, int currentBuilding ) 
    : money{ money }, name{ name }, c{c}, cup{ cup }, currentBuilding{ currentBuilding } {}

Player::~Player() {}



int Player::getMoney() {
    return money;
}
std::string Player::getName() {
    return name;
}

int Player::getCurBuilding() {
    return currentBuilding;
}

void Player::setCurBuilding ( int newBuilding ) {
    currentBuilding = newBuilding;
}

std::vector<std::shared_ptr<Building>> Player::getProperty() {
    return property;
}
int Player::getCup() {
    return cup; 
}
    
void Player::gainMoney( int amount ) {
    money += amount;
    std::cout << name << " gains $" << amount <<  "." << std::endl;
}

void Player::loseMoney( int amount ) {
    money -= amount;
    std::cout << name << " loses $" << amount <<  "." << std::endl;
}

void Player::addProperty( std::shared_ptr<Building> building ) {
    property.emplace_back(building);
    std::cout << name << " has a new building: " << building->getName() <<  "." << std::endl;
}

void Player::removeProperty( std::shared_ptr<Building> building ) {
    if ( std::find(property.begin(), property.end(), building) != property.end() ) {
        int n = property.size();
        for( int i = 0; i < n; i++ ) {
            if ( property.at(i) == building ) {
                property.erase(  property.begin() + i );
                break;
            }
        }
        std::cout << name << " no longer owns " << building->getName() <<  "." << std::endl;
    } else {
        std::cout << "You don't have this building: " << building->getName() << "." << std::endl;
    }
}

void Player::setCup( int amount ) {
    cup += amount;
}

char Player::getChar() {
    return c;
}

int Player::totalWealth() {
    int wealth = getMoney();
                    
    auto prop = getProperty();
    int n = prop.size();
    
    int cost = 0;
    for (int x = 0; x < n ; x++) {
        auto b = std::dynamic_pointer_cast<Chargeable>(prop[x]);
        if (b->getName() != "REV" && b->getName() != "PAC" && b->getName() != "REV" && b->getName() != "MKV" && b->getName() != "UWP" 
            && b->getName() != "V1" && b->getName() != "CIF"  ) {
                auto a = std::dynamic_pointer_cast<Academic>(b);
                cost = a->getPurchase();
                int imp = a->getImprovements();
                int impCost = a->getImproveCost();
                cost = cost + imp*impCost;
                wealth = cost + wealth;
                cost = 0;
            } else {
                cost = b->getPurchase();
                wealth = cost + wealth;
                cost = 0;
            }
    }
    return wealth;
}

