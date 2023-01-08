#include "chargeable.h"

Chargeable::Chargeable( std::string name, int purchase,  bool mortgaged)
        : Building{ name }, purchase{ purchase }, mortgaged{ mortgaged } {}
  
Chargeable::~Chargeable() {}

