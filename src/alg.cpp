// Copyright 2021 NNTU-CS
#include <string>
#include <sstream>
#include "tstack.h"

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::string infx2pstfx(std::string inf) {
    TStack<char, 100> stack;
    std::string pst;

    for (char c : inf) {
        if (c == ' ') continue;

        if (isdigit(c)) {
            pst += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.get() != '(') {
                pst += ' ';
                pst += stack.pop();
            }
            stack.pop();
        } else if (isOperator(c)) {
            while (!stack.isEmpty() && priority(stack.get()) >= priority(c)) {
                pst += ' ';
                pst += stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        pst += ' ';
        pst += stack.pop();
    }

    return pst;
}

int eval(std::string post) {
    TStack<int, 100> stack;
    std::istringstream iss(post);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.push(std::stoi(token));
        } else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            int result;
            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            stack.push(result);
        }
    }

    return stack.pop();
}
