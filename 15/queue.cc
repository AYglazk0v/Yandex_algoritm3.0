#include <iostream>
#include <queue>

int main() {
    std::string s;
    std::queue<int> q;
    while(std::cin >> s) {
        if (int tmp; s == "push") {
            std::cin >> tmp;
            q.push(tmp);
            std::cout << "ok" << "\n";
        } else if (s == "pop") {
            if (q.empty()) {
                std::cout << "error" << "\n";
                continue;;
            }
            std::cout << q.front() << "\n";
            q.pop();
        } else if (s == "front") {
            if (q.empty()) {
                std::cout << "error" << "\n";
                continue;;
            }
            std::cout << q.front() << "\n";
        } else if (s == "size") {
            std::cout << q.size() << "\n";
        } else if (s == "clear") {
            q = std::queue<int>();
            std::cout << "ok" << "\n";
        } else {
            std::cout << "bye";
            break;
        }
    }
    return 0;
}