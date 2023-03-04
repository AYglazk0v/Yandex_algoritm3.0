#include <iostream>
#include <map>

int main () {
    std::string str;
    std::cin >> str;

    std::map<char, unsigned long> ret;
    for (auto it = str.begin(), ite = str.end(); it != ite ; ++it) {
        ret[*it] += (std::distance(str.begin(), it) + 1) * (std::distance(it, str.end()));
    }
    for (auto it = ret.begin(), ite = ret.end(); it != ite; ++it) {
        std::cout << (*it).first << ": " << (*it).second << "\n";
    }
    return 0;
}