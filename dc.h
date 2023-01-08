#ifndef _DC_H_
#define _DC_H_
#include <memory>
#include <map>
#include "building.h"

class DC : public Building {
    std::map<char,int> turns;
    
    public:
    DC();
    virtual std::string getName() override;
    void addTurns(char , int );
    int getTurns(char);
   
};

#endif

