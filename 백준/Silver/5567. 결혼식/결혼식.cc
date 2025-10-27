/*
BFS
*/

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> graph;
std::vector<bool> visited;

int cnt = 0;

static void bfs(int start) {
    std::queue<std::pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();
        cnt++;

        for (const int& next : graph[cur]) {
            if (!visited[next] && dist + 1 <= 2) {
                visited[next] = true;
                q.push({next, dist + 1});
            }
        }
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    graph.resize(n + 1);
    visited.resize(n + 1);
    
    int m;
    std::cin >> m;
    
    int u, v;
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    bfs(1);

    std::cout << cnt - 1; // 1번 제외

    return 0;
}