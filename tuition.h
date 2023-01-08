#ifndef _TUITION_H_
#define _TUITION_H_

#include "building.h"

class Tuition : public Building {
    public:
    Tuition();
    ~Tuition();
    virtual std::string getName() override;
    int payTui();
};

#endif


