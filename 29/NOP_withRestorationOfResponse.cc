#include <iostream>
#include <iterator>
#include <vector>

int main() {
    int n,m;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i != n; ++i) {
        std::cin >> a[i];
    }

    std::cin >> m;
    std::vector<int> b(m);
    for (int i = 0; i != m; ++i) {
        std::cin >> b[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::vector<int> ans;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    std::copy(ans.rbegin(), ans.rend(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}