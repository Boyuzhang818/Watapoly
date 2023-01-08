#include "board.h"
#include "player.h"
#include "building.h"
#include "display.h"
#include <iostream>
#include <sstream>
#include "academic.h"
#include "chargeable.h"
#include "slc.h"
#include "gym.h"
#include "residences.h"
#include "osap.h"
#include "coop.h"
#include "dc.h"
#include "dice.h"
#include "goTims.h"
#include "goose.h"
#include "needles.h"
#include "tuition.h"

Board::Board() : currentPlayer{ 0 } {
    d = std::make_shared<Display>();
}

Board::~Board() {}

void Board::sellImprove(std::shared_ptr<Player> p, std::string name) {
    auto prop = p->getProperty();
    int n = prop.size();
    for (int x = 0; x < n; x++){
        if (prop[x]->getName() == name ){
            auto y = std::dynamic_pointer_cast<Academic>(prop[x]);
            int a = y->getImprovements();
            if ( a > 0 ) {
                int amount = 0.5 * y->getImproveCost();
                players[currentPlayer]->gainMoney(amount);
                y->decImprovements();
                d->notify(prop[x]);
            } else {
                std::cout << name << " has no improvements to sell." << std::endl;
            }
        }
    }
}

void Board::give( std::string name, int amount) {
    auto curPlayer = players[currentPlayer];
    if ( name == "bank" ) {
        if ( curPlayer->getMoney() >= amount ) {
            curPlayer->loseMoney(amount);
            if ( curPlayer->getCurBuilding() == 10 ) {
                auto dc = std::dynamic_pointer_cast<DC>(buildings[10]);
                int turns = -1 * dc->getTurns(curPlayer->getChar());
                dc->addTurns(curPlayer->getChar(), turns-1);
            }
        } else {
            std::cout << "You don't have enough money to pay BANK." << std::endl;
        }
    } else {
        auto p = getPlayer(name);
        if ( p ) {
            
            if ( curPlayer->getMoney() >= amount ) {
                curPlayer->loseMoney(amount);
                p->gainMoney(amount);
            } else {
                std::cout << "You don't have enough money to pay " << name << std::endl;
            }
        } else {
            std::cout << "There is no such player." << std::endl;
        }
    }
}

std::shared_ptr<Building> Board::getBuilding(int a) {
    return buildings[a];
}

void Board::update(std::shared_ptr<Building> b) {
    d->notify(b);
}

std::shared_ptr<Player> Board::getPlayer(std::string name) {
    int n = players.size();
    for (int x = 0; x < n; x++){
        if (name == players[x]->getName()){
            return players[x];
        }
    }
    
    return nullptr;
}

int Board::getNumPlayers() {
    int n = players.size();
    return n;
}

std::shared_ptr<Player> Board::getCurPlayer() {
    return players.at(currentPlayer);
}

std::shared_ptr<Building> Board::movePlayer(int steps) {
    int n = players[currentPlayer]->getCurBuilding();
    auto p = players[currentPlayer];
    int x = steps + n;
    
    if ( x > 39 ){
        x = x - 40;
        if ( x == 0 ) {
            std::cout << "You have landed on " << buildings[0]->getName() << "." << std::endl;
        } else {
            std::cout << "You have passed " << buildings[0]->getName() << "." << std::endl;
        }
        players.at(currentPlayer)->gainMoney(200);
    }
    
    buildings[n]->removeCurPlayer(players[currentPlayer]);
    players[currentPlayer]->setCurBuilding(x);
    buildings[x]->addCurPlayer(players.at(currentPlayer));

    if (p->getCurBuilding() == 1) {
        auto building = getBuilding(1);
        auto a = std::dynamic_pointer_cast<Academic>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(1));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage() ) {
                int n = a->getImprovements();
                auto tui = a->getTuition();
                int amount = tui[n];
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName() << " " << amount << "!" << std::endl;
                    
                }
            }
        }
    } else if (p->getCurBuilding() == 2) {
        auto building = getBuilding(2);
        auto a = std::dynamic_pointer_cast<SLC>(building);
        int n = a->draw();
        if ( n == -11) {
            p->setCup(1);
            auto slc1 = std::dynamic_pointer_cast<SLC>(buildings[17]);
            slc1->addCup(-1);
            auto slc3 = std::dynamic_pointer_cast<SLC>(buildings[33]);
            slc3->addCup(-1);
            auto n1 = std::dynamic_pointer_cast<Needles>(buildings[7]);
            n1->addCup(-1);
            auto n2 = std::dynamic_pointer_cast<Needles>(buildings[22]);
            n2->addCup(-1);
            auto n3 = std::dynamic_pointer_cast<Needles>(buildings[36]);
            n3->addCup(-1);
            std::cout << "Lucky you! One cup for you!" << std::endl;
        } else {
            if (n == 0) {
                std::cout << "You are going to move to Collect OSAP" << std::endl;
                movePlayer(-2);
            } else if (n == 10) {
                std::cout << "You are going to move to DC Tims Lines" << std::endl;
                movePlayer(8);
            } else if (n == -3) {
                players.at(currentPlayer)->gainMoney(200);
                movePlayer(37);
            }{
                std::cout << "You are going to move " << n << " steps" << std::endl;
                movePlayer(n);
            }
        }
    } else if (p->getCurBuilding() == 3) {
        auto building = getBuilding(3);
        auto a = std::dynamic_pointer_cast<Academic>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(3));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int amount = a->charge();
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName() << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 4) {
        auto building = getBuilding(4);
        auto a = std::dynamic_pointer_cast<Tuition>(building);
        int wealth = p->totalWealth();
            
        std::cout << "Pay $300 tuition (1) or lose 10% of your total worth " << wealth << " (2)" << std::endl;
                    
        std::string s;
        while(std::cin >> s) {
            if (s == "1") {
                if (p->getMoney() > 300) {
                    p->loseMoney(300);
                    break;
                } else {
                    std::cout << "You do not have enough money to pay bank $300." << std::endl;
                    break;
                }
            } else if (s == "2") {
                p->loseMoney(0.1*wealth);
                break;
            } else if (s == "assets" || s == "all") {
                std::cout << "You cannot see assets while paying tuition."  << std::endl;
            } else {
                std::cout << "Please choose again" << std::endl;
            }
        }
    } else if (p->getCurBuilding() == 5) {
        auto building = getBuilding(5);
        auto a = std::dynamic_pointer_cast<Residences>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(5));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int amount = a->charge();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    
                    a->getOwner()->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << a->getOwner() << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 6) {
        auto building = getBuilding(6);
        auto a = std::dynamic_pointer_cast<Academic>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(6));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int n = a->getImprovements();
                auto tui = a->getTuition();
                int amount = tui[n];
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName() << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 7) {
    auto building = getBuilding(7);
    auto c = std::dynamic_pointer_cast<Needles>(building);
    std::cout << "You have reached " << c->getName() << "! Something will happen to your savings!" << std::endl;
    int money = c->draw();
        if ( money > 0 ) {
            p->gainMoney(money);
        } else if (money == -11) {
            p->setCup(1);
            auto slc2 = std::dynamic_pointer_cast<SLC>(buildings[17]);
            slc2->addCup(-1);
            auto slc3 = std::dynamic_pointer_cast<SLC>(buildings[33]);
            slc3->addCup(-1);
            auto slc1 = std::dynamic_pointer_cast<SLC>(buildings[2]);
            slc1->addCup(-1);
            auto n2 = std::dynamic_pointer_cast<Needles>(buildings[22]);
            n2->addCup(-1);
            auto n3 = std::dynamic_pointer_cast<Needles>(buildings[36]);
            n3->addCup(-1);
        } else {
            if ( p->getMoney() + money >= 0 ) {
                p->loseMoney(abs(money));
            } else {
                std::cout << "You don't have enough money to pay bank " << money << "!" << std::endl;
            }
        }
    } else if (p->getCurBuilding() == 8) {
        auto building = getBuilding(8);
        auto a = std::dynamic_pointer_cast<Academic>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(8));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int n = a->getImprovements();
                auto tui = a->getTuition();
                int amount = tui[n];
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 9) {
        auto building = getBuilding(9);
        auto a = std::dynamic_pointer_cast<Academic>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(9));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int n = a->getImprovements();
                auto tui = a->getTuition();
                int amount = tui[n];
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 10) {
        auto building = getBuilding(10);
        auto a = std::dynamic_pointer_cast<DC>(building);
        int turns = a->getTurns(p->getChar());
        if (turns == 0 || turns == 1) {
                std::cout << "You are now in the DC Tims Line. Please choose the following to get out of line." << std::endl;
                std::cout << "Please enter (1)roll (2)pay $50 (3)cup" << std::endl;
                std::string x;
                while(true) {
                    if (std::cin >> x) {
                        if ( x == "roll" ) {
                            Dice d1;
                            //Dice d2;
                            int r1 = d1.roll();
                            std::cout << "You rolled " << r1 << std::endl;
                            std::cout << "Roll again? (Y/N)" << std::endl; 
                            int r2;
                            std::string z;
                            while (true) {
                                std::cin >> z;
                                if (z == "Y") {
                                    int u = d1.roll();
                                    r2 = u;
                                    std::cout << "You rolled a " << r2 << std::endl;
                                    break;
                                } else {
                                    std::cout << "You have to roll again!" << std::endl;
                                    z = "Y";
                                }
                            }
                            
                            if ( r1 == r2 ) {
                                std::cout << "You are free!" << std::endl;
                                movePlayer(r1+r2);
                                int t = -1 * turns - 1;
                                a->addTurns(p->getChar(), t);
                                break;
                            } else {
                                std::cout << "Oops! You are stuck here." << std::endl;
                                a->addTurns(p->getChar(), 1);
                                break;
                            }
                        } else if (x == "pay") {
                            if ( p->getMoney() > 50 ) {
                                p->loseMoney(50);
                                std::cout << "You are free" << std::endl;
                                int t = -1 * turns - 1;
                                a->addTurns(p->getChar(), t);
                                break;
                            } else {
                                std::cout << "You don't have enough money to pay bank 50!" << std::endl;
                                break;
                            }
                        } else if ( x == "cup" ) {
                            if ( p->getCup() > 0 ) {
                                    p->setCup(-1);
                                    std::cout << "You are free!" << std::endl;
                                    int t = -1 * turns - 1;
                                    a->addTurns(p->getChar(), t);
                                    break;
                            } else {
                                std::cout << "You don't have any CUPS!" << std::endl;
                                std::cout << "Please enter (1)roll or (2)pay!" << std::endl;
                                continue;
                            }
                        } else {
                            std::cout << "Please enter (1)roll (2)pay $50 (3)cup!" << std::endl;
                        }
                    }
                }
            }
            
            if (turns == 2) {
                std::cout << "You are now in the DC Tims Line. Please choose the following to get out of line." << std::endl;
                std::cout << "Please enter (1)roll (2)pay $50 (3)cup" << std::endl;
                std::string x;
                while(true) {
                    if (std::cin >> x) {
                        if ( x == "roll" ) {
                            Dice d1;
                            //Dice d2;
                            int r1 = d1.roll();
                            std::cout << "You rolled " << r1 << std::endl;
                            std::cout << "Roll again? (Y/N)" << std::endl; 
                            int r2;
                            std::string z;
                            while (true) {
                                std::cin >> z;
                                if (z == "Y") {
                                    int u = d1.roll();
                                    r2 = u;
                                    std::cout << "You rolled a " << r2 << std::endl;
                                    break;
                                } else {
                                    std::cout << "You have to roll again!" << std::endl;
                                    z = "Y";
                                }
                            }
                            
                            if ( r1 == r2 ) {
                                std::cout << "You are free!" << std::endl;
                                movePlayer(r1+r2);
                                int t = -1 * turns - 1;
                                a->addTurns(p->getChar(), t);
                                break;
                            } else {
                                std::cout << "Choose between (1)pay $50 or (2)cup to get out of here" << std::endl;
                                std::string x;
                                while(true) {
                                        if (std::cin >> x) {
                                            if ( x == "cup" ) {
                                                if (p->getCup() > 0) {
                                                    p->setCup(-1);
                                                    std::cout << "You are free!" << std::endl;
                                                    int t = -1 * turns - 1;
                                                    a->addTurns(p->getChar(), t);
                                                    break;
                                                } else {
                                                    std::cout << "You do not have any CUPs! Please choose (1)pay $50." << std::endl;
                                                }
                                            } else if (x == "pay") {
                                                if ( p->getMoney() > 50 ) {
                                                    p->loseMoney(50);
                                                    std::cout << "You are free!" << std::endl;
                                                    int t = -1 * turns - 1;
                                                    a->addTurns(p->getChar(), t);
                                                    break;
                                                }  else {
                                                    std::cout << "You don't have enough money to pay bank 50!" << std::endl;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                //break;
                            }
                        } else if (x == "pay") {
                            if ( p->getMoney() > 50 ) {
                                p->loseMoney(50);
                                std::cout << "You are free" << std::endl;
                                int t = -1 * turns - 1;
                                a->addTurns(p->getChar(), t);
                                break;
                            } else {
                                std::cout << "You don't have enough money to pay bank 50!" << std::endl;
                                break;
                            }
                        } else if ( x == "cup" ) {
                            if ( p->getCup() > 0 ) {
                                    p->setCup(-1);
                                    std::cout << "You are free!" << std::endl;
                                    int t = -1 * turns - 1;
                                    a->addTurns(p->getChar(), t);
                                    break;
                            } else {
                                std::cout << "You don't have any CUPS!" << std::endl;
                                std::cout << "Please enter (1)roll or (2)pay!" << std::endl;
                                continue;
                            }
                        } else {
                            std::cout << "Please enter (1)roll or (2)pay or (3)cup!" << std::endl;
                        }
                    }
                }
            }
        
    } else if (p->getCurBuilding() == 11) {
        auto building = getBuilding(11);
        auto a = std::dynamic_pointer_cast<Academic>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(11));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int n = a->getImprovements();
                auto tui = a->getTuition();
                int amount = tui[n];
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 12) {
        auto building = getBuilding(12);
        auto a = std::dynamic_pointer_cast<Gym>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(12));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int amount = a->charge();
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 13) {
        auto building = getBuilding(13);
        auto a = std::dynamic_pointer_cast<Academic>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(13));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int n = a->getImprovements();
                auto tui = a->getTuition();
                int amount = tui[n];
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 14) {
        auto building = getBuilding(14);
        auto a = std::dynamic_pointer_cast<Academic>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(14));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int n = a->getImprovements();
                auto tui = a->getTuition();
                int amount = tui[n];
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 15) {
        auto building = getBuilding(15);
        auto a = std::dynamic_pointer_cast<Residences>(building);
        auto owner = a->getOwner();
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s) {
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(15));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int amount = a->charge();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    a->getOwner()->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 16) {
        auto building = getBuilding(16);
        auto a = std::dynamic_pointer_cast<Academic>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(16));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int n = a->getImprovements();
                auto tui = a->getTuition();
                int amount = tui[n];
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money!" << std::endl;
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 17) {
        auto building = getBuilding(17);
        auto a = std::dynamic_pointer_cast<SLC>(building);
        int n = a->draw();
        if ( n == -11) {
            p->setCup(1);
            auto n1 = std::dynamic_pointer_cast<Needles>(buildings[7]);
            n1->addCup(-1);
            auto slc3 = std::dynamic_pointer_cast<SLC>(buildings[33]);
            slc3->addCup(-1);
            auto slc1 = std::dynamic_pointer_cast<SLC>(buildings[2]);
            slc1->addCup(-1);
            auto n2 = std::dynamic_pointer_cast<Needles>(buildings[22]);
            n2->addCup(-1);
            auto n3 = std::dynamic_pointer_cast<Needles>(buildings[36]);
            n3->addCup(-1);
        } else {
            if (n == 0) {
                std::cout << "You are going to move to Collect OSAP" << std::endl;
                movePlayer(23);
            } else if (n == 10) {
                std::cout << "You are going to move to DC Tims Lines" << std::endl;
                movePlayer(33);
            } else {
                std::cout << "You are going to move " << n << " steps" << std::endl;
                movePlayer(n);
            }
        }
    } else if (p->getCurBuilding() == 18) {
        auto building = getBuilding(18);
        auto a = std::dynamic_pointer_cast<Academic>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(18));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int n = a->getImprovements();
                auto tui = a->getTuition();
                int amount = tui[n];
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money!" << std::endl;
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 19) {
        auto building = getBuilding(19);
        auto a = std::dynamic_pointer_cast<Academic>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(19));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int n = a->getImprovements();
                auto tui = a->getTuition();
                int amount = tui[n];
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 20) {
        std::cout << "Goose Attack!!!" << std::endl;
    } else if (p->getCurBuilding() == 21) {
        auto building = getBuilding(21);
        auto a = std::dynamic_pointer_cast<Academic>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(21));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int n = a->getImprovements();
                auto tui = a->getTuition();
                int amount = tui[n];
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 22) {
    auto building = getBuilding(22);
    auto c = std::dynamic_pointer_cast<Needles>(building);
    std::cout << "You have reached " << c->getName() << "! Something will happen to your savings!" <<std::endl;
    int money = c->draw();
        if ( money > 0 ) {
            p->gainMoney(money);
        } else if (money == -11) {
            p->setCup(1);
            auto n1 = std::dynamic_pointer_cast<Needles>(buildings[7]);
            n1->addCup(-1);
            auto slc3 = std::dynamic_pointer_cast<SLC>(buildings[33]);
            slc3->addCup(-1);
            auto slc1 = std::dynamic_pointer_cast<SLC>(buildings[2]);
            slc1->addCup(-1);
            auto slc2 = std::dynamic_pointer_cast<SLC>(buildings[17]);
            slc2->addCup(-1);
            auto n3 = std::dynamic_pointer_cast<Needles>(buildings[36]);
            n3->addCup(-1);
        }{
            if ( p->getMoney() + money >= 0 ) {
                p->loseMoney(abs(money));
            } else {
                std::cout << "You don't have enough money to pay bank " << money << "!" << std::endl;
            }
        }
    }  else if (p->getCurBuilding() == 23) {
        auto building = getBuilding(23);
        auto a = std::dynamic_pointer_cast<Academic>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(23));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int n = a->getImprovements();
                auto tui = a->getTuition();
                int amount = tui[n];
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money!" << std::endl;
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 24) {
    auto building = getBuilding(24);
    auto a = std::dynamic_pointer_cast<Academic>(building);
    if (a->getOwner() == nullptr) { 
        std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
        std::string s;
        while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(24));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
    } else {
        if ( a->getOwner() != p && !a->getMortgage()  ) {
            auto owner = a->getOwner();
            int amount = a->charge();
            if ( p->getMoney() > amount ) {
                p->loseMoney(amount);
                owner->gainMoney(amount);
            } else {
                std::cout << "You don't have enough money!" << std::endl;
                std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
            }
        }
    }
} else if (p->getCurBuilding() == 25) {
        auto building = getBuilding(25);
        auto a = std::dynamic_pointer_cast<Residences>(building);
        auto owner = a->getOwner();
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(25));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int amount = a->charge();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    a->getOwner()->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 26) {
    auto building = getBuilding(26);
    auto a = std::dynamic_pointer_cast<Academic>(building);
    if (a->getOwner() == nullptr) { 
        std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
        std::string s;
        while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(26));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
    } else {
        if ( a->getOwner() != p && !a->getMortgage()  ) {
            
            auto owner = a->getOwner();
            //auto tui = a->getTuition();
            int amount = a->charge();
            if ( p->getMoney() > amount ) {
                p->loseMoney(amount);
                owner->gainMoney(amount);
            } else {
                std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
            }
        }
    }
} else if (p->getCurBuilding() == 27) {
    auto building = getBuilding(27);
    auto a = std::dynamic_pointer_cast<Academic>(building);
    if (a->getOwner() == nullptr) { 
        std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
        std::string s;
        while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(27));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
    } else {
        if ( a->getOwner() != p && !a->getMortgage()  ) {
            auto owner = a->getOwner();
            int amount = a->charge();
            if ( p->getMoney() > amount ) {
                p->loseMoney(amount);
                owner->gainMoney(amount);
            } else {
                std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                
            }
        }
    }
} else if (p->getCurBuilding() == 28) {
        auto building = getBuilding(28);
        auto a = std::dynamic_pointer_cast<Gym>(building);
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(28));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int amount = a->charge();
                auto owner = a->getOwner();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    owner->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 29) {
    auto building = getBuilding(29);
    auto a = std::dynamic_pointer_cast<Academic>(building);
    if (a->getOwner() == nullptr) { 
        std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
        std::string s;
        while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(29));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
    } else {
        if ( a->getOwner() != p && !a->getMortgage()  ) {
            auto owner = a->getOwner();
            int amount = a->charge();
            if ( p->getMoney() > amount ) {
                p->loseMoney(amount);
                owner->gainMoney(amount);
            } else {
                std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
            }
        }
    }
} else if (p->getCurBuilding() == 30) {
    std::cout << "You have reached Go to Tims!" << std::endl;
    std::cout << "You are going to move to DC Tims Lines" << std::endl;
    auto dc = std::dynamic_pointer_cast<DC>(buildings[10]);
    dc->addTurns(p->getChar(), 1);
    movePlayer(-20);

} else if (p->getCurBuilding() == 31) {
    auto building = getBuilding(31);
    auto a = std::dynamic_pointer_cast<Academic>(building);
    if (a->getOwner() == nullptr) { 
        std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
        std::string s;
       while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(31));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
    } else {
        if ( a->getOwner() != p && !a->getMortgage()  ) {
            auto owner = a->getOwner();
            int amount = a->charge();
            if ( p->getMoney() > amount ) {
                p->loseMoney(amount);
                owner->gainMoney(amount);
            } else {
                std::cout << "You don't have enough money to pay " << owner->getName()  << " " << amount << "!" << std::endl;
            }
        }
    }
} else if (p->getCurBuilding() == 32) {
    auto building = getBuilding(32);
    auto a = std::dynamic_pointer_cast<Academic>(building);
    if (a->getOwner() == nullptr) { 
        std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
        std::string s;
        while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(32));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
    } else {
        if ( a->getOwner() != p && !a->getMortgage()  ) {
            auto owner = a->getOwner();
            int amount = a->charge();
            if ( p->getMoney() > amount ) {
                p->loseMoney(amount);
                owner->gainMoney(amount);
            } else {
                std::cout << "You don't have enough money to pay " << owner->getName() << " " << amount << "!" << std::endl;
            }
        }
    }
} else if (p->getCurBuilding() == 33) {
        auto building = getBuilding(33);
        auto a = std::dynamic_pointer_cast<SLC>(building);
        int n = a->draw();
        if ( n == -11) {
            p->setCup(1);
            auto n1 = std::dynamic_pointer_cast<Needles>(buildings[7]);
            n1->addCup(-1);
            auto slc3 = std::dynamic_pointer_cast<SLC>(buildings[33]);
            slc3->addCup(-1);
            auto n2 = std::dynamic_pointer_cast<Needles>(buildings[22]);
            n2->addCup(-1);
            auto slc2 = std::dynamic_pointer_cast<SLC>(buildings[17]);
            slc2->addCup(-1);
            auto n3 = std::dynamic_pointer_cast<Needles>(buildings[36]);
            n3->addCup(-1);
        } else {
            if (n == 0) {
                std::cout << "You are going to move to Collect OSAP" << std::endl;
                movePlayer(7);
            } else if (n == 10) {
                std::cout << "You are going to move to DC Tims Lines" << std::endl;
                movePlayer(17);
            } else {
                std::cout << "You are going to move " << n << " steps" << std::endl;
                movePlayer(n);
            }
        }
    } else if (p->getCurBuilding() == 34) {
    auto building = getBuilding(34);
    auto a = std::dynamic_pointer_cast<Academic>(building);
    if (a->getOwner() == nullptr) { 
        std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
        std::string s;
        while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(34));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
    } else {
        if ( a->getOwner() != p && !a->getMortgage()  ) {
            auto owner = a->getOwner();
            int amount = a->charge();
            if ( p->getMoney() > amount ) {
                p->loseMoney(amount);
                owner->gainMoney(amount);
            } else {
                std::cout << "You don't have enough money to pay " << owner->getName() << " " << amount << "!" << std::endl;
            }
        }
    }
} else if (p->getCurBuilding() == 35) {
        auto building = getBuilding(35);
        auto a = std::dynamic_pointer_cast<Residences>(building);
        auto owner = a->getOwner();
        if (a->getOwner() == nullptr) { 
            std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
            std::string s;
            while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(35));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
        } else {
            if (a->getOwner() != p && !a->getMortgage()  ) {
                int amount = a->charge();
                if ( p->getMoney() > amount ) {
                    p->loseMoney(amount);
                    
                    a->getOwner()->gainMoney(amount);
                } else {
                    std::cout << "You don't have enough money to pay " << owner->getName() << " " << amount << "!" << std::endl;
                }
            }
        }
    } else if (p->getCurBuilding() == 36) {
    auto building = getBuilding(36);
    auto c = std::dynamic_pointer_cast<Needles>(building);
    std::cout << "You have reached " << c->getName() << "! Something will happen to your savings!" << std::endl;
    int money = c->draw();
    if ( money > 0 ) {
        p->gainMoney(money);
    } else if (money == -11) {
        p->setCup(1);
            auto n1 = std::dynamic_pointer_cast<Needles>(buildings[7]);
            n1->addCup(-1);
            auto slc3 = std::dynamic_pointer_cast<SLC>(buildings[33]);
            slc3->addCup(-1);
            auto n2 = std::dynamic_pointer_cast<Needles>(buildings[22]);
            n2->addCup(-1);
            auto slc2 = std::dynamic_pointer_cast<SLC>(buildings[17]);
            slc2->addCup(-1);
            auto slc1 = std::dynamic_pointer_cast<SLC>(buildings[2]);
            slc1->addCup(-1);
    } {
        if ( p->getMoney() + money >= 0 ) {
            p->loseMoney(abs(money));
        } else {
            std::cout << "You don't have enough money to pay bank " << money << "!" << std::endl;
        }
    }
} else if (p->getCurBuilding() == 37) {
    auto building = getBuilding(37);
    auto a = std::dynamic_pointer_cast<Academic>(building);
    if (a->getOwner() == nullptr) { 
        std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
        std::string s;
        while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(37));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
    } else {
        if ( a->getOwner() != p && !a->getMortgage()  ) {
            auto owner = a->getOwner();
            int amount = a->charge();
            if ( p->getMoney() > amount ) {
                p->loseMoney(amount);
                owner->gainMoney(amount);
            } else {
                std::cout << "You don't have enough money to pay " << owner->getName() << " " << amount << "!" << std::endl;
            }
        }
    }
} else if (p->getCurBuilding() == 38) {
    auto building = getBuilding(38);
    auto c = std::dynamic_pointer_cast<Coop>(building);
    if ( p->getMoney() > 150 ) {
        p->loseMoney(150);
    } else {
        std::cout << "You don't have enough money to pay bank 150!" << std::endl;
    }
} else if (p->getCurBuilding() == 39) {
    auto building = getBuilding(39);
    auto a = std::dynamic_pointer_cast<Academic>(building);
    if (a->getOwner() == nullptr) { 
        std::cout << "Do you want to purchase " << a->getName() << " ? (Y/N)" << std::endl;
        std::string s;
        while (std::cin >> s){
                if (s == "Y") {
                    if (p->getMoney() >= a->getPurchase()) {
                        p->loseMoney(a->getPurchase());
                        p->addProperty(getBuilding(39));
                        a->setOwner(p);
                        break;
                    } else {
                        std::cout << "You don't have enough money!" << std::endl;
                        auction(building);
                        break;
                    }
                } else if (s == "N") {
                    auction(building);
                    break;
                } else {
                    std::cout << "Please choose between Y or N" << std::endl;
                }
            }
    } else {
        if (a->getOwner() != p && !a->getMortgage()  ) {
            auto owner = a->getOwner();
            int amount = a->charge();
            if ( p->getMoney() > amount ) {
                p->loseMoney(amount);
                owner->gainMoney(amount);
            } else {
                std::cout << "You don't have enough money to pay " << owner->getName() << " " << amount << "!" << std::endl;
            }
        }
    }
}

    d->notify(buildings[n]);
    d->notify(buildings[x]);
    
    return buildings[x];
}

void Board::addPlayer(std::shared_ptr<Player> p) {
    players.emplace_back(p);
    buildings[p->getCurBuilding()]->addCurPlayer(p);
    d->notify(buildings[0]);
}

void Board::addBuilding(std::shared_ptr<Building> b){
    buildings.emplace_back(b);
    b->attach(d);
}

void Board::nextPlayer() {
    int x = currentPlayer + 1;
    int n = players.size() - 1;
    
    if (x > n) {
        x = 0;
    }
    
    currentPlayer = x;
    
    if (players[currentPlayer]->getCurBuilding() == 10){
        auto dc = std::dynamic_pointer_cast<DC>(buildings[10]);
        int turns = dc->getTurns(players[currentPlayer]->getChar());
        if (turns != -1) {
            movePlayer(0);
        }
    }
}

std::shared_ptr<Building> Board::findBuilding(std::shared_ptr<Player> p, std::string name) {
    auto a = p->getProperty();
    int n = a.size();
    for (int x = 0; x < n; ++x){
        if (name == a.at(x)->getName()) {
            return a.at(x);
        }
    }
    
    return nullptr;
}

std::shared_ptr<Player> Board::findPlayer(std::string name){
    int n = players.size();
    for (int x = 0; x < n; x++ ) {
        if (name == players.at(x)->getName()){
            return players.at(x);
        }
    }
    return nullptr;
}

void Board::trade(std::string name, int give, std::string receive){
    std::cout << "Does " << name << " agree to trade " << receive << " with " << give << " ? (Y/N)" << std::endl;
    
    while (true) {
        std::string s;
        std::cin >> s;
        if (s == "Y") {
            if (players[currentPlayer]->getMoney() > give){
                auto p = findPlayer(name);
                if (p != nullptr){
                    auto b = findBuilding(p, receive);
                    auto c = std::dynamic_pointer_cast<Chargeable>(b);
                    if (b != nullptr && !c->getMortgage()) {
                        
                         players.at(currentPlayer)->addProperty(b);
                         players.at(currentPlayer)->loseMoney(give);
                         p->removeProperty(b);
                         p->gainMoney(give);
                         auto c = std::dynamic_pointer_cast<Chargeable>(b);
                         c->setOwner(players.at(currentPlayer));
                         
                    } else {
                        std::cout << name << " doesnt't have property " << receive << std::endl;
                    }
                } else {
                    std::cout << "Doesn't have player " << name << std::endl;
                }
            } else {
                std::cout << players.at(currentPlayer)->getName() << " doesn't have enough money" << std::endl;
            }
            break;
        } else if (s == "N") {
            break;
        } else {
        std:: cout << "Please choose between Y or N" << std::endl;
        }
    }
}

void Board::trade(std::string name, std::string give, std::string receive) {
    std::cout << "Does " << name << " agree to trade " << receive << " with " << give << " ? (Y/N)" << std::endl;

    
    while (true) {
        std::string s;
        std::cin >> s;
        if (s == "Y") {
            auto p = findPlayer(name);
            if (p != nullptr) {
                auto p1 = findBuilding(players.at(currentPlayer), give);
                auto c1 = std::dynamic_pointer_cast<Chargeable>(p1);
                if (p1 != nullptr && !c1->getMortgage()) {
                    auto p2 = findBuilding(p, receive);
                    auto c2 = std::dynamic_pointer_cast<Chargeable>(p2);
                    if (p2 != nullptr && !c2->getMortgage()) {
                        players.at(currentPlayer)->addProperty(p2);
                        players.at(currentPlayer)->removeProperty(p1);
                        p->removeProperty(p2);
                        p->addProperty(p1);
                        auto c1 = std::dynamic_pointer_cast<Chargeable>(p1);
                        c1->setOwner(p);
                        auto c2 = std::dynamic_pointer_cast<Chargeable>(p2);
                        c2->setOwner(players.at(currentPlayer));
                    } else {
                        std::cout << name << " doesn't have property " << receive << std::endl;
                    }
                } else {
                    std::cout << players.at(currentPlayer)->getName() << " doesn't have property " << give << std::endl;
                }
            } else {
                std::cout << "Doesn't have player " << name << std::endl;
            }
            break;
        } else if (s == "N"){
            break;
        } else {
            std:: cout << "Please choose between Y or N" << std::endl;
        }
    }
}

void Board::trade(std::string name, std::string give, int receive) {
    std::cout << "Does " << name << " agree to trade " << receive << " with " << give << " ? (Y/N)" << std::endl;

    while (true) {
        std::string s;
        std::cin >> s;
        if (s == "Y") {
            auto p = findPlayer(name);
            if (p != nullptr) {
                auto p1 = findBuilding(players.at(currentPlayer), give);
                auto c1 = std::dynamic_pointer_cast<Chargeable>(p1);
                if (p1 != nullptr && !c1->getMortgage()) {
                    if (players[currentPlayer]->getMoney() > receive) {
                        players[currentPlayer]->gainMoney(receive);
                        players[currentPlayer]->removeProperty(p1);
                        p->addProperty(p1);
                        p->loseMoney(receive);
                        
                        auto c = std::dynamic_pointer_cast<Chargeable>(p1);
                        c->setOwner(p);
                    } else {
                        std::cout << name << " doesn't have enough money" << std::endl;
                    }
                } else {
                    std::cout << players.at(currentPlayer)->getName() << " doesn't have property " << give << std::endl;
                }
            } else {
                std::cout << "Doesn't have player " << name << std::endl;
            }
            break;
        } else if (s == "N"){
            break;
        } else {
            std:: cout << "Please choose between Y or N" << std::endl;
        }
    }
}

void Board::auction(std::shared_ptr<Building> b){
    int bid = 0;
    std::shared_ptr<Player> p;
    
    std::cout << "Auction for " << b->getName() << " starts!!" << std::endl;
    std::cout << "Please enter your bid in the format of [Name] [Price]. Type F to end the auction" << std::endl;
    
    std::string s;
    int a;
    

    while (true) {
            std::cin >> s;
       
            if ( s == "F"){
                break;
            }
            
            auto temp  = findPlayer(s);
            if (temp == nullptr) {
                std::cout << "No such player!" << std::endl;
            }
            
            if (! (std::cin >> a)) {
                if (std::cin.eof()) break;
                std::cout << "Please enter your name followed by your bid!" << std::endl;  
            
                std::cin.clear();
                std::cin.ignore();
            } else {
            
                if (bid < a) {
                    bid = a;
                    //std::cin >> s;
                    p = temp;
                }
            }

    }
    
    if (bid > 0) {
        p->addProperty(b);
        p->loseMoney(bid);
        
        if ( b->getName() == "MKV" || b->getName() == "UWP" || b->getName() == "V1" || b->getName() == "REV") {
            auto r = std::dynamic_pointer_cast<Residences>(b);
            r->setOwner(p);
        } else if (b->getName() == "PAC" || b->getName() == "CIF") {
            auto g = std::dynamic_pointer_cast<Gym>(b);
            g->setOwner(p);
        } else {
            auto ac = std::dynamic_pointer_cast<Academic>(b);
            ac->setOwner(p);
        }
    }
}

void Board::improve( std::shared_ptr<Player> p , std::string name ) {
    auto b = this->findBuilding(p, name);
    if ( b != nullptr ) {
        auto a = std::dynamic_pointer_cast<Academic>(b);
        int cost = a->getImproveCost();
        if ( p->getMoney() >= cost ) {
            if ( a->getImprovements() == 5 ) {
                std::cout << "You cannot improve this building anymore." << std::endl;
            } else {
                bool isMono = false;
                if ( a->getBlock() == "Arts1" ) {
                    isMono = a->isArts1Mono();
                }
                if ( a->getBlock() == "Arts2" ) {
                    isMono = a->isArts2Mono();
                }
                if ( a->getBlock() == "Eng" ) {
                    isMono = a->isEngMono();
                }
                if ( a->getBlock() == "Health" ) {
                    isMono = a->isHealthMono();
                }
                if ( a->getBlock() == "Env" ) {
                    isMono = a->isEnvMono();
                }
                if ( a->getBlock() == "Sci1" ) {
                    isMono = a->isSci1Mono();
                }
                if ( a->getBlock() == "Sci2" ) {
                    isMono = a->isSci2Mono();
                }
                if ( a->getBlock() == "Math" ) {
                    isMono = a->isMathMono();
                }
    
                if (isMono) {
                    a->incImprovements();
                    p->loseMoney(cost);
                    d->notify(b);
                    std::cout << a->getName() << " has been improved." << std::endl;
                } else {
                    std::cout << "You have not achieved Monopoly yet." << std::endl;
                }
            }
        } else {
            std::cout << "You don't have enough money to improve " << name << "." << std::endl;
        }
    } else {
        std::cout << "You don't have property " << name << std::endl;
    }
}

void Board::mortgage( std::string name ) {
    auto player = players.at(currentPlayer);
    auto b = this->findBuilding(player, name);
    if ( b != nullptr ) {
        std::string name = b->getName();
        if ( name != "PAC" && name != "CIF" && name != "UWP" && name != "MKV" && name != "V1" && name != "REV" ) {
            auto c = std::dynamic_pointer_cast<Academic>(b);
            int improvements = c->getImprovements();
            bool mortgaged = c->getMortgage();
            if ( mortgaged ) {
                std::cout << "This building is already mortgaged!" << std::endl;
             } else if ( improvements != 0 ) {
                std::cout << "You need to sell improvements first!" << std::endl;
            } else {
                c->mortgage();
                int cost = c->getPurchase() / 2;
                player->gainMoney(cost);
            }
        } else {
             auto c = std::dynamic_pointer_cast<Chargeable>(b);
             bool mortgaged = c->getMortgage();
             if ( mortgaged ) {
                std::cout << "This building is already mortgaged!" << std::endl;
            } else {
                c->mortgage();
                int cost = c->getPurchase() / 2;
                player->gainMoney(cost);
            }
        }
    } else {
        std::cout << "You don't have property" << name << std::endl;
    }
}

void Board::unmortgage( std::string name ) {
    auto player = players.at(currentPlayer);
    auto b = this->findBuilding(player, name);
    int money = player->getMoney();
    if ( b != nullptr ) {
        auto c = std::dynamic_pointer_cast<Chargeable>(b);
        int cost = c->getPurchase() * 0.6;
        bool mortgaged = c->getMortgage();
        if ( !mortgaged ) {
            std::cout << "This building is not mortgaged!" << std::endl;
        } else if ( money < cost ) {
            std::cout << "You don't have enough money." << std::endl;
        } else {
            c->unmortgage();
            player->loseMoney(cost);
        }
    } else {
        std::cout << "You don't have property" << name << std::endl;
    }
}

void Board::bankrupt() {
    auto p =  players.at(currentPlayer);
    auto properties = p->getProperty();
    
    int c = p->getCup();
    if (c != 0) {
        auto p1 = getBuilding(2);
        auto slc1 = std::dynamic_pointer_cast<SLC>(p1);
        auto p2 = getBuilding(17);
        auto slc2 = std::dynamic_pointer_cast<SLC>(p1);
        auto p3 = getBuilding(33);
        auto slc3 = std::dynamic_pointer_cast<SLC>(p3);
        
        slc1->addCup(c);
        slc2->addCup(c);
        slc3->addCup(c);
    }
    
    std::cout << p->getName() << " has declared bankruptcy!" << std::endl;
    int n = properties.size();
    if (n > 0) {
        std::cout << "Auction Begins Now!" << std::endl;
        
        for( int i = 0; i < n; i++ ) {
            auction(p->getProperty().at(i));
        }
        std::cout << "Auction Ends Now." << std::endl;
    }
    
    auto b = buildings[p->getCurBuilding()];
    b->removeCurPlayer(p);
    update(b);
    
    int n1 = players.size();
    for (int x = 0; x < n1; x++) {
        if (p->getName() == players.at(x)->getName()) {
            if ( x == n1 - 1 ) {
                currentPlayer--;
            }
            players.erase(players.begin()+x);
            break;
        }
    }
}

void Board::bankrupt( std::shared_ptr<Player> player ) {
    auto p =  players.at(currentPlayer);
    auto properties = p->getProperty();
    int money = p->getMoney();
    int cup = p->getCup();
    
    player->gainMoney(money);
    player->setCup(cup);
    int n = properties.size();
    for( int i = 0; i < n; i++ ) {
        player->addProperty(properties.at(i));
    }
    
    auto b = buildings[p->getCurBuilding()];
    b->removeCurPlayer(p);
    update(b);
    std::cout << p->getName() << " has declared bankruptcy!" << std::endl;
    
    int n1 = players.size();
    for (int x = 0; x < n1; x++) {
        if (p->getName() == players.at(x)->getName()) {
            if ( x == n1 - 1 ) {
                currentPlayer--;
            }
            players.erase(players.begin()+x);
            break;
        }
    }
}

void Board::getAssets() {
    auto player = players.at(currentPlayer);
    std::string name = player->getName();
    std::cout << "Assets of " << name << ":" << std::endl;
    std::cout << "   Money: " << player->getMoney() << std::endl;
    std::cout << "   Property: "<< std::endl;
    auto p = player->getProperty();
    int n = p.size();
    for( int i = 0; i < n ; i++ ) {
        if ( i == n - 1 ) {
            if ( i == 0 ) {
                std::cout << "      " << p.at(i)->getName() << std::endl;
            } else {
                std::cout << p.at( n - 1 )->getName() << std::endl;
            }
        } else {
            if ( i == 0 ) {
                std::cout << "      " << p.at(i)->getName() << ", ";
            } else {
                std::cout << p.at(i)->getName() << ", ";
            }
        }
    }
    std::cout << "   Roll Up the Rim Cup: " << player->getCup() <<  '\n' << std::endl;
}

void Board::getAllAssets() {
    int n = players.size();
    for( int i = 0; i < n; i ++ ) {
        std::string name = players.at(i)->getName();
        std::cout << "   Assets of " << name << ":" << std::endl;
        std::cout << "   Money: " << players.at(i)->getMoney() << std::endl;
        std::cout << "   Property: "<< std::endl;
        auto p = players.at(i)->getProperty();
        int n = p.size();
        for( int i = 0; i < n; i++ ) {
            if ( i == n - 1 ) {
                if ( i == 0 ) {
                    std::cout << "      " << p.at(i)->getName() << std::endl;
                } else {
                    std::cout << p.at( n - 1 )->getName() << std::endl;
                }
            } else {
                if ( i == 0 ) {
                    std::cout << "      " << p.at(i)->getName() << ", ";
                } else {
                    std::cout << p.at(i)->getName() << ", ";
                }
            }
        }
        std::cout << "   Roll Up the Rim Cup: " << players.at(i)->getCup() << '\n' << std::endl;
    }
}

std::ostream & operator<<( std::ostream & out, const Board & b ) {
    out << *b.d;
    return out;
}

