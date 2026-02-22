/*
평범한 위상 정렬

dp[i]: i번 완료 최소 시간

윽.. ACM Craft의 악몽이..
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<int> times, dp;

static int dfs(int cur) {
    if (dp[cur]) {
        return dp[cur];
    }

    int max_time = 0;
    for (int prereq : graph[cur]) {
        max_time = std::max(max_time, dfs(prereq));
    }

    dp[cur] = times[cur] + max_time;

    return dp[cur];
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    times.resize(N + 1);
    graph.resize(N + 1);
    
    int time, prereq, n;
    for (int i = 1; i <= N; i++) {
        std::cin >> time >> prereq;
        times[i] = time;
        for (int j = 0; j < prereq; j++) {
            std::cin >> n;
            graph[i].emplace_back(n);
        }
    }

    dp.resize(N + 1);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = std::max(ans, dfs(i));
    }

    std::cout << ans;

    return 0;
}