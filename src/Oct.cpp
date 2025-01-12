#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
#include "Oct.h"

std::string FloatToOct(float value){
    int conv = static_cast<int>(value);
    std::ostringstream oss;
    oss << std::oct << conv;
    return oss.str();
}

std::string ExpOctToDec(std::string exp){
    int lp {0};
    std::string number_str;
    std::string result;
    for (int i {0}; i < exp.size(); i++){
        if(isdigit(exp[i])){
            number_str += exp[i];
        }else{
            lp = 0;
            for (int j {0}; j < number_str.size(); j++){
                lp += (number_str[number_str.size()-1-j] - '0')*(pow(8,j));
            }
            result += std::to_string(lp);
            result += exp[i];
            number_str.clear();
        }
    }

    if (!number_str.empty()) {
        lp = 0;
        for (size_t j = 0; j < number_str.size(); j++) {
            lp += (number_str[number_str.size() - 1 - j] - '0')*((pow(8, j)));
        }
        result += std::to_string(lp);
    }
    exp = result;
    return exp;
}