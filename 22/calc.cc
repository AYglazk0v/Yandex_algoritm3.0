#include <iostream>
#include <vector>

void print(std::vector<int>& prev, int curr) {
    if (curr != -1) {
        print(prev, prev[curr]);
        std::cout << curr << " ";
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> dp(n + 1,0);
    std::vector<int> prev(n + 1, -1);
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        prev[i] = i - 1;
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            prev[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            prev[i] = i / 3;
        }
    }
    std::cout <<  dp[n] << "\n";
    print(prev, n);
    return 0;
}