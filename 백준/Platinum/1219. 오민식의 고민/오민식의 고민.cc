/*
1738에서 풀어본 유형이긴 한데 다시 풀어 봅시다.

도착 도시에 도달 가능한 음수 사이클이 있는지 판정해야 하므로 간선 방향을 반대로 한 뒤 Bellman-Ford로 B -> A 경로 탐색

시작점에서도 도달 가능해야 하므로 정방향 그래프에서 경로 탐색
*/

#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int to, dist;
};

void bfs(const std::vector<std::vector<Edge>>& graph, std::vector<bool>& can_reach, int S, int E) {
    std::queue<int> q;
    q.push(S);
    can_reach[S] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (const auto& [to, dist] : graph[cur]) {
            if (!can_reach[to]) {
                can_reach[to] = true;
                q.push(to);
            }
        }
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, S, E, M;
    std::cin >> N >> S >> E >> M;

    std::vector<std::vector<Edge>> fwd_graph(N);
    std::vector<std::vector<Edge>> graph(N);
    int v, u, w;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v >> w;
        graph[v].emplace_back(Edge {u, w});
        fwd_graph[u].emplace_back(Edge {v, w});
    }

    std::vector<int> earn(N);
    for (int i = 0; i < N; i++) {
        std::cin >> earn[i];
    }

    constexpr long long INF = 4e18;
    std::vector<bool> can_reach(N);

    bfs(fwd_graph, can_reach, S, E);

    std::vector<long long> dists(N, INF);
    dists[E] = -earn[E];
    for (int it = 0; it < N - 1; it++) {
        for (int u = 0; u < N; u++) {
            if (dists[u] == INF) {
                continue;
            }

            for (const auto& [to, dist] : graph[u]) {
                long long nd = dists[u] + dist - earn[to];
                if (dists[to] > nd) {
                    dists[to] = nd;
                }
            }
        }
    }

    if (dists[S] == INF) { // 도달 불가
        std::cout << "gg";
        return 0;
    }

    for (int u = 0; u < N; u++) {
        if (dists[u] == INF) {
            continue;
        }

        for (const auto& [to, dist] : graph[u]) {
            long long nd = dists[u] + dist - earn[to];
            if (can_reach[to] && dists[to] > nd) {
                std::cout << "Gee";
                return 0;
            }
        }
    }

    std::cout << -dists[S]; // 음수면 돈 먹음, 양수면 잃음

    return 0;
}