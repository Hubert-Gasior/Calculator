#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <cctype>
#include "Calculator.h"

float Calculator::applyOperation(float down_val, float top_val, char operation){        //funkcja wykonująca działanie operatora
    switch (operation) {
        case '+': return down_val + top_val;
        case '-': return down_val - top_val;
        case '*': return down_val * top_val;
        case '/': return down_val / top_val;
        default: return 0;
    }
}

int Calculator::precedence(char operation){     //funkcja określająca hierarchię wykonywania działań
    if (operation == '+' || operation == '-') return 1;
    if (operation == '*' || operation == '/') return 2;
    return 0;
}

float Calculator::Compute(std::string exp){     //funkcja obliczająca wyrażenie
    std::stack<float> number_stack;
    std::stack<char> operation_stack;
    size_t i = 0;

    if(exp.size() == 0){
        return 0;
    }
    
    while (i < exp.size()) {        //Wyodrębnienie liczby z wyrażenia
        if (isdigit(exp[i])) {
            std::string number_str;
            while (i < exp.size() && (isdigit(exp[i]) || exp[i] == '.')) {      //pętla konwertująca string na float
                number_str += exp[i];
                i++;
            }
            number_stack.push(std::stof(number_str));
        } else if (exp[i] == '(') {
            operation_stack.push(exp[i]);
            i++;
        } else if (exp[i] == ')') {
            while (!operation_stack.empty() && operation_stack.top() != '(') {      //Wykonanie działań wewnątrz nawiasu
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
        } else {        //warunek uzupełniający stosy zgodnie z algorytmem 'shunting yard alghoritm"
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

    while (!operation_stack.empty()) {      //pętla wykonująca działania zapisne na stosach
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