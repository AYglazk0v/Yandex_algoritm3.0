// #include <iostream>
// #include <vector>

// std::vector<int> cycle;

// bool dfs(int v, int p, std::vector<bool>& visited, std::vector<std::vector<int>>& graph) {
// 	visited[v] = true;
// 	for (int curr = 0, end = graph.size(); curr != end; ++curr) {
// 		if (graph[v][curr]) {
// 			if (!visited[curr]) {
// 				if (dfs(curr, v, visited, graph)) {
// 					cycle.push_back(v);
// 					return v == cycle[0];
// 				}
// 			} else if (curr != p) {
// 				cycle.push_back(v);
// 				return true;
// 			}
// 		}
// 		if (!cycle.empty()) {
// 			break;
// 		}
// 	}
// 	return false;
// }

// int main() {
// 	int n;
// 	std::cin >> n;

// 	std::vector<std::vector<int>> graph(n, std::vector<int>(n));
// 	std::vector<bool> visited(n, false);
// 	for (int i = 0; i != n; ++i) {
// 		for (int j = 0; j != n; ++j) {
// 			std::cin >> graph[i][j];
// 		}
// 	}

// 	for (int i = 0; i != n; ++i) {
// 		if (!visited[i] && dfs(i, -1, visited, graph)) {
// 			std::cout << "YES\n";
// 			std::cout << cycle.size() << '\n';
// 			for (int curr : cycle) {
// 				std::cout << curr + 1 << ' ';
// 			}
// 			return 0;
// 		}
// 	}
// 	std::cout << "NO";
// 	return 0;
// }