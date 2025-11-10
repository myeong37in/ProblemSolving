/*
입력이... 이게 맞나?

dp[i] = 1에서 i년까지 커버하는 최소 비용

점화식
dp[i] = min(dp[k - 1] + c + m(k, i)) for 1 <= k <= i

초기
dp[0] = 0

O(N^2)
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int c, n;
    while (std::cin >> c >> n) {        
        std::vector<std::vector<int>> costs(n + 1, std::vector<int> (n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                std::cin >> costs[i][j];
            }
        }

        std::vector<int> dp(n + 1, 2e9);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                dp[i] = std::min(dp[i], dp[k - 1] + c + costs[k][i]);
            }
        }

        std::cout << dp[n] << "\n";
    }

    return 0;
}