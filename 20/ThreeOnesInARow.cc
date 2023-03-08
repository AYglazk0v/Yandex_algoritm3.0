#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int a = 1, b = 2, c = 4;
    if (n == 1) {
        std::cout << 2;
    } else if (n == 2) {
        std::cout << 4;
    } else {
        for (int i = 3; i <= n; i++) {
            int temp = c;
            c = a + b + c;
            a = b;
            b = temp;
        }
        std::cout << c;
    }
    return 0;
}