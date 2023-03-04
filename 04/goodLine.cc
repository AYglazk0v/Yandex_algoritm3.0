#include <iostream>

int main() {
    int N;
    std::cin >> N;
    unsigned long nice = 0;

    int prev;
    std::cin >> prev;
    for (int i = 1, tmp; i != N; ++i) {
        std::cin >> tmp;
        if (tmp >= prev) {
            nice+=prev;
        } else {
            nice += tmp;
        }
        prev = tmp;
    }
    std::cout << nice;
    return 0;
}