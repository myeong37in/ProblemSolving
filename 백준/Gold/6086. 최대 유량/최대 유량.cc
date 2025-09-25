/*
Edmonds-Karp를 다시 배워 봅시다.
*/

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> capacity, flow;

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    constexpr int MAX = 52, INF = 2e9;
    capacity.assign(MAX, std::vector<int> (MAX));
    flow.assign(MAX, std::vector<int> (MAX));

    char u, v;
    int cap;
    for (int i = 0; i < N; i++) {
        std::cin >> u >> v >> cap;

        if (u >= 'a') {
            u = u - 'a' + 26;    
        }
        else {
            u -= 'A';
        }

        if (v >= 'a') {
            v = v - 'a' + 26;    
        }
        else {
            v -= 'A';
        }

        int ui = u;
        int vi = v;

        // 양방향
        capacity[ui][vi] += cap;
        capacity[vi][ui] += cap;
    }

    constexpr int source = 0, sink = 25; // source: 'A', sink: 'Z'
    int ans = 0;
    while (true) {
        std::vector<int> parent(MAX, -1);
        std::queue<int> q;
        q.push(source);
        parent[source] = source;

        while (!q.empty() && parent[sink] == -1) {
            int cur = q.front();
            q.pop();

            for (int next = 0; next < MAX; next++) {
                if (capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1) {
                    q.push(next);
                    parent[next] = cur;
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
            // 양방향
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] += amount;
        }

        ans += amount;
    }

    std::cout << ans;

    return 0;
}