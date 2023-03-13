#include <iostream>
#include <vector>

bool bad_graph = false;

void dfs(int idx, int clr, std::vector<int> &color, std::vector<std::vector<int>>& grph) {
	color[idx] = clr;
	for (auto v : grph[idx]) {
		if (color[v] == clr){
			bad_graph = true;
		}
		if (color[v] == 0) {
			dfs(v, 3 - clr, color, grph);
		}
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> grph(n + 1);
	std::vector<int> color(n + 1, 0);

	for (int i = 0, g1, g2; i < m; ++i) {
		std::cin >> g1 >> g2;
		grph[g1].push_back(g2);
		grph[g2].push_back(g1);
	}

	for (int i = 1; i <= n; ++i) {
		if (color[i] == 0) {
			dfs(i, 1, color, grph);
			if (bad_graph){
				std::cout << "NO";
				return 0;
			}
		}
	}
	std::cout << "YES";
	return 0;
}  