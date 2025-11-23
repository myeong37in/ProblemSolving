/*
음... DP인가?

2차원은 현재까지 본 마지막 인덱스가 구간에 포함되는지 안 되는지 알기 어렵다

3차원?

dp[i][j][0]: i번까지 구간이 j개일 때 i번이 비포함.
    i - 1번까지 비포함 or 포함 중 더 큰 값 채택
dp[i][j][1]: i번이 포함
    i - 1번, 구간이 j - 1개일 때 비포함 or i - 1번, 구간이 j개일 때 포함

dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1])
dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j][1]) + seq[i]

초기값
dp[i][0][0] = 0 (0 <= i <= N)
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> seq(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }

    constexpr int INF = 2e9;
    std::vector<std::vector<std::vector<int>>> dp(N + 1, std::vector<std::vector<int>> (M + 1, std::vector<int> (2, -INF)));
    for (int i = 0; i <= N; i++) {
        dp[i][0][0] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i - 1][j][1]);
            dp[i][j][1] = std::max(dp[i - 1][j][1], dp[i - 1][j - 1][0]) + seq[i];
        }
    }

    std::cout << std::max(dp[N][M][0], dp[N][M][1]);

    return 0;
}