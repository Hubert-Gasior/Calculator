#include <iostream>
#include <bitset>
#include <string>
#include <cmath>
#include <cctype>
#include "Bin.h"

std::string Bin::FloatToBin(float value) {     //funkcja konwertująca float an system dwójkowy
    unsigned int val = static_cast<unsigned int>(value);
    std::string bin = std::bitset<32>(val).to_string();   //zapisanie 32 bitowej liczby binarnej jako string
    int msb {32};
    for (int i {0}; i < bin.size(); i++) {  //pętla wyszukująca MSB
        if (bin[i] == '1') {
            msb = msb - i;
            break;
        }
    }
    std::string result = bin.substr(32 - msb);   //wpisanie jako wynik liczby binarnej o długości równej pozycji MSB
    return result;
}

std::string Bin::ExpBinToDec(std::string exp){  //funkcja konwertująca wyrażenie binarne do wyrażenia dziesiętnego
    std::string number_str;
    int lp {0};
    std::string result;
    for (int i {0}; i < exp.size(); i++){
        if(isdigit(exp[i])){        //wyodrębnienie liczby binarnej
            number_str += exp[i];
        }else{
            lp = 0;
            for (int j {0}; j < number_str.size(); j++){  //zamiana wyodrębnionej liczby binarnej na liczbe dziesiętną
                lp += (number_str[number_str.size()-1-j] - '0')*(pow(2,j));
            }
            result += std::to_string(lp);
            result += exp[i];
            number_str.clear();
        }
    }

    if (!number_str.empty()) {  //zamiana ostatniej liczby z wyrażenia na system dziesiętny
        lp = 0;
        for (size_t j = 0; j < number_str.size(); j++) {
            lp += (number_str[number_str.size() - 1 - j] - '0')*((pow(2, j)));
        }
        result += std::to_string(lp);
    }
    exp = result;
    return exp;
}
