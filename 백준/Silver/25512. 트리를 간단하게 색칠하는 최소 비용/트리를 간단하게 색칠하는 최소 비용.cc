/*
방법은 하나. 아니 정확히는 둘
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<int> color;

static void dfs(int cur, int parent) {
    for (int next : graph[cur]) {
        if (next == parent) {
            continue;
        }

        color[next] = !color[cur];
        dfs(next, cur);
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    graph.resize(n);
    color.resize(n);
    
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        std::cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    std::vector<std::pair<int, int>> costs(n);
    for (int i = 0; i < n; i++) {
        std::cin >> costs[i].first >> costs[i].second;
    }

    color[0] = 0;
    dfs(0, -1);

    // total1: 그대로, total2: 반대 색으로
    long long total1 = 0, total2 = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            total1 += costs[i].first;
            total2 += costs[i].second;
        }
        else {
            total1 += costs[i].second;
            total2 += costs[i].first;
        }
    }

    std::cout << std::min(total1, total2);
    
    return 0;
}