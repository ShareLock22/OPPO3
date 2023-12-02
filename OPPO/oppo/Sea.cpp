#include "Sea.h"

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <algorithm>


Sea::Sea(std::string NameOfSea, float salty, float deep) {
    validateName(NameOfSea);
    validateSalty(salty);
    validateDeep(deep);
}

std::string Sea::getNameOfSea() const {
    return NameOfSea;
}
int Sea::getSalty() const {
    return salty;
}

int Sea::getDeep() const {
    return deep;
}

void Sea::validateName(std::string NameOfSea)  {
    std::string Alphabet = "QWERTYUIOPASDFGHJKLZXCVBNMËЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ-";
    std::transform(NameOfSea.begin(), NameOfSea.end(), NameOfSea.begin(), ::toupper);
    for (int i = 0; i < NameOfSea.size(); i++) {
        if (Alphabet.find(NameOfSea[i])) {
            throw (std::runtime_error("Использование недопустимого символа в названии моря"));
        }
    }
}

void Sea::validateDeep(int deep) {
    if (deep < 0) {
        throw (std::out_of_range("Глубина не может быть меньше нуля"));
    }
}

void Sea::validateSalty(int salty) {
    if (salty < 0 || salty >= 100) {
        throw (std::out_of_range("Соленость измерятеся в процентах (от 0 до 100)"));
    }
}

Sea Sea::load_txt(std::istream& ist)
{
    std::string buffer;
    std::string name;
    while (ist >> buffer) {
        name.append(buffer);
        if (buffer.back() == '"') {
            break;
        }
        name.append(" ");
    }
    
    if (buffer.empty()) {
        throw (std::runtime_error("Пустое поле"));
    }

    if (name[0] != '"' || buffer.back() != '"') {
        throw (std::runtime_error("Ошибка формата данных"));
    }

    float deep, salty;
    ist >> deep >> salty;

    if (ist.fail()) {

    }

    return Sea(name, salty, deep);
}

void Sea::print_txt(std::ostream& ost) const
{
    std::string name = getNameOfSea();
    float deep = getDeep();
    float salty = getSalty();
    ost << name << "/n";
    ost << deep << "/n";
    ost << salty << "/n";

}


