/*
dists[i][j]: i번 정점까지 j개 포장해서 가는 최단 거리

dists[N][0]에서 dists[N][K]까지 중 최솟값이 답
*/

#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int to, weight;
};

struct State {
    int to, pojang;
    long long dist;
};

auto cmp = [](const State& a, const State& b) {
    return a.dist > b.dist;
};

constexpr long long INF = 9e18;

std::vector<std::vector<Edge>> graph;
std::vector<std::vector<long long>> dists;

void Dijkstra(int start, int N, int K) {
    std::priority_queue<State, std::vector<State>, decltype(cmp)> pq(cmp);
    pq.push({start, 0, 0});
    dists[start][0] = 0;

    while (!pq.empty()) {
        auto [cur, pojang, dist] = pq.top();
        pq.pop();

        if (dists[cur][pojang] != dist) {
            continue;
        }

        if (cur == N) {
            return;
        }

        for (const auto& [next, weight] : graph[cur]) {
            long long nd = dist + weight;
            int np = pojang + 1;
            if (dists[next][pojang] > nd) { // 포장 안 하고 가기
                dists[next][pojang] = nd;
                pq.push({next, pojang, nd});
            }

            if (np <= K && dists[next][np] > dist) { // 포장하고 가기
                dists[next][np] = dist;
                pq.push({next, np, dist});
            }
        }
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, K;
    std::cin >> N >> M >> K;

    graph.resize(N + 1);
    int u, v, w;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v >> w;
        graph[u].emplace_back(Edge {v, w});
        graph[v].emplace_back(Edge {u, w});
    }

    dists.assign(N + 1, std::vector<long long> (K + 1, INF));
    Dijkstra(1, N, K);
    
    long long best = INF;
    for (int i = 0; i <= K; i++) {
        best = std::min(best, dists[N][i]);
    }

    std::cout << best;

    return 0;
}