#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <cctype>
#include "Calculator.h"

float applyOperation(float down_val, float top_val, char operation){
    switch (operation) {
        case '+': return down_val + top_val;
        case '-': return down_val - top_val;
        case '*': return down_val * top_val;
        case '/': return down_val / top_val;
        default: return 0;
    }
}

int precedence(char operation){
    if (operation == '+' || operation == '-') return 1;
    if (operation == '*' || operation == '/') return 2;
    return 0;
}

float Calculator(std::string exp){
    std::stack<float> number_stack;
    std::stack<char> operation_stack;

    size_t i = 0;
    while (i < exp.size()) {
        if (isdigit(exp[i])) {
            std::string number_str;
            while (i < exp.size() && (isdigit(exp[i]) || exp[i] == '.')) {
                number_str += exp[i];
                i++;
            }
            number_stack.push(std::stof(number_str));
        } else if (exp[i] == '(') {
            operation_stack.push(exp[i]);
            i++;
        } else if (exp[i] == ')') {
            while (!operation_stack.empty() && operation_stack.top() != '(') {
                float top_val = number_stack.top(); 
                number_stack.pop();
                float down_val = number_stack.top(); 
                number_stack.pop();
                char operation = operation_stack.top(); 
                operation_stack.pop();
                number_stack.push(applyOperation(down_val, top_val, operation));
            }
            if (!operation_stack.empty() && operation_stack.top() == '(') {
                operation_stack.pop();
            }
            i++;
        } else {
            char current_operator = exp[i];
            while (!operation_stack.empty() && precedence(operation_stack.top()) >= precedence(current_operator)) {
                float top_val = number_stack.top(); 
                number_stack.pop();
                float down_val = number_stack.top(); 
                number_stack.pop();
                char operation = operation_stack.top(); 
                operation_stack.pop();
                number_stack.push(applyOperation(down_val, top_val, operation));
            }
            operation_stack.push(current_operator);
            i++;
        }
    }

    while (!operation_stack.empty()) {
        float top_val = number_stack.top(); 
        number_stack.pop();
        float down_val = number_stack.top(); 
        number_stack.pop();
        char operation = operation_stack.top(); 
        operation_stack.pop();
        number_stack.push(applyOperation(down_val, top_val, operation));
    }

    float result = number_stack.top();
    number_stack.pop();
    return result;
}