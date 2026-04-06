/*
집에서 높이가 증가하는 방향으로 Dijkstra, 고려대에서 높이가 증가하는 방향으로 Dijkstra

거리가 불필요하게 늘어나면 답이 될 수 없으므로 최단 거리 문제임 

최대 거리 Nn
*/

#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int to, dist;
};

struct State {
    int cur;
    long long dist;
};

struct StateCmp {
    bool operator()(const State& a, const State& b) const {
        return a.dist > b.dist;
    }
};

std::vector<std::vector<Edge>> graph;

std::vector<int> heights;
std::vector<long long> home_dists, korea_dists;

constexpr long long INF = 9e15;

static void HomeDijkstra(int start) {
    std::priority_queue<State, std::vector<State>, StateCmp> pq;
    pq.push({start, 0});
    home_dists[start] = 0;

    while (!pq.empty()) {
        auto [cur, dist] = pq.top();
        pq.pop();

        if (home_dists[cur] != dist) {
            continue;
        }

        for (auto& [nxt, nd] : graph[cur]) {
            // 높이가 증가하는 방향으로만 이동해야 함
            if (heights[cur] >= heights[nxt]) {
                continue;
            }

            if (home_dists[nxt] > home_dists[cur] + nd) {
                home_dists[nxt] = home_dists[cur] + nd;
                pq.push({nxt, home_dists[nxt]});
            }
        }
    }
}

static void KoreaDijkstra(int start) {
    std::priority_queue<State, std::vector<State>, StateCmp> pq;
    pq.push({start, 0});
    korea_dists[start] = 0;

    while (!pq.empty()) {
        auto [cur, dist] = pq.top();
        pq.pop();

        if (korea_dists[cur] != dist) {
            continue;
        }

        for (auto& [nxt, nd] : graph[cur]) {
            if (heights[cur] >= heights[nxt]) {
                continue;
            }

            if (korea_dists[nxt] > korea_dists[cur] + nd) {
                korea_dists[nxt] = korea_dists[cur] + nd;
                pq.push({nxt, korea_dists[nxt]});
            }
        }
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, D, E;
    std::cin >> N >> M >> D >> E;

    graph.resize(N + 1);
    heights.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        std::cin >> heights[i];
    }

    home_dists.assign(N + 1, INF);
    korea_dists.assign(N + 1, INF);

    int u, v, d;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v >> d;
        
        graph[u].emplace_back(Edge {v, d});
        graph[v].emplace_back(Edge {u, d});
    }

    HomeDijkstra(1);
    KoreaDijkstra(N);

    long long best = -INF;
    for (int i = 2; i <= N - 1; i++) {
        // 도달 불가 컷
        if (home_dists[i] == INF || korea_dists[i] == INF) {
            continue;
        }

        best = std::max(best, E * heights[i] - D * (home_dists[i] + korea_dists[i]));
    }

    if (best == -INF) {
        std::cout << "Impossible";
    }
    else {
        std::cout << best;
    }

    return 0;
}