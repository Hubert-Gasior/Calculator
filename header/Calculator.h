#pragma once
#include <string>

float applyOperation(float down_val, float top_val, char operation);
int precedence(char operation);
float Calculator(std::string exp);