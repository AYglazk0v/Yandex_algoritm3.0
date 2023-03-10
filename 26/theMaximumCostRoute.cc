#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> dp(n);
    std::vector<std::vector<int>> in(n);
    for (int i = 0; i != n; ++i) {
        dp[i].resize(m, -1);
        in[i].resize(m, -1);
    }
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            std::cin >> in[i][j];
        }
    }
    dp[0][0] = in[0][0];
    for (int i = 0; i!= n; ++i) {
        for (int j = 0; j != m; ++j) {
            if (i > 0) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + in[i][j]);
            }
            if (j > 0) {
                dp[i][j] = std::max(dp[i][j], dp[i][j - 1] + in[i][j]);
            }
        }
    }
    std::cout << dp[n - 1][m - 1] << "\n";
    return 0;
}