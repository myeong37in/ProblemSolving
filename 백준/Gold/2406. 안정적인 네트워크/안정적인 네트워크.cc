/*
기본적으로 1번은 모든 컴퓨터와 연결되어 있으므로, 1번을 제외한 무슨 컴퓨터가 고장나든 모두 연결되어 있음

따라서 1번을 제외한 나머지가 모두 연결되어 있으면 됨.

Prim으로 합시다.
*/

#include <iostream>
#include <vector>
#include <queue>

struct State {
    int cur, cost, parent;
};

struct StateCmp {
    bool operator()(const State& a, const State& b) const {
        return a.cost > b.cost;
    }
};

int adj[1001][1001];

std::vector<std::pair<int, int>> ans;

static int Prim(int start, int n) {
    std::priority_queue<State, std::vector<State>, StateCmp> pq;
    std::vector<bool> visited(n + 1);

    pq.push({start, 0});
    int total = 0;
    while (!pq.empty()) {
        auto [cur, cost, parent] = pq.top();
        pq.pop();

        if (visited[cur]) {
            continue;
        }

        visited[cur] = true;
        total += cost;

        if (cost) {
            ans.emplace_back(cur, parent);
        }

        for (int nxt = 2; nxt <= n; nxt++) {
            if (visited[nxt]) {
                continue;
            }

            pq.push({nxt, adj[cur][nxt], cur});
        }
    }

    return total;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    if (n == 1) {
        std::cout << "0 0";
        return 0;
    }

    int u, v;
    std::vector<std::pair<int, int>> connected(m);
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v;

        // 이미 연결된 점끼리는 잇는 거리 0
        connected[i] = {u, v};
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> adj[i][j];
        }
    }

    for (auto& [a, b] : connected) {
        adj[a][b] = adj[b][a] = 0;
    }

    int total = Prim(2, n);

    std::cout << total << " " << ans.size() << "\n";
    for (auto& [a, b] : ans) {
        std::cout << a << " " << b << "\n";
    }
    
    return 0;
}