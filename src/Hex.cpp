#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
#include "Hex.h"

int HexCharToDec(char c){
        std::string tab = "0123456789ABCDEF";
        for (int i {0}; i < tab.size(); i++){
            if(toupper(c) == tab[i])
            return i;
        }
        return 0;
}

std::string FloatToHex(float value) {
    int conv = static_cast<int>(value);
    std::ostringstream oss;
    oss << std::hex << conv;
    return oss.str();
}

std::string ExpHexToDec(std::string exp){
    std::string number_str;
    int lp {0};
    std::string result; 

    for (int i {0}; i < exp.size(); i++){
        if(isalnum(exp[i])){
            number_str += exp[i];
        }else{
            lp = 0;
            for (int j {0}; j < number_str.size(); j++){
                lp += HexCharToDec(number_str[number_str.size()-1-j])*(pow(16,j));
            }
            result += std::to_string(lp);
            result += exp[i];
            number_str.clear();
        }
    }

    if (!number_str.empty()) {
        lp = 0;
        for (size_t j = 0; j < number_str.size(); j++) {
            lp += HexCharToDec(number_str[number_str.size() - 1 - j])*((pow(16, j)));
        }
        result += std::to_string(lp);
    }
    return result;  
}