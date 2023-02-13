#include <iostream>
#include <string>
#include <vector>


int main() {
    int array[256]{};
    while (std::cin.good()) {
        std::string tmp;
        std::cin >>  tmp;
        for (auto c : tmp) {
            array[(int)c]++;
        }
    }
    std::vector<std::pair<char, int>> ret;
    int max = -1;
    for (int i = 0; i < 256; ++i) {
        if (array[i] != 0) {
            if (max < array[i]) {
                max = array[i];
            }
            ret.push_back({i,array[i]});
        }
    }
    for (int i = max; i > 0; --i){
        for (auto curr : ret) {
            if (curr.second >= i) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    for (auto curr : ret) {
        std::cout << curr.first;
    }
    return  0;
}