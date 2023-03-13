#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void dfs(int idx, std::vector<bool> &visited, std::vector<std::vector<int>>& grph, std::vector<int>& ans) {
	visited[idx] = true;
	ans.push_back(idx);
	for (auto v : grph[idx]) {
			if (visited[v] == false) {
					dfs(v, visited, grph, ans);
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


	std::vector<std::vector<int>> out;
	for (int i = 1; i <= n; ++i) {
		std::vector<int> ans;
		if (visited[i] == false) {
			dfs(i, visited, grph, ans);
		}
		if (ans.size() != 0){
			out.push_back(ans);
		}
	}

	std::cout << out.size() << '\n';
	for (auto&& v : out) {
		std::cout << v.size() << '\n';
		std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << '\n';

	}
	return 0;
}