#include <iostream>
#include <stack>

int main() {
    std::stack<char> stk;
    char c;
    while (std::cin >> c) {
        if ((c == ')' || c == ']' || c == '}') && stk.empty()) {
            std::cout << "no";
            return 0;
        }
        if (c == ')'){
            if (stk.top() == '(') {
                stk.pop();
            } else {
                std::cout << "no";
                return 0;
            }
        } else if (c == ']') {
            if (stk.top() == '[') {
                stk.pop();
            } else {
                std::cout << "no";
                return 0;
            }
        } else if (c == '}') {
            if (stk.top() == '{') {
                stk.pop();
            } else {
                std::cout << "no";
                return 0;
            }
        } else {
            stk.push(c);
        }
    }
    if (stk.empty()) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
    return 0;
}