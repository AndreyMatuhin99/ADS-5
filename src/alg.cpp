// Copyright 2021 NNTU-CS
#include <string>
#include <sstream>
#include "tstack.h"

int priority(char x) {
    switch (x) {
        case '(': return 0;
        case ')': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
        default: return -1;
    }
}

void processOperator(char op, std::stringstream& postfix, const TStack<char, 100>& stack) {
    char zna;
    while (!stack.isEmpty() && (zna = stack.get()) != '(' && priority(zna) >= priority(op)) {
        postfix << stack.pop() << ' ';
    }
}

std::string infx2pstfx(const std::string& inf) {
    std::stringstream postfix;
    TStack<char, 100> stack;

    for (char x : inf) {
        if (x == ' ') continue;

        int pr = priority(x);
        if (pr == -1) {
            postfix << x << ' ';
        } else if (x == '(') {
            stack.push(x);
        } else if (x == ')') {
            processOperator(x, postfix, stack);
            stack.pop(); // Pop '('
        } else {
            processOperator(x, postfix, stack);
        }
    }

    while (!stack.isEmpty()) {
        postfix << stack.pop() << ' ';
    }

    return postfix.str();
}

int eval(const std::string& post) {
    TStack<int, 100> stack;

    std::stringstream ss(post);
    std::string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            stack.push(std::stoi(token));
        } else {
            int b = stack.pop();
            int a = stack.pop();
            switch (token[0]) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }

    return stack.pop();
}
