#ifndef _OSAP_H_
#define _OSAP_H_

#include "building.h"

class OSAP : public Building {
    public:
    OSAP();
    int give();
    virtual std::string getName() override;
};

#endif

