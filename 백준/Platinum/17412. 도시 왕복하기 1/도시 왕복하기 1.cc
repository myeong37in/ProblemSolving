/*
네트워크 플로우

간선 capacity 1, 역방향은 0
Dinic 알고리즘
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const int INF = 2e9;

struct Edge {
    int to; // 다음 노드
    int capacity; // 이 간선의 잔여 용량
    int rev; // 인접 리스트 adj[to]에서 역(reverse) 간선이 위치한 인덱스
};

std::vector<std::vector<Edge>> adj;
std::vector<int> level;
std::vector<int> ptr;

void AddEdge(int u, int v, int c) {
    adj[u].push_back({v, c, static_cast<int>(adj[v].size())});
    adj[v].push_back({u, 0, static_cast<int>(adj[u].size()) - 1});
}

// level graph 형성
bool bfs(const int& start, const int& end) {
    std::fill(level.begin(), level.end(), -1);
    
    std::queue<int> q;
    q.push(start);
    level[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto& e : adj[u]) {
            if (level[e.to] < 0 && e.capacity > 0) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }

    return (level[end] >= 0);
}

// blocking flow 계산
// 증강 경로가 없을 때까지 flow를 push
int dfs(const int& u, const int& v, const int& f) {
    if (u == v || f == 0) {
        return f;
    }

    for (int &cid = ptr[u]; cid < adj[u].size(); cid++) {
        auto& e = adj[u][cid];
        if (level[e.to] == level[u] + 1 && e.capacity > 0) {
            int pushed = dfs(e.to, v, std::min(f, e.capacity));

            if (pushed > 0) {
                e.capacity -= pushed;
                adj[e.to][e.rev].capacity += pushed;
                return pushed;
            }
        }
    }

    return 0;
}

int GetMaxFlow(const int& start, const int& end) {
    int flow = 0;
    while (bfs(start, end)) {
        std::fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs(start, end, INF)) {
            flow += pushed;
        }
    }

    return flow;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, P;
    std::cin >> N >> P;

    adj.resize(N + 1);
    level.resize(N + 1);
    ptr.resize(N + 1);

    int u, v;
    for (int i = 0; i < P; i++) {
        std::cin >> u >> v;
        AddEdge(u, v, 1); // 간선 용량 1
    }

    std::cout << GetMaxFlow(1, 2);

    return 0;
}