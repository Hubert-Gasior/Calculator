#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
#include "Oct.h"

std::string Oct::FloatToOct(float value){       //funkcja konwertująca float na system ósemkowy
    int conv = static_cast<int>(value);
    std::ostringstream oss;
    oss << std::oct << conv;
    return oss.str();
}

std::string Oct::ExpOctToDec(std::string exp){      //funkcja konwertująca wyrażenie z systemu ósemkowego na system dzięsietny
    int lp {0};
    std::string number_str;
    std::string result;
    std::string check ="01234567+-*/()";

    for (int i {0}; i < exp.size(); i++){       //Sprawdzenie czy format zpstał poprawnie wprowadzony
        size_t res = check.find(exp[i]);
        if(res == std::string::npos){
            return "Invalid argument";
        }
    }
    
    for (int i {0}; i < exp.size(); i++){
        if(isdigit(exp[i])){        //wyodrębnienie liczby z systemu ósemkowego
            number_str += exp[i];
        }else{                      //konwersja liczby z systemu ósemkowego na system dziesiętny
            lp = 0;
            for (int j {0}; j < number_str.size(); j++){
                lp += (number_str[number_str.size()-1-j] - '0')*(pow(8,j));
            }
            result += std::to_string(lp);       //uzupełnienie wyrażenia o przekonwertowaną liczbę
            result += exp[i];       //zachowanie operatora w wyrażeniu
            number_str.clear();
        }
    }

    if (!number_str.empty()) {      //konwersja ostaniej liczby z wyrażenia na system dziesiętny
        lp = 0;
        for (size_t j = 0; j < number_str.size(); j++) {
            lp += (number_str[number_str.size() - 1 - j] - '0')*((pow(8, j)));
        }
        result += std::to_string(lp);
    }
    exp = result;
    return exp;
}