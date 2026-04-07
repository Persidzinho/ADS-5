// Copyright 2025 NNTU-CS
#include <string>
#include "alg.h"
#include "tstack.h"

int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> stack;
    std::string result = "";

    for (size_t i = 0; i < inf.length(); ++i) {
        char c = inf[i];

        if (c >= '0' && c <= '9') {
            while (i < inf.length() && inf[i] >= '0' && inf[i] <= '9') {
                result += inf[i];
                ++i;
            }
            result += ' ';
            --i;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.get() != '(') {
                result += stack.get();
                result += ' ';
                stack.pop();
            }
            if (!stack.isEmpty()) {
                stack.pop();
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!stack.isEmpty() && stack.get() != '(' &&
                   getPriority(stack.get()) >= getPriority(c)) {
                result += stack.get();
                result += ' ';
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        result += stack.get();
        result += ' ';
        stack.pop();
    }

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    return result;
}

int eval(const std::string& post) {
    TStack<int, 100> stack;

    for (size_t i = 0; i < post.length(); ++i) {
        char c = post[i];
        if (c >= '0' && c <= '9') {
            int num = 0;
            while (i < post.length() && post[i] >= '0' && post[i] <= '9') {
                num = num * 10 + (post[i] - '0');
                ++i;
            }
            stack.push(num);
            --i;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = stack.get();
            stack.pop();
            int a = stack.get();
            stack.pop();
            int res = 0;
            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') res = a / b;
            stack.push(res);
        }
    }
    return stack.get();
}
