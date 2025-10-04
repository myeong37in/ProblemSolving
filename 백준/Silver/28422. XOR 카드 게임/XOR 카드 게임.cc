/*
DP는 오래 안 풀면 감이 떨어진다는 게 맞는 듯. 깨닫는 데 오래 걸렸다

dp[i]: i번 카드까지 가져갔을 때 최고 점수
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    if (N == 1) {
        std::cout << 0;
        return 0;
    }

    std::vector<int> seq(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }

    if (N == 2) {
        std::cout << __builtin_popcount(seq[1] ^ seq[2]);
        return 0;
    }
    else if (N == 3) {
        std::cout << __builtin_popcount(seq[1] ^ seq[2] ^ seq[3]);
        return 0;
    }

    std::vector<int> dp(N + 1);
    dp[1] = -1e9; // 여기서 전이 방지
    dp[2] = __builtin_popcount(seq[1] ^ seq[2]);
    dp[3] = __builtin_popcount(seq[1] ^ seq[2] ^ seq[3]);
    for (int i = 4; i <= N; i++) {
        dp[i] = std::max(dp[i - 3] + __builtin_popcount(seq[i - 2] ^ seq[i - 1] ^ seq[i]), dp[i - 2] + __builtin_popcount(seq[i - 1] ^ seq[i]));
    }

    std::cout << dp[N];

    return 0;
}