/*
4개의 노드가 mesh형으로 6개의 간선으로 연결되어 있을 때 최소 4개 색을 쓰게 됨

트리에서 임의 4개의 정점을 고르면 모두 연결되어 있거나 되어 있지 않거나

모두 연결되어 있을 경우 간선은 최대 3개(사이클 x) -> 답은 3개

1번부터 시작해서 4개 고릅시다.
*/

#include <iostream>
#include <vector>

std::vector<int> selected;
std::vector<bool> visited;
std::vector<std::vector<int>> graph; 

static void dfs(int cur) {
    if (selected.size() >= 4) {
        return;
    }
    visited[cur] = true;
    selected.emplace_back(cur);

    for (int next : graph[cur]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    graph.resize(N + 1);
    visited.resize(N + 1);
    int u, v;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    dfs(1);

    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            int u = selected[i], v = selected[j];
            bool exist = false;
            for (int n : graph[u]) {
                if (n == v) {
                    exist = true;
                }
            }

            if (!exist) {
                ans.emplace_back(u, v);
            }
        }
    }

    std::cout << ans.size() << "\n";
    for (auto& [u, v] : ans) {
        std::cout << u << " " << v << "\n";
    }
    
    return 0;
}