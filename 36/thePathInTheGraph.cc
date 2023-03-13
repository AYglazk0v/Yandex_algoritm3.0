#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

int main() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> graph(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			std::cin >> x;
			if (x == 1) {
				graph[i].push_back(j);
			}
		}
	}

	int start, end;
	std::cin >> start >> end;
	start--;
	end--;

	if (start == end) {
		std::cout << 0;
		return 0;
	}

	std::vector<int> dist(n, -1);
	std::vector<int> prev(n, -1);

	std::queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int curr : graph[u]) {
			if (dist[curr] == -1) {
				dist[curr] = dist[u] + 1;
				prev[curr] = u;
				q.push(curr);
				if (curr == end) {
					std::cout << dist[curr] << '\n';
					
					std::vector<int> out;
					out.reserve(dist[curr]);
					int pos_start = end;
					while(pos_start != start) {
						out.push_back(pos_start);
						pos_start = prev[pos_start];
					}
					out.push_back(start);

					std::for_each(out.rbegin(), out.rend(), [](int c){std::cout << ++c << " ";});
					return 0;
				}
			}
		}
	}

	std::cout << -1;
	return 0;
}