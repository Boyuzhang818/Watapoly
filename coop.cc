#include "coop.h"

Coop::Coop() : Building{ "COOP FEE" } {}

Coop::~Coop() {}

int Coop::payCoop() {
    return 150;
}

std::string Coop::getName() {
    return name;
}

