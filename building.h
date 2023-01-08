#ifndef _BUILDING_H_
#define _BUILDING_H_

#include <string>
#include <memory>
#include <vector>
#include "subject.h"

class Player;

class Building : public Subject {
    protected:
    std::string name;
    std::vector<std::shared_ptr<Player>> currentPlayers;
    
    public:
    Building( std::string name );
    virtual ~Building() = 0;
    virtual std::string getName() = 0;
    void addCurPlayer( std::shared_ptr<Player> Player );
    void removeCurPlayer( std::shared_ptr<Player> Player );
    std::vector<std::shared_ptr<Player>> getCurPlayers();
};

#endif


