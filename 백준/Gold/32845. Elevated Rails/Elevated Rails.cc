/*
섬1과 섬3의 정점을 연결한다고 하면 섬1-섬2, 섬2-섬3 사이에 다리를 놓아야 경로가 최대가 됨
이때 경로의 길이: 섬1, 섬3에서 연결할 정점을 루트로 하는 각각의 트리의 랭크 + 1(본인 포함) + 섬2의 지름
가 됨

그럼 트리에서 모든 정점의 랭크를 구해야 하는데
1) 트리의 지름과 한쪽 끝 정점을 찾는다.
2) 그 정점으로부터 DFS 하면서 (지름 - depth, depth) 중 더 큰 값이 랭크가 된다.

그럼 나머지 하나의 섬을 어떻게 O(1)에 구함
각 정점이 어느 섬에 속하는지를 저장, 섬마다 지름을 저장해 두면?
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<bool> visited;
std::vector<int> in_tree, path_len;
int max_depth = 0;
int root = 0;

static void dfs(int cur, int depth) {
    visited[cur] = true;
    in_tree.emplace_back(cur);

    if (depth > max_depth) {
        max_depth = depth;
        root = cur;
    }

    for (int next : graph[cur]) {
        if (!visited[next]) {
            dfs(next, depth + 1);
        }
    }
}

static void CalcDiameterAndDists(int cur, std::vector<int>& dists, int depth) {
    visited[cur] = true;
    dists[cur] = depth;

    if (depth > max_depth) {
        max_depth = depth;
        root = cur;
    }

    for (int next : graph[cur]) {
        if (!visited[next]) {
            CalcDiameterAndDists(next, dists, depth + 1);
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;

    graph.resize(n + 1);

    int u, v;
    for (int i = 0; i < n - 3; i++) {
        std::cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    visited.resize(n + 1);
    path_len.assign(n + 1, 1);
    std::vector<int> diameters(3); // 트리 3개의 지름
    std::vector<int> node_to_island(n + 1); // i번 정점이 어떤 섬(트리)에 속하는지(0, 1, 2)
    int island_idx = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, 0);
        }
        else {
            continue;
        }

        for (int n : in_tree) {
            visited[n] = false;
            node_to_island[n] = island_idx;
        }

        max_depth = 0;

        std::vector<int> dists1(n + 1), dists2(n + 1); // 트리의 지름을 이루는 두 정점들로부터 다른 정점들까지의 거리

        CalcDiameterAndDists(root, dists1, 0);

        for (int n : in_tree) {
            visited[n] = false;
        }

        CalcDiameterAndDists(root, dists2, 0);

        for (int n : in_tree) {
            path_len[n] = std::max(dists1[n], dists2[n]) + 1;
        }

        diameters[island_idx] = max_depth;
        
        in_tree.clear();
        max_depth = 0;
        island_idx++;
    }

    for (int i = 0; i < q; i++) {
        std::cin >> u >> v;
        int island1 = node_to_island[u];
        int island2 = node_to_island[v];

        int ans = path_len[u] + path_len[v];
        if (island1 + island2 == 1) { // 0, 1번 섬의 정점이 쿼리로 들어옴
            ans += diameters[2] + 1; // 지름 + 1이 지나는 최대 정점 수
        }
        else if (island1 + island2 == 2) { // 0, 2
            ans += diameters[1] + 1;
        }
        else if (island1 + island2 == 3) { // 1, 2
            ans += diameters[0] + 1;
        }

        std::cout << ans << "\n";
    }
    
    return 0;
}