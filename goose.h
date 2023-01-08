#ifndef _GOOSE_H_
#define _GOOSE_H_

#include "building.h"

class Goose : public Building {
    public:
    Goose();
    ~Goose();
    std::string message();
    virtual std::string getName() override;
};

#endif

