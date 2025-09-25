/*
유량이 무엇을 뜻하는가?
서점에서 사람에게 보내는 책의 수

유량이 어디서 생겨서 어디서 사라지는가?
공급: 서점, 수요: 사람

source: super source S.
sink: super sink T.

S -> 서점 i 간선 용량: B_i. 비용: 0
서점 i -> 사람 j 간선 용량: min(B_i, A_j), 혹은 영향을 받지 않으니 간단히 INF. 비용: C_ij
사람 j -> T 간선 용량: A_j. 비용: 0
*/

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> costs, capacity, flow;

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    // super source: 0, 서점: 1 ~ M, 사람: M + 1 ~ M + N, super sink: N + M + 1
    int last_idx = N + M + 1;
    int source = 0;
    int sink = last_idx;
    std::vector<std::vector<int>> capacity(last_idx + 1, std::vector<int> (last_idx + 1));
    std::vector<std::vector<int>> flow(last_idx + 1, std::vector<int> (last_idx + 1));
    std::vector<std::vector<int>> costs(last_idx + 1, std::vector<int> (last_idx + 1));

    for (int i = M + 1; i <= M + N; i++) {
        std::cin >> capacity[i][sink];
    }

    for (int i = 1; i <= M; i++) {
        std::cin >> capacity[0][i];
    }

    constexpr int INF = 2e9;
    int c;
    for (int i = 1; i <= M; i++) {
        for (int j = M + 1; j <= M + N; j++) {
            capacity[i][j] = INF;
            std::cin >> costs[i][j];
            costs[j][i] = -costs[i][j];
        }
    }

    int ans = 0;
    while (true) {
        // Bellman-Ford의 'in practice' optimization. SPFA
        std::vector<int> parent(last_idx + 1, -1), dists(last_idx + 1, INF);
        std::vector<bool> in_queue(last_idx + 1, false);
        std::queue<int> q;
        dists[source] = 0;
        parent[source] = source;
        q.push(source);
        in_queue[source] = true;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            in_queue[cur] = false;

            for (int next = 1; next <= last_idx; next++) {
                if (capacity[cur][next] - flow[cur][next] > 0 && dists[next] > dists[cur] + costs[cur][next]) {
                    dists[next] = dists[cur] + costs[cur][next];
                    parent[next] = cur;

                    if (!in_queue[next]) {
                        q.push(next);
                        in_queue[next] = true;
                    }
                }
            }
        }

        if (parent[sink] == -1) {
            break;
        }

        int amount = INF;
        for (int p = sink; p != source; p = parent[p]) {
            amount = std::min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }

        for (int p = sink; p != source; p = parent[p]) {
            ans += amount * costs[parent[p]][p];

            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
    }

    std::cout << ans;

    return 0;
}