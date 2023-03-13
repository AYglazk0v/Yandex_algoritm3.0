#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void dfs(int idx, std::vector<bool> &visited, std::vector<std::vector<int>>& grph) {
	visited[idx] = true;
	for (auto v : grph[idx]) {
		if (visited[v] == false) {
			dfs(v, visited, grph);
		}
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> grph(n + 1);
	std::vector<bool> visited(n + 1, false);

	for (int i = 0, g1, g2; i < m; i++) {
		std::cin >> g1 >> g2;
		grph[g1].push_back(g2);
		grph[g2].push_back(g1);
	}

	dfs(1, visited, grph);

	std::vector<int> ans;
	for (int i = 0; i <= n; ++i) {
	if (visited[i] == true)
		ans.push_back(i);
	}
	
	std::cout << ans.size() << '\n';
	std::sort(ans.begin(), ans.end());
	std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}