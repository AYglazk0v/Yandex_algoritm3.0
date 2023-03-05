#include <iostream>
#include <stack>

using lint_t = long long;

int main() {
    std::string s;
    std::stack<lint_t> stk;
    while (std::cin >> s) {
        if (s == "+") {
            int tmp = stk.top();
            stk.pop();
            int tmp1 = stk.top();
            stk.pop();
            tmp1 += tmp;
            stk.push(tmp1);
        } else if (s == "-") {
            int tmp = stk.top();
            stk.pop();
            int tmp1 = stk.top();
            stk.pop();
            tmp1 -= tmp;
            stk.push(tmp1);
        } else if (s == "*") {
            int tmp = stk.top();
            stk.pop();
            int tmp1 = stk.top();
            stk.pop();
            tmp1 *= tmp;
            stk.push(tmp1);
        } else {
            stk.emplace(std::stoi(s));
        }
    }
    std::cout << stk.top();
    return 0;
}