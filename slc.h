#ifndef _SLC_H_
#define _SLC_H_

#include <memory>
#include "building.h"

class SLC : public Building {
    std::vector<int> moves;
    std::vector<int> probs;
    int cups;
    
    public:
    SLC(std::string s);
    int draw();
    int generate( std::vector<int>, std::vector<int> );
    virtual std::string getName() override;
    void addCup(int);
    
};

#endif


