#ifndef _GOTIMS_H_
#define _GOTIMS_H_

#include "building.h"

class GoTims : public Building {
    public:
    GoTims();
    virtual std::string getName() override;
   
};

#endif

