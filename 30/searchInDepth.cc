#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> grph(n+1);
    std::vector<bool> visited(n+1, false);

    for (int i = 0, g1, g2; i < m; i++) {
        std::cin >> g1 >> g2;
        grph[g1].push_back(g2);
        grph[g2].push_back(g1);
    }

    std::queue<int> q;
    q.push(1);
    visited[1] = true;

    std::vector<int> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : grph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    std::cout << ans.size() << '\n';
    std::sort(ans.begin(), ans.end());
    std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}