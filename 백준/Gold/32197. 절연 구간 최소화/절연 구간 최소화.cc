/*
T가 달라지면 가중치 1, 같으면 가중치 0

0-1 BFS
*/

#include <iostream>
#include <vector>
#include <deque>

struct State {
    int cur, prev_power, dist;
};

std::vector<std::vector<std::pair<int, int>>> graph;

int bfs(int A, int B) {
    int N = graph.size();
    std::deque<State> deq;
    std::vector<std::vector<bool>> visited(N, std::vector<bool> (2)); // 0으로 방문, 1로 방문

    deq.push_back({A, -1, 0});

    while (!deq.empty()) {
        auto [cur, prev_power, dist] = deq.front();
        deq.pop_front();

        if (cur == B) {
            return dist - 1; // 최초 +1 제거
        }

        for (const auto& [next, power] : graph[cur]) {
            if (visited[next][power]) {
                continue;
            }

            visited[next][power] = true;
            if (prev_power != power) {
                deq.push_back({next, power, dist + 1});
            }
            else {
                deq.push_front({next, power, dist});
            }
        }
    }

    return -1;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    graph.resize(N + 1);
    int s, e, t;
    for (int i = 0; i < M; i++) {
        std::cin >> s >> e >> t;
        graph[s].emplace_back(e, t);
        graph[e].emplace_back(s, t);
    }
    std::cin >> s >> e;

    int ans = bfs(s, e);
    std::cout << ans;

    return 0;
}