#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

std::vector<std::vector<int>> graph;
std::vector<bool> visited;

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    constexpr int INF = 2e9;

    graph.resize(N + 1);
    visited.resize(N + 1);
    int u, v;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    std::vector<int> order(N);
    for (int i = 0; i < N; i++) {
        std::cin >> order[i];
    }

    if (order[0] != 1) {
        std::cout << 0;
        return 0;
    }

    std::queue<int> q;
    q.push(1);
    visited[1] = true;
    bool okay = true;
    int parent_idx = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        std::unordered_set<int> children; // 현재 부모의 자식 셋
        for (const int& next : graph[cur]) {
            if (!visited[next]) {
                children.insert(next);
            }
        }

        for (int i = 1; i <= children.size(); i++) { // 다음 연속한 방문 순서에 모든 자식이 있는지 확인
            if (children.find(order[parent_idx + i]) == children.end()) {
                okay = false;
                break;
            }
        }

        if (!okay) {
            break;
        }

        for (int i = 1; i <= children.size(); i++) {
            int next = order[parent_idx + i];
            visited[next] = true;
            q.push(next);
        }

        parent_idx += children.size();
    }

    std::cout << (okay ? 1 : 0);

    return 0;
}