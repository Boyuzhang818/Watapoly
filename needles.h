#ifndef _NEEDLES_H_
#define _NEEDLES_H_

#include <memory>
#include "building.h"

class Needles : public Building {
    std::vector<int> moves;
    std::vector<int> probs;
    int cups;
    
    
    public:
    Needles(std::string s);
    int draw();
    int generate(std::vector<int>, std::vector<int>);
    virtual std::string getName() override;
    void addCup(int);
    
};

#endif
