#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include "Bin.h"
#include "Oct.h"
#include "Hex.h"

class Calculator : public Bin, public Oct, public Hex{
public:
    float applyOperation(float down_val, float top_val, char operation);
    int precedence(char operation);
    float Compute(std::string exp);
};

#endif // CALCULATOR_H
