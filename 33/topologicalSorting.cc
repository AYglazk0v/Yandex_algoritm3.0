#include <iostream>
#include <iterator>
#include <vector>

bool bad_graph = false;
std::vector<int> ret;

void dfs(int idx, int clr, std::vector<int> &color, std::vector<std::vector<int>>& grph) {
	color[idx] = clr;
	if (bad_graph) {
		return;
	}
	for (auto v : grph[idx]) {
		if (color[v] == 1){
			bad_graph = true;
			return;
		}
		if (color[v] == 0) {
			dfs(v, 1, color, grph);
		}
	}
	ret.push_back(idx);
	color[idx] = 2;
}

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> grph(n + 1);
	std::vector<int> color(n + 1, 0);

	for (int i = 0, g1, g2; i < m; ++i) {
		std::cin >> g1 >> g2;
		grph[g1].push_back(g2);
	}

	for (int i = 1; i <= n; ++i) {
		if (color[i] == 0) {
			dfs(i, 1, color, grph);
			if (bad_graph){
				std::cout << -1;
				return 0;
			}
		}
	}
	std::copy(ret.rbegin(), ret.rend(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}