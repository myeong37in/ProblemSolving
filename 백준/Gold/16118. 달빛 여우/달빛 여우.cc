/*
달빛 여우: 평범한 Dijkstra
달빛 늑대: 경로 길이의 parity에 따라 가중치가 절반, 혹은 2배. 거리를 2차원으로 하면 되겠군
*/

#include <iostream>
#include <vector>
#include <queue>

struct FoxState {
    int to, dist;
};

struct WolfState {
    int to, dist, parity;
};

struct Edge {
    int v, w;
};

auto cmp = [](const auto& a, const auto& b) {
    return a.dist > b.dist;
};

std::vector<std::vector<Edge>> graph;
std::vector<int> fox_dists;
std::vector<std::vector<int>> wolf_dists;

constexpr int INF = 2e9;

void FoxDijkstra(int start) {
    std::priority_queue<FoxState, std::vector<FoxState>, decltype(cmp)> pq(cmp);
    fox_dists[start] = 0;
    pq.push({1, 0});

    while (!pq.empty()) {
        auto [cur, dist] = pq.top();
        pq.pop();

        if (fox_dists[cur] != dist) {
            continue;
        }

        for (const auto& [nxt, w] : graph[cur]) {
            int nd = w + dist;
            if (fox_dists[nxt] > nd) {
                fox_dists[nxt] = nd;
                pq.push({nxt, nd});
            }
        }
    }
}

void WolfDijkstra(int start) {
    std::priority_queue<WolfState, std::vector<WolfState>, decltype(cmp)> pq(cmp);
    wolf_dists[start][0] = 0;
    pq.push({1, 0, 0});

    while (!pq.empty()) {
        auto [cur, dist, parity] = pq.top();
        pq.pop();

        if (wolf_dists[cur][parity] != dist) {
            continue;
        }

        for (const auto& [nxt, w] : graph[cur]) {
            int nd = dist;
            if (!parity) {
                nd += w / 2;
            }
            else {
                nd += 2 * w;
            }

            int np = !parity;
            if (wolf_dists[nxt][np] > nd) {
                wolf_dists[nxt][np] = nd;
                pq.push({nxt, nd, np});
            }
        }
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    graph.resize(N + 1);
    fox_dists.assign(N + 1, INF);
    wolf_dists.assign(N + 1, std::vector<int> (2, INF));

    int u, v, w;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v >> w;
        graph[u].emplace_back(Edge {v, 2 * w}); // 2배 해서 넣으면 소수점 계산 안 해도 됨
        graph[v].emplace_back(Edge {u, 2 * w});
    }

    FoxDijkstra(1);
    WolfDijkstra(1);

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (fox_dists[i] < std::min(wolf_dists[i][0], wolf_dists[i][1])) {
            cnt++;
        }
    }

    std::cout << cnt;

    return 0;
}