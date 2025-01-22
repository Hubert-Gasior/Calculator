#ifndef HEX_H
#define HEX_H
#include <string>

class Hex{
public:
    int HexCharToDec(char c);
    std::string FloatToHex(float value);
    std::string ExpHexToDec(std::string exp);
};
#endif // HEX_H
