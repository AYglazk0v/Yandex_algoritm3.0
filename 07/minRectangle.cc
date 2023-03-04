#include <iostream>

int main() {
    int K;
    std::cin >> K;
    int min_x, min_y, max_x, max_y;
    std::cin >> min_x >> min_y;
    max_x = min_x;
    max_y = min_y;
    for (int i = 1, tmp_x, tmp_y; i != K; ++i) {
        std::cin >> tmp_x >> tmp_y;
        if (tmp_x < min_x) {
            min_x = tmp_x;
        } else if (tmp_x > max_x) {
            max_x = tmp_x;
        }
        if (tmp_y < min_y) {
            min_y = tmp_y;
        } else if ( tmp_y > max_y) {
            max_y = tmp_y;
        }
    }
    std::cout << min_x << " " << min_y << " " << max_x << " " << max_y;
    return 0;
}