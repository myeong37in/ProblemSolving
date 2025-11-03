/*
정방향, 역방향 그래프 만들어 DFS, 앞/뒤로 몇 명 있는지 확인. 합쳐서 N - 1명이면 순위 확정

O(N(N+M))
*/

#include <iostream>
#include <vector>

std::vector<int> visited;

int visit_count = 1;

void dfs(const std::vector<std::vector<int>>& graph, const int& cur, int& cnt) {
    visited[cur] = visit_count;

    for (const int& next : graph[cur]) {
        if (visited[next] != visit_count) {
            cnt++;
            dfs(graph, next, cnt);
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, M;
        std::cin >> N >> M;

        std::vector<std::vector<int>> fwd_graph(N + 1), rev_graph(N + 1);
        visited.assign(N + 1, 0);

        int u, v;
        for (int i = 0; i < M; i++) {
            std::cin >> u >> v;
            fwd_graph[u].emplace_back(v);
            rev_graph[v].emplace_back(u);
        }

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            int fwd_cnt = 0;
            int rev_cnt = 0;
            dfs(fwd_graph, i, fwd_cnt);
            visit_count++;
            dfs(rev_graph, i, rev_cnt);
            visit_count++;
            
            if (fwd_cnt + rev_cnt == N - 1) {
                ans++;
            }
        }

        std::cout << "#" << tc << " " << ans << "\n";;
    }


    return 0;
}