/*
갈 수 없는 분기점(노드)으로의 간선은 안 만들면 되겠지. 10^10 주의하고
*/

#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int to, weight;
};

struct Node {
    int id;
    long long dist;
};

auto cmp = [](const Node& a, const Node& b) {
    return a.dist > b.dist;
};

std::vector<std::vector<Edge>> graph;
std::vector<long long> dists;

void Dijkstra(int start) {
    dists[start] = 0;
    std::priority_queue<Node, std::vector<Node>, decltype(cmp)> pq(cmp);
    pq.push({start, 0});

    int N = graph.size();

    while (!pq.empty()) {
        auto [cur, dist] = pq.top();
        pq.pop();

        if (dists[cur] != dist) {
            continue;
        }

        for (const auto& [to, weight] : graph[cur]) {
            if (dist + weight >= dists[to]) {
                continue;
            }

            dists[to] = dist + weight;
            pq.push({to, dist + weight});
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;

    graph.resize(N);
    
    constexpr long long INF = 9e18;
    dists.assign(N, INF);

    std::vector<int> valid(N);
    for (int i = 0; i < N; i++) {
        std::cin >> valid[i];
    }
    valid[N - 1] = 0;

    int u, v, w;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v >> w;
        if (valid[u] || valid[v]) {
            continue;
        }

        graph[u].emplace_back(Edge {v, w});
        graph[v].emplace_back(Edge {u, w});
    }

    Dijkstra(0);

    std::cout << (dists[N - 1] == INF ? -1 : dists[N - 1]);
    
    return 0;
}