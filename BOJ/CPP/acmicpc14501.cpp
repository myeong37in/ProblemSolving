// https://www.acmicpc.net/problem/14501
// 퇴사
// 실버 3

/*
T가 최대 5다
dp[i]: i일째까지 최대 수익
dp[1] = T_1 == 1이면  P1. 아니면 0

dp[i] = (j = i - 4부터 i까지, T_j + j - 1 == i라면 max(dp[i], dp[j - 1] + P_j))
-> i일까지의 최대 수익 vs j - 1일 전까지의 최대 수익에 i일로부터 j일 전에 일을 시작해 i일에 끝날 때 얻는 수익
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> dp(N + 1);
    std::vector<std::pair<int, int>> info(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> info[i].first >> info[i].second;
    }

    dp[1] = info[1].first == 1 ? info[1].second : 0;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1];
        for (int j = std::max(1, i - 4); j <= i; j++) {
            if (info[j].first + j - 1 == i) {
                dp[i] = std::max(dp[i], dp[j - 1] + info[j].second);
            }
        }
    }

    std::cout << dp[N];

    return 0;
}