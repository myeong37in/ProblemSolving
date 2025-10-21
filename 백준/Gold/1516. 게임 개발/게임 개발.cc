/*
ACM 크래프트네

dp[i]: i번 건물 완성 시간. 즉슨, i번의 선행 건물 건설 시간 중 최댓값 + i번 건물 건설 시간
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<int> build, dp;

int dfs(int cur) {
    if (dp[cur] != -1) {
        return dp[cur];
    }
    
    dp[cur] = 0;

    for (const int& next : graph[cur]) {
        dp[cur] = std::max(dp[cur], dfs(next));
    }

    dp[cur] += build[cur];

    return dp[cur];
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    graph.resize(N + 1);
    build.resize(N + 1);
    int prereq;
    for (int u = 1; u <= N; u++) {
        std::cin >> build[u];
        while (std::cin >> prereq) {
            if (prereq == -1) {
                break;
            }

            graph[u].emplace_back(prereq);
        }
    }

    dp.assign(N + 1, -1);
    for (int u = 1; u <= N; u++) {
        if (dp[u] == -1) {
            dfs(u);
        }
        std::cout << dp[u] << "\n";
    }

    return 0;
}