#ifndef _COOP_H_
#define _COOP_H_

#include "building.h"

class Coop : public Building {
    public:
    Coop();
    ~Coop();
    int payCoop();
    virtual std::string getName() override;
};

#endif
