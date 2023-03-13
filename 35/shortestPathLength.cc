#include <iostream>
#include <vector>
#include <queue>

int main() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> graph(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0, tmp; j < n; j++) {
			std::cin >> tmp;
			if (tmp == 1) {
				graph[i].push_back(j);
			}
		}
	}

	int start, end;
	std::cin >> start >> end;
	--start, --end;
	if (start == end) {
		std::cout << 0;
		return 0;
	}

	std::vector<int> dist(n, -1);

	std::queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		for (int curr : graph[pos]) {
			if (dist[curr] == -1) {
				dist[curr] = dist[pos] + 1;
				q.push(curr);
				if (curr == end) {
					std::cout << dist[curr];
					return 0;
				}
			}
		}
	}

	std::cout << -1;
	return 0;
}