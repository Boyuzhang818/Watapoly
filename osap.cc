#include "osap.h"

OSAP::OSAP() 
    : Building{"COLLECT OSAP"} {}
    
int OSAP::give() {
    return 200;
}

std::string OSAP::getName() {
    return name;
}

