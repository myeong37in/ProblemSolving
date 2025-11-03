/*
양수가 음수고 음수가 양수예요.
음의 사이클이 있으면 -1이에요.

O(nm) Bellman-Ford + 역추적인 듯

4 4
1 4 1
1 2 1
2 3 1000
3 2 1000

아.. 이런 거?

n에서 출발해서 1로 도달하는 문제로 바꾸면 되겠군. 그럼 n에서 도달 가능한 음의 사이클을 판정하게 될 것
*/

#include <iostream>
#include <vector>

struct Edge {
	int to, weight;
};

int main(int argc, char* argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<Edge>> graph(n + 1);
	int u, v, w;
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v >> w;
		graph[v].emplace_back(Edge { u, -w }); // 간선 반대로
	}

	constexpr int INF = 2e9;
	std::vector<int> dists(n + 1, INF);
	std::vector<int> prev(n + 1, -1);
	dists[n] = 0;
	for (int it = 0; it < n - 1; it++) {
		bool relaxed = false;
		for (int u = 1; u <= n; u++) {
			if (dists[u] == INF) {
				continue;
			}

			for (const auto& [next, weight] : graph[u]) {
				int nd = dists[u] + weight;
				if (nd < dists[next]) {
					dists[next] = nd;
					prev[next] = u;
					relaxed = true;
				}
			}
		}

		if (!relaxed) {
			break;
		}
	}

	for (int u = 1; u <= n; u++) {
		if (dists[u] == INF) {
			continue;
		}

		for (const auto& [next, weight] : graph[u]) {
			int nd = dists[u] + weight;
			if (nd < dists[next]) {
				std::cout << -1;
				return 0;
			}
		}
	}

	std::vector<int> path;
	for (int v = 1; v != -1; v = prev[v]) {
		path.emplace_back(v);
	}

	for (int i = 0; i < path.size(); i++) {
		std::cout << path[i] << " ";
	}

	return 0;
}