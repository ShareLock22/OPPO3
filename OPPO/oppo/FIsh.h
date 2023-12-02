#pragma once

#include "Sea.h"
#include <string>
#include <iostream>
#include <fstream>

class Fish {
public:
    std::string NameOfFish;
    Sea sea;
    static void validName(std::string value);
    std::string getNameOfFish();
    void load(std::istream& ist);
    void print(std::ostream& ost);
};