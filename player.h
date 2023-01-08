#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <memory>
#include <vector>

class Building;

class Player {

    int money;
    std::string name;
    char c;
    std::vector<std::shared_ptr<Building>> property;
    int cup;
    int currentBuilding;
    
    public:
    Player( int money, std::string name, char c, int cup, int currentBuilding );
    ~Player();
    void setCurBuilding ( int newBuilding );
    int getMoney();
    std::string getName();
    std::vector<std::shared_ptr<Building>> getProperty();
    int getCurBuilding();
    int getCup();
    void gainMoney( int amount );
    void loseMoney( int amount );
    void addProperty( std::shared_ptr<Building> building );
    void removeProperty( std::shared_ptr<Building> building );
    void setCup( int amount );
    char getChar();
    int totalWealth();
 
};



#endif