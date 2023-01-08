#include "tuition.h"

Tuition::Tuition() : Building{ "TUITION" } {}

Tuition::~Tuition() {}

std::string Tuition::getName() {
    return name;
}

int Tuition::payTui() {
    return 300;
}

