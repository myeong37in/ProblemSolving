/*
1을 포함하는 음수 사이클이 있으면 1에 도달할 수 있는 모든 정점이 가능함

그 외에는 1로 향하는 거리 기댓값이 T 이하인 정점을 골라야겠군..?

??

Bellman-Ford는 O(NM)인데요..?

양방향이니까 1이 포함된 경로에서 음수 간선이 있으면 1에 도달할 수 있는 모든 정점이 가능함

1에서 Dijkstra를 돌리되 음수 가중치가 있으면 기록하면 되겠다. O((N + M) log N)
*/

// #include <iostream>
// #include <vector>

// struct Edge {
//     int to, dist;
// };

// std::vector<std::vector<Edge>> graph;
// std::vector<long long> dists;

// constexpr long long INF = 9e18;

// // 1 포함 음수 사이클이 있으면 true
// static bool BellmanFord(int start) {
//     int N = graph.size() - 1;
//     dists[start] = 0;
    
//     // N - 1번 완화
//     for (int it = 1; it <= N - 1; it++) {
//         bool relaxed = false;
//         for (int u = 1; u <= N; u++) {
//             if (dists[u] == INF) {
//                 continue;
//             }

//             for (const auto& [next, dist] : graph[u]) {
//                 long long nd = dists[u] + dist;
//                 if (nd < dists[next]) {
//                     dists[next] = nd;
//                     relaxed = true;
//                 }
//             }
//         }

//         if (!relaxed) {
//             break;
//         }

//         for (int u = 1; u <= N; u++) {
//             if (dists[u] == INF) {
//                 continue;
//             }

//             for (const auto& [next, dist] : graph[u]) {
//                 long long nd = dists[u] + dist;
//                 if (nd < dists[next]) {
//                     return true;
//                 }
//             }
//         }
//     }

//     return false;
// }

// int main(int argc, char* argv[]){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int N, M;
//     std::cin >> N >> M;

//     graph.resize(N + 1);
//     int u, v, a, b;
//     for (int i = 0; i < M; i++) {
//         std::cin >> u >> v >> a >> b;
//         graph[u].emplace_back(Edge {v, a + b}); // 가중치 2배
//         graph[v].emplace_back(Edge {u, a + b});
//     }
//     long long T;
//     std::cin >> T;

//     std::vector<int> ans;
//     dists.assign(N + 1, INF);
//     if (BellmanFord(1)) {
//         for (int i = 2; i <= N; i++) {
//             if (dists[i] != INF) {
//                 ans.emplace_back(i);
//             }
//         }
//     }
//     else {
//         for (int i = 2; i <= N; i++) {
//             if (dists[i] <= 2 * T) { // 검사도 2배
//                 ans.emplace_back(i);
//             }
//         }
//     }

//     std::cout << ans.size() << "\n";
//     for (const int& n : ans) {
//         std::cout << n << " ";
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int to, dist;
};

struct State {
    int to;
    long long dist;
};

auto cmp = [](const State& a, const State& b) {
    return a.dist > b.dist;
};

std::vector<std::vector<Edge>> graph;
std::vector<long long> dists;

constexpr long long INF = 9e18;

bool neg_cycle = false;

static void Dijkstra(int start) {
    std::priority_queue<State, std::vector<State>, decltype(cmp)> pq(cmp);
    pq.push({start, 0});
    dists[start] = 0;

    while (!pq.empty()) {
        auto [cur, dist] = pq.top();
        pq.pop();

        if (dists[cur] != dist) {
            continue;
        }

        for (const auto& e : graph[cur]) {
            int next = e.to;
            long long nd = e.dist + dist;
            if (nd < 0) {
                neg_cycle = true;
                nd *= -1; // 양수로 바꿔서 계산. 이 시점에서 거리값은 무의미함
            }

            if (dists[next] > nd) {
                dists[next] = nd;
                pq.push({next, nd});
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
    int u, v, a, b;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v >> a >> b;
        graph[u].emplace_back(Edge {v, a + b}); // 가중치 2배
        graph[v].emplace_back(Edge {u, a + b});
    }
    long long T;
    std::cin >> T;

    std::vector<int> ans;
    dists.assign(N + 1, INF);

    Dijkstra(1);

    if (neg_cycle) {
        for (int i = 2; i <= N; i++) {
            if (dists[i] != INF) {
                ans.emplace_back(i);
            }
        }
    }
    else {
        for (int i = 2; i <= N; i++) {
            if (dists[i] <= 2 * T) { // 검사도 2배
                ans.emplace_back(i);
            }
        }
    }

    std::cout << ans.size() << "\n";
    for (const int& n : ans) {
        std::cout << n << " ";
    }

    return 0;
}