/*
트리: 임의 정점에서 다른 정점으로의 경로가 유일하게 결정됨

결국 LCA 문제인데 binary lifting으로 쿼리 당 부모 찾기 O(logN)
거리 찾기는 루트로의 거리를 미리 구해 두면 dists[u] + dists[v] - 2 * dists[(u와 v의 LCA)]로 상수 시간에 구해짐

O((N + M) logN)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>

struct Edge {
    int to, weight;
};

std::vector<std::vector<Edge>> graph;
std::vector<std::vector<int>> parents;
std::vector<int> depths, dists;

static void dfs(int cur, int par) {
    parents[cur][0] = par;
    depths[cur] = depths[par] + 1;

    for (const auto& [next, weight] : graph[cur]) {
        if (next == par) {
            continue;
        }

        dists[next] = dists[cur] + weight;
        dfs(next, cur);
    }
}

static int GetLCA(int u, int v, int max_k) {
    if (depths[u] < depths[v]) {
        std::swap(u, v);
    }

    int diff = depths[u] - depths[v];
    for (int k = 0; k <= max_k; k++) {
        if (diff & (1 << k)) {
            u = parents[u][k];
        }
    }

    if (u == v) {
        return u;
    }

    for (int k = max_k; k >= 0; k--) {
        if (parents[u][k] != parents[v][k]) {
            u = parents[u][k];
            v = parents[v][k];
        }
    }

    return parents[u][0];
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    graph.resize(N + 1);
    int u, v, w;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> u >> v >> w;
        graph[u].emplace_back(Edge {v, w});
        graph[v].emplace_back(Edge {u, w});
    }

    int max_k = std::log2(N);
    parents.assign(N + 1, std::vector<int> (max_k + 1));
    depths.resize(N + 1);
    dists.resize(N + 1);

    dfs(1, 0);

    for (int k = 1; k <= max_k; k++) {
        for (int u = 1; u <= N; u++) {
            parents[u][k] = parents[parents[u][k - 1]][k - 1];
        }
    }

    int M;
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v;
        int lca = GetLCA(u, v, max_k);
        int ans = dists[u] + dists[v] - 2 * dists[lca];
        std::cout << ans << "\n";
    }

    return 0;
}