#include <iostream>
#include <stack>

int main() {
    std::string cmd;
    std::stack<int> stk;
    while(true) {
        std::cin >> cmd;
        if (int tmp; cmd == "push") {
            std::cin >> tmp;
            stk.push(tmp);
            std::cout << "ok" << "\n";
        } else if (cmd == "size") {
            std::cout << stk.size() << "\n";
        } else if (cmd == "clear") {
            stk = std::stack<int>();
            std::cout << "ok" << "\n";
        } else if (cmd == "pop") {
            if (!stk.empty()) {
                std::cout << stk.top() << "\n";
                stk.pop();
            } else {
                std::cout << "error" << "\n";
            }
        } else if (cmd == "back") {
            if (!stk.empty()) {
                std::cout << stk.top() << "\n";
            } else {
                std::cout << "error" << "\n";
            }
        } else {
            std::cout << "bye" << "\n";
            break;
        }
    }
    return 0;
}