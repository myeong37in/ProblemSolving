/*
초기 시간에 몇을 더하냐인데, 이분 탐색으로 하면 될 듯
*/

#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int v, d, t;
};

struct State {
    int cur, dist;
};

auto cmp = [](const State& a, const State& b) {
    return a.dist > b.dist;
};

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<Edge>> graph(N + 1);

    int u, v, d, t;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v >> d >> t;

        graph[u].emplace_back(Edge {v, d, t});
        graph[v].emplace_back(Edge {u, d, t}); // 오 UDT
    }

    constexpr int INF = 2e9;

    int lo = 0;
    int hi = INF;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // 먹는 연어 수

        std::vector<int> dists(N + 1, INF);
        std::priority_queue<State, std::vector<State>, decltype(cmp)> pq(cmp);

        pq.push({1, mid});
        dists[1] = mid;

        while (!pq.empty()) {
            auto [cur, dist] = pq.top();
            pq.pop();

            if (dists[cur] != dist) {
                continue;
            }

            if (cur == N) {
                break;
            }

            for (auto& [nxt, d, t] : graph[cur]) {
                // 무너짐
                if (dist + d > t) {
                    continue;
                }

                if (dists[nxt] < dist + d) {
                    continue;
                }

                dists[nxt] = dist + d;
                pq.push({nxt, dist + d});
            }
        }

        if (dists[N] == INF) {
            hi = mid - 1;
        }
        else {
            ans = mid;
            lo = mid + 1;
        }
    }

    std::cout << ans;
    
    return 0;
}