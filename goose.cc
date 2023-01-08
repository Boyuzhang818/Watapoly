#include "goose.h"

Goose::Goose() : Building{ "Goose Nesting" } {}

Goose::~Goose()  {}

std::string Goose::getName() {
    return name;
}

std::string Goose::message() {
    return "You have been attacked by a flock of NESTING GEESE!!!";
}

