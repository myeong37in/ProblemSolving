/*
입력 형식이 좀 귀찮긴 하군요

각 사람이 각 도시에 도달하는 시간을 구해서 모든 사람이 도달하는 도시가 없으면 -1, 있으면 최솟값을 구하면 되겠다
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Edge {
    int to, dist;
};

struct Friend {
    int from, unit_time;
};

struct State {
    int to, dist;
};

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, P, M;
        std::cin >> N >> P >> M;

        std::vector<Friend> friends(P + 1);
        for (int i = 1; i <= P; i++) {
            std::cin >> friends[i].from >> friends[i].unit_time;
        }

        std::vector<std::vector<Edge>> graph(N + 1);
        int dist, city_cnt;
        for (int i = 0; i < M; i++) {
            std::cin >> dist >> city_cnt;

            int u, v;
            std::cin >> u;
            for (int j = 0; j < city_cnt - 1; j++) {
                std::cin >> v;
                graph[u].emplace_back(Edge {v, dist});
                graph[v].emplace_back(Edge {u, dist});

                u = v; // prev = cur
            }
        }

        constexpr int INF = 2e9;
        std::vector<std::vector<int>> dists(P + 1, std::vector<int> (N + 1, INF));
        for (int p = 1; p <= P; p++) {
            const auto& [from, unit_time] = friends[p];
            
            // BFS
            std::queue<State> q;
            q.push({from, 0});
            dists[p][from] = 0;

            while (!q.empty()) {
                auto [cur, dist] = q.front();
                q.pop();

                for (const auto& [next, nd] : graph[cur]) {
                    if (dists[p][next] > dist + nd * unit_time) {
                        dists[p][next] = dist + nd * unit_time;
                        q.push({next, dist + nd * unit_time});
                    }
                }
            }
        }

        std::vector<int> dists_to_cites(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            for (int p = 1; p <= P; p++) {
                // 모든 사람의 도달 시간 중 최댓값이 그 도시에 모두 모이는 시간
                dists_to_cites[i] = std::max(dists_to_cites[i], dists[p][i]);
            }
        }

        // 그중 최솟값이 답
        int ans = *std::min_element(dists_to_cites.begin() + 1, dists_to_cites.end());
        std::cout << "Case #" << tc << ": " << (ans == INF ? -1 : ans) << "\n";
    }

    return 0;
}