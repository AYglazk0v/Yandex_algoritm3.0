#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << "0\n" << 0 << " " << 0;
        return 0;
    }
    int m = n + 1;
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 30001));
    std::vector<int> in(n);
    for (int i = 0; i != n; ++i) {
        std::cin >> in[i];
    }
    if (in[0] <= 100) {
        dp[0][0] = in[0];
    } else {
        dp[0][1] = in[0];
    }

    for (int i = 1; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            if (in[i] > 100){
                if (j > 0){
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + in[i]);
                }
                if (j < m - 1) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j + 1]);
                }
            } else {
                if (j < m - 1) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j + 1]);
                }
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + in[i]);
            }

        }
    }
    auto it_min = std::min_element(dp[n-1].rbegin(), dp[n-1].rend());
    std::cout << *(it_min) << "\n";

    int pos_min = std::distance(it_min, dp[n - 1].rend() - 1);
    std::cout << pos_min << " ";
    std::vector<int> ret;
    for (int i = n - 1; i != 0; --i) {
        if (in[i] > 100) {
            if (pos_min > 0 && dp[i][pos_min] == dp[i-1][pos_min - 1] + in[i]) {
                pos_min--;
            } else {
                pos_min++;
                ret.push_back(i + 1);
            }
        } else {
            if (pos_min + 1 < n && dp[i][pos_min] == dp[i - 1][pos_min + 1]) {
                pos_min++;
                ret.push_back(i + 1);
            }
        }
    }
    std::cout << ret.size() << "\n";
    std::copy(ret.rbegin(), ret.rend(), std::ostream_iterator<int>(std::cout, "\n"));
    return 0;
}