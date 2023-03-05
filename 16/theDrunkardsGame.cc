#include <iostream>
#include <queue>

int main() {
    std::queue<int> first, second;
    for (int i = 0, tmp; i < 5; ++i) {
        std::cin >> tmp, first.push(tmp);
    }
    for (int i = 0, tmp; i < 5; ++i) {
        std::cin >> tmp, second.push(tmp);
    }
    int i = 0;
    for (int f_c, s_c; i < 1000000 && !first.empty() && !second.empty(); ++i) {
        f_c = first.front(), s_c = second.front();
        first.pop();
        second.pop();
        if (f_c == 0 && s_c == 9) {
            first.push(f_c);
            first.push(s_c);
        } else if (f_c == 9 && s_c == 0) {
            second.push(f_c);
            second.push(s_c);
        } else if ( f_c < s_c ) {
            second.push(f_c);
            second.push(s_c);
        } else {
            first.push(f_c);
            first.push(s_c);
        }
    }
    if (first.empty()) {
        std::cout << "second" << " " << i;
    } else if (second.empty()) {
        std::cout << "first" << " " << i;
    } else {
        std::cout << "botva";
    }
    return 0;
}