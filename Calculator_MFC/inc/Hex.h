#pragma once
#include <string>

class Hex{
public:
    int HexCharToDec(char c);
    std::string FloatToHex(float value);
    std::string ExpHexToDec(std::string exp);
};
