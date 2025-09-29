#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int weight, to;
};

std::vector<std::vector<Edge>> graph;
std::vector<bool> visited;
std::vector<int> parent;

auto cmp = [](const Edge& a, const Edge& b) {
    if (a.weight == b.weight) {
        return a.to > b.to;
    }
    return a.weight > b.weight;
};

constexpr int INF = 2e9;
int Dijkstra(int S, int E) {
    std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> pq(cmp);
    int N = graph.size();
    std::vector<int> dists(N, INF);

    pq.push({0, S});
    dists[S] = 0;
    while (!pq.empty()) {
        auto [dist, cur] = pq.top();
        pq.pop();

        if (dists[cur] != dist) {
            continue;
        }

        for (const auto& [nd, next] : graph[cur]) {
            // 음...
            if (visited[next]) {
                continue;
            }
            if (dists[next] > dist + nd) {
                parent[next] = cur;
                dists[next] = dist + nd;
                pq.push({dist + nd, next});
            }
            else if (dists[next] == dist + nd && next > cur) { // 이건 부모만 바꿔주면 되겠지
                parent[next] = cur;
            }
        }
    }

    return dists[E];
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    graph.resize(N + 1);
    int u, v, w;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v >> w;
        graph[u].emplace_back(Edge {w, v});
        graph[v].emplace_back(Edge {w, u});
    }

    int S, E;
    std::cin >> S >> E;

    visited.resize(N + 1);
    parent.resize(N + 1);

    int ans = Dijkstra(S, E);
    for (int n = E; n != S; n = parent[n]) {
        visited[n] = true;
    }
    visited[E] = false;

    ans += Dijkstra(E, S);

    std::cout << ans;

    return 0;
}