#include <iostream>
#include <vector>

struct Combo {
    int a;
    int b;
    int c;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Combo> var(n);
    for (int i = 0; i != n; ++i) {
        std::cin >> var[i].a >> var[i].b >> var[i].c;
    }
    std::vector<int> dp(n);
    dp[0] = var[0].a;
    if (n > 1) {
        dp[1] = std::min(dp[0] + var[1].a, var[0].b);
    }
    if (n > 2) {
        dp[2] = std::min( std::min(dp[1] + var[2].a, dp[0] + var[1].b), var[0].c);
    }
    for (int i = 3; i != n; ++i) {
        dp[i] = std::min(std::min(dp[i - 1] + var[i].a, dp[i - 2] + var[i - 1].b), dp[i - 3] + var[i - 2].c);
    }
    std::cout << dp[n - 1];
    return 0;
}