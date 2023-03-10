#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> dp(n);
    std::vector<int> coord(n);
    for (int i = 0; i != n; ++i) {
        std::cin >> coord[i];
    }
    std::sort(coord.begin(),coord.end());
    dp[0] = 20001;
    dp[1] = coord[1] - coord[0];
    for (int i = 2, tmp; i < n; ++i) {
        tmp = coord[i] - coord[i - 1];
        dp[i] = std::min(dp[i - 1] + tmp, dp[i - 2] + tmp);
    }
    std::cout << dp[n - 1];
    return 0;
}