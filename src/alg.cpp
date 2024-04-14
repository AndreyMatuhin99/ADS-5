// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int priority(char x) {
    switch (x) {
        case '(': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return -1;
    }
}

std::string infx2pstfx(std::string inf) {
    std::string post;
    TStack<char, 100> stack;

    for (char x : inf) {
        if (x == ' ')
            continue;

        int p = priority(x);

        if (p == -1) {
            post += x;
            post += ' ';
        } else {
            if (stack.isEmpty() || x == '(') {
                stack.push(x);
            } else if (x == ')') {
                while (!stack.isEmpty() && stack.get() != '(') {
                    post += stack.pop();
                    post += ' ';
                }
                stack.pop();  // Pop '('
            } else {
                while (!stack.isEmpty() && priority(stack.get()) >= p) {
                    post += stack.pop();
                    post += ' ';
                }
                stack.push(x);
            }
        }
    }

    while (!stack.isEmpty()) {
        post += stack.pop();
        post += ' ';
    }

    return post;
}

int eval(std::string post) {
    TStack<int, 100> stack;

    for (char x : post) {
        if (x == ' ') continue;

        if (isdigit(x)) {
            stack.push(x - '0');  // Convert char to int
        } else {
            int v = stack.pop();
            int p = stack.pop();
            switch (x) {
                case '+': stack.push(p + v); break;
                case '-': stack.push(p - v); break;
                case '*': stack.push(p * v); break;
                case '/': stack.push(p / v); break;
            }
        }
    }

    return stack.pop();
}
