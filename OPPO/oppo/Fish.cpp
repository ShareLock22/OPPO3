#include "FIsh.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

std::string Fish::getNameOfFish() {
    return NameOfFish;
}

void Fish::validName(std::string value) {
    std::string Alphabet = "QWERTYUIOPASDFGHJKLZXCVBNMËЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ-";
    std::transform(value.begin(), value.end(), value.begin(), ::toupper);
    for (int i = 0; i < value.size(); i++) {
        if (Alphabet.find(value[i]) == std::string::npos) {
            throw (std::runtime_error("Использование недопустимого символа в названии рыбы"));
        }
    }
}


void Fish::load(std::istream & ist) {
    std::string buffer;
    while (ist >> buffer) {
        NameOfFish.append(buffer);
        if (buffer.back() == '"') {
            break;
        }
        NameOfFish.append(" ");
    }
    if (buffer.empty()) {
        throw (std::runtime_error("Пустое поле"));
    }

    if (NameOfFish[0] != '"' || buffer.back() != '"') {
        throw (std::runtime_error("Ошибка формата данных"));
    }

}

void Fish::print(std::ostream& ost) {
    ost << NameOfFish << "/n";
    ost << sea.getNameOfSea() << "/n";
}