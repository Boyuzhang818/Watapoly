#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <memory>
#include <string>
#include <iostream>

class Building;
class Player;
class Display;

class Board {
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::shared_ptr<Building>> buildings;
    int currentPlayer;
    std::shared_ptr<Display> d = nullptr;
    
    public:
    Board();
    ~Board();
    std::shared_ptr<Player> getCurPlayer();
    std::shared_ptr<Building> movePlayer( int steps );
    int getNumPlayers();
    void addPlayer( std::shared_ptr<Player> p );
    void addBuilding( std::shared_ptr<Building> b );
    void nextPlayer();
    void trade( std::string name, int give, std::string receive );
    void trade( std::string name, std::string give, std::string receive );
    void trade( std::string name, std::string give, int receive );
    void improve( std::shared_ptr<Player>, std::string name );
    void mortgage( std::string name );
    void unmortgage( std::string name );
    void bankrupt();
    void bankrupt(std::shared_ptr<Player>);
    void getAssets();
    void getAllAssets();
    void update(std::shared_ptr<Building>);
    void auction( std::shared_ptr<Building> );
    std::shared_ptr<Building> getBuilding(int);
    std::shared_ptr<Player> getPlayer(std::string);
    void sellImprove(std::shared_ptr<Player> p, std::string name);
    std::shared_ptr<Building> findBuilding( std::shared_ptr<Player>, std::string name );
    std::shared_ptr<Player> findPlayer( std::string name );
    void give( std::string name, int amount);
    
    friend std::ostream & operator<<( std::ostream & out, const Board & b );
};

std::ostream & operator<<( std::ostream & out, const Board & b );

#endif

