/*
연결 요소 구하고 플로이드-워셜 쓰면 O(N^3)인 듯?
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::vector<int>> adj_mat;
std::vector<std::vector<int>> components;
std::vector<bool> visited;

void bfs(int start, int idx, int N) {
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (visited[i] || adj_mat[cur][i] == 0) {
                continue;
            }

            components[idx].emplace_back(i);
            q.push(i);
            visited[i] = true;
        }
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    constexpr int INF = 1e9;
    adj_mat.assign(N + 1, std::vector<int> (N + 1));
    std::vector<std::vector<int>> dists(N + 1, std::vector<int> (N + 1, INF));
    int u, v;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v;
        adj_mat[u][v] = adj_mat[v][u] = 1;
        dists[u][v] = dists[v][u] = 1;
    }

    for (int i = 1; i <= N; i++) {
        dists[i][i] = 0;
    }

    visited.resize(N + 1);
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            components.emplace_back();
            components[cnt].emplace_back(i);
            bfs(i, cnt, N);
            cnt++;
        }
    }
    
    std::vector<int> ans;
    for (const auto& component : components) {
        int sz = component.size();

        for (int m = 0; m < sz; m++) {
            for (int s = 0; s < sz; s++) {
                for (int e = 0; e < sz; e++) {
                    if (dists[component[s]][component[e]] > dists[component[s]][component[m]] + dists[component[m]][component[e]]) {
                        dists[component[s]][component[e]] = dists[component[s]][component[m]] + dists[component[m]][component[e]];
                    }
                }
            }
        }

        int best_dist = INF;
        int best_id = 0;
        for (int n : component) {
            int max_dist = 0;
            
            for (int m : component) {
                max_dist = std::max(max_dist, dists[n][m]);
            }

            // 거리의 최댓값이 가장 작은 노드가 대표
            if (best_dist > max_dist) {
                best_dist = max_dist;
                best_id = n;
            }
        }

        ans.emplace_back(best_id);
    }

    std::sort(ans.begin(), ans.end());

    std::cout << cnt << "\n";
    for (int n : ans) {
        std::cout << n << "\n";
    }

    return 0;
}