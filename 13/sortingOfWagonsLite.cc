#include <iostream>
#include <stack>

int main() {
    int n;
    std::cin >> n;

    std::stack<int> stk;
    int min = 1;
    for (int i = 0, tmp; i != n; ++i) {
        std::cin >> tmp;
        stk.push(tmp);
        while (true) {
            if (!stk.empty() && min == stk.top()) {
                min++;
                stk.pop();
            } else {
                break;
            }
        }
    }
    if (stk.empty()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}