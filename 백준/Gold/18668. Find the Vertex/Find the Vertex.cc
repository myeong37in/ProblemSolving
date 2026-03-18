/*
d = 0인 정점만 시작점 후보 가능

시작점에서는 인접한 모든 정점이 d = 1

근데 시작점이 아닌 d = 0인 정점은 인접한 정점 중 d = 2인 정점이 있어야 함. 나머지 2 -> 나머지 0으로 들어오는 거니까
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> dists(n + 1);
    std::vector<std::vector<int>> graph(n + 1);

    std::vector<int> candidates;
    for (int i = 1; i <= n; i++) {
        std::cin >> dists[i];
        if (dists[i] == 0) {
            candidates.emplace_back(i);
        }
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    for (auto s : candidates) {
        bool okay = true;

        for (int dest : graph[s]) {
            if (dists[dest] != 1) {
                okay = false;
                break;
            }
        }

        if (okay) {
            std::cout << s;
            break;
        }
    }
    
    return 0;
}