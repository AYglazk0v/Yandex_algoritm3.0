#include <iostream>
#include <deque>

int  main() {
    std::string s;
    std::deque<int> q;
    while (std::cin >> s) {
        if (int tmp; s == "push_front") {
            std::cin >> tmp;
            q.push_front(tmp);
            std::cout << "ok\n";
        } else if (int tmp; s == "push_back") {
            std::cin >> tmp;
            q.push_back(tmp);
            std::cout << "ok\n";
        } else if (int tmp; s == "pop_front") {
            if (q.empty()) {
                std::cout << "error\n";
                continue;
            }
            tmp = q.front();
            q.pop_front();
            std::cout << tmp << "\n";
        } else if (int tmp; s == "pop_back") {
            if (q.empty()) {
                std::cout << "error\n";
                continue;
            }
            tmp = q.back();
            q.pop_back();
            std::cout << tmp << "\n";
        } else if (s == "front") {
            if (q.empty()) {
                std::cout << "error\n";
                continue;
            }
            std::cout << q.front() << "\n";
        } else if (s == "back") {
            if (q.empty()) {
                std::cout << "error\n";
                continue;
            }
            std::cout << q.back() << "\n";
        } else if (s == "size") {
            std::cout << q.size() << "\n";
        } else if (s == "clear") {
            q = std::deque<int>();
            std::cout << "ok\n";
        } else {
            std::cout << "bye";
            break;
        }
    }
    return 0;
}