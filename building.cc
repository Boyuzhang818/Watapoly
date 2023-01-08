#include "building.h"

Building::Building( std::string name )
    : name{ name } {}

Building::~Building() {}

void Building::addCurPlayer( std::shared_ptr<Player> Player ) {
    currentPlayers.emplace_back(Player);
}

void Building::removeCurPlayer( std::shared_ptr<Player> Player ) {
      for ( auto it = currentPlayers.begin(); it != currentPlayers.end(); ++it ) {
        if ( *it == Player ) {
            currentPlayers.erase(it);
            break;
        }
    }
}

std::vector<std::shared_ptr<Player>> Building::getCurPlayers() {
    return currentPlayers;
}

