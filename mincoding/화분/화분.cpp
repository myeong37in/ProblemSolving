/*
dp[i][j]: i번 화분까지 비료를 주고 i번 화분에 준 비료가 j번일 때의 최댓값

dp[0][0] = fert1[0]
dp[0][1] = fert2[0]

dp[i][0] = max(dp[i - 1][0] + fert1[i] - p, dp[i - 1][1] + fert1[i])
dp[i][1] = max(dp[i - 1][0] + fert2[i], dp[i - 1][1] + fert2[i] - p)
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int n, p;
        std::cin >> n >> p;

        std::vector<int> fert1(n);
        for (int i = 0; i < n; i++) {
            std::cin >> fert1[i];
        }

        std::vector<int> fert2(n);
        for (int i = 0; i < n; i++) {
            std::cin >> fert2[i];
        }

        std::vector<std::vector<int>> dp(n, std::vector<int> (2));

        dp[0][0] = fert1[0];
        dp[0][1] = fert2[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = std::max(dp[i - 1][0] + fert1[i] - p, dp[i - 1][1] + fert1[i]);
            dp[i][1] = std::max(dp[i - 1][0] + fert2[i], dp[i - 1][1] + fert2[i] - p);
        }

        std::cout << "#" << t << " " << std::max(dp[n - 1][0], dp[n - 1][1]) << "\n";
    }

    return 0;
}