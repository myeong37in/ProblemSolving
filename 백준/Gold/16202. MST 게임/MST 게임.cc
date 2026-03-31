/*
K번 MST. 그냥 턴마다 간선만 잘 제거해 주면 되겠지

간선마다 가중치가 다르므로 간선 목록들 저장해 두고 Prim에서는 최소 가중치만 판정하면 어떤 간선이 선택됐는지 볼 수 있음

그리고 MST를 이루는지 판정까지
*/

#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int to, weight;
};

struct State {
    int cur, dist;
};

auto cmp = [](const State& a, const State& b) {
    return a.dist > b.dist;
};

int visit_cnt = 1;

constexpr int INF = 2e9;

std::vector<int> visited;

std::vector<bool> removed;

std::vector<std::vector<Edge>> graph;

static int Prim(int start, int N) {
    std::priority_queue<State, std::vector<State>, decltype(cmp)> pq(cmp);
    
    pq.push({start, 0});

    int total = 0;
    int best_dist = INF;
    
    while (!pq.empty()) {
        auto [cur, dist] = pq.top();
        pq.pop();

        if (visited[cur] == visit_cnt) {
            continue;
        }

        visited[cur] = visit_cnt;
        if (cur != start) {
            best_dist = std::min(best_dist, dist);
        }
        total += dist;

        for (auto& [nxt, weight] : graph[cur]) {
            if (visited[nxt] == visit_cnt) {
                continue;
            }

            if (removed[weight]) {
                continue;
            }

            pq.push({nxt, weight});
        }
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i] != visit_cnt) {
            return -1;
        }
    }

    removed[best_dist] = true;

    return total;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M, K;
    std::cin >> N >> M >> K;

    visited.resize(N + 1);
    graph.resize(N + 1);
    removed.resize(M + 1);
    std::vector<std::pair<int, int>> edges(M + 1);
    
    int u, v;
    for (int i = 1; i <= M; i++) {
        std::cin >> u >> v;

        edges[i] = {u, v};
        graph[u].emplace_back(Edge {v, i});
        graph[v].emplace_back(Edge {u, i});
    }

    bool okay = true;
    for (int i = 0; i < K; i++) {
        if (!okay) {
            std::cout << "0 ";
            continue;
        }

        int ans = Prim(1, N);
        if (ans == -1) {
            okay = false;
            std::cout << "0 ";
        }
        else {
            std::cout << ans << " ";
        }
        visit_cnt++;
    }
    
    return 0;
}