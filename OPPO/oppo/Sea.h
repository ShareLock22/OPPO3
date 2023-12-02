#pragma once

#include <string>
#include <iostream>
#include <fstream>

class Sea {
private:
    std::string NameOfSea;
    float salty, deep;

public:
    Sea() {};

    Sea(std::string NameOfSea, float salty, float deep);
    static void validateName (std::string value) ;
    static void validateDeep(int deep);
    static void validateSalty(int salty);
    std::string getNameOfSea() const;
    int getSalty() const;
    int getDeep() const;
    static Sea load_txt(std::istream& ist);
    void print_txt(std::ostream& ost) const;
};