/*
indegree + BFS로 풀어 봅시다
*/

#include <iostream>
#include <vector>
#include <queue>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> graph(N + 1);
    std::vector<int> indegree(N + 1);

    int num, u;
    for (int i = 0; i < M; i++) {
        std::cin >> num;

        int prev = 0;
        for (int j = 0; j < num; j++) {
            std::cin >> u;

            if (prev) {
                graph[prev].emplace_back(u);
                indegree[u]++;
            }

            prev = u;
        }
    }

    std::queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    std::vector<int> order;
    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;
        order.emplace_back(cur);

        for (int next : graph[cur]) {
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // 다 방문 못 하면 위상 정렬 불가능
    if (cnt < N) {
        std::cout << 0;
    }
    else {
        for (int u : order) {
            std::cout << u << "\n";
        }
    }

    return 0;
}