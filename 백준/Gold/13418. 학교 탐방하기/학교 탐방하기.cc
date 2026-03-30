/*
두가지 기준으로 MST 구하면 될 듯
*/

#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int to, type;
};

struct State {
    int cur, dist;
};

struct BestStateCmp {
    bool operator()(const State& a, const State& b) const {
        return a.dist > b.dist;
    }
};

struct WorstStateCmp {
    bool operator()(const State& a, const State& b) const {
        return a.dist < b.dist;
    }
};

std::vector<std::vector<Edge>> graph;

static int BestPrim(int start, int N) {
    std::priority_queue<State, std::vector<State>, BestStateCmp> pq;
    std::vector<bool> visited(N + 1);

    pq.push({start, 0});
    int ans = 0;
    while (!pq.empty()) {
        auto [cur, weight] = pq.top();
        pq.pop();

        if (visited[cur]) {
            continue;
        }
        visited[cur] = true;
        ans += weight;

        for (auto& [nxt, type] : graph[cur]) {
            if (!visited[nxt]) {
                pq.push({nxt, type});
            }
        }
    }

    return ans;
}

static int WorstPrim(int start, int N) {
    std::priority_queue<State, std::vector<State>, WorstStateCmp> pq;
    std::vector<bool> visited(N + 1);

    pq.push({start, 0});
    int ans = 0;
    while (!pq.empty()) {
        auto [cur, weight] = pq.top();
        pq.pop();

        if (visited[cur]) {
            continue;
        }
        visited[cur] = true;
        ans += weight;

        for (auto& [nxt, type] : graph[cur]) {
            if (!visited[nxt]) {
                pq.push({nxt, type});
            }
        }
    }

    return ans;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;

    graph.resize(N + 1);
    
    int u, v, type;
    std::cin >> u >> v >> type;

    // u가 입구, v가 시작점이 되도록 고정
    if (u > v) {
        std::swap(u, v);
    }
    // 1이 오르막인 게 계산 상 편함
    int start_uphill = !type;
    int start = v;

    for (int i = 0; i < M; i++) {
        std::cin >> u >> v >> type;

        graph[u].emplace_back(Edge {v, !type});
        graph[v].emplace_back(Edge {u, !type});
    }

    int best_ans = BestPrim(start, N) + start_uphill;
    int worst_ans = WorstPrim(start, N) + start_uphill;

    std::cout << worst_ans * worst_ans - best_ans * best_ans;

    return 0;
}