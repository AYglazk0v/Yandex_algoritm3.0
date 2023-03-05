#include <iterator>
#include <utility>
#include <iostream>
#include <vector>
#include <stack>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> ret;
    ret.resize(n);
    std::stack<std::pair<int, int>> stk;

    for (int i = 0, value; i != n; ++i) {
        std::cin >> value;
        while (!stk.empty()) {
            auto curr = stk.top();
            if (value < curr.first) {
                ret[curr.second] = i;
                stk.pop();
            } else {
                break;
            }
        }
        stk.push({value, i});
    }
    while (!stk.empty()) {
        auto curr = stk.top();
        ret[curr.second] = -1;
        stk.pop();
    }

    std::copy(ret.begin(), ret.end(), std::ostream_iterator<int> (std::cout, " "));
    return 0;
}