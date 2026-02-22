#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, a, b;
    std::cin >> N >> a >> b;

    constexpr int INF = 2e9;
    std::vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + 1; // 기다리기

        if (i >= a + 1) {
            dp[i] = std::min(dp[i], dp[i - (a + 1)] + 1);
        }

        if (i >= b + 1) {
            dp[i] = std::min(dp[i], dp[i - (b + 1)] + 1);
        }
    }

    std::cout << dp[N];

    return 0;
}