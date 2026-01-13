/*
DDDDPPPP
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        std::vector<int> coins(N);
        for (int i = 0; i < N; i++) {
            std::cin >> coins[i];
        }

        int M;
        std::cin >> M;

        std::vector<int> dp(M + 1);
        dp[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = coins[i]; j <= M; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        std::cout << dp[M] << "\n";
    }
    
    return 0;
}