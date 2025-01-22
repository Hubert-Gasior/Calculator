#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
#include "Hex.h"

int Hex::HexCharToDec(char c){      //funkcja konwertująca cyfrę z systemu szesnastkowego na dziesiętny
    std::string tab = "0123456789ABCDEF";
    for (int i {0}; i < tab.size(); i++){       //konwersja poprzez przypisanie wartości indeksu
        if(toupper(c) == tab[i])
            return i;
    }
    return 0;
}

std::string Hex::FloatToHex(float value) {      //funkcja konwertująca float na system szesnastkowy
    int conv = static_cast<int>(value);
    std::ostringstream oss;
    oss << std::hex << conv;
    return oss.str();
}

std::string Hex::ExpHexToDec(std::string exp){      //funkcja konwertująca wyrażenie w formie szesnatkowej na dziesiętną
    std::string number_str;
    int lp {0};
    std::string result;

    for (int i {0}; i < exp.size(); i++){       //wyodrębnieine liczby z systemu szesnastkowego
        if(isalnum(exp[i])){
            number_str += exp[i];
        }else{
            lp = 0;
            for (int j {0}; j < number_str.size(); j++){        //konwersja liczby na system dziesiętny
                lp += HexCharToDec(number_str[number_str.size()-1-j])*(pow(16,j));
            }
            result += std::to_string(lp);
            result += exp[i];
            number_str.clear();
        }
    }

    if (!number_str.empty()) {      //konwersja ostatniej liczby wyrażenia z systemu szesnatkowego na dziesiętny
        lp = 0;
        for (size_t j = 0; j < number_str.size(); j++) {
            lp += HexCharToDec(number_str[number_str.size() - 1 - j])*((pow(16, j)));
        }
        result += std::to_string(lp);
    }
    return result;
}
