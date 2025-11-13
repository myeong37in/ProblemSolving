/*
dp[i][j][k]: 현재 i(천사/악마)를 선택하고 돌다리 인덱스가 j, 두루마리 인덱스가 k일 때 경우의 수

돌다리 길이 N, 두루마리 길이 L

초기화
roll[0]과 값이 같은 인덱스를 찾는다.
roll[0] == angel[j]인 0 <= j < N에 대해 dp[0][j][0] = 1
roll[0] == devil[j]인 0 <= j < N에 대해 dp[1][j][0] = 1

점화식
roll[k] == angel[j]일 때
dp[0][j][k] = sum of dp[1][p][k - 1] where 0 <= p <= j - 1

roll[k] == devil[j]일 때
dp[1][j][k] = sum of dp[0][p][k - 1] where 0 <= p <= j - 1

k가 끝에 도달했을 때 모든 j에 대해서 천사와 악마에 대해 dp값의 합

O(NL)
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string roll, devil, angel;
    std::cin >> roll >> devil >> angel;

    int L = roll.size();
    int N = devil.size();
    std::vector<std::vector<std::vector<int>>> dp(2, std::vector<std::vector<int>> (N, std::vector<int> (L)));

    for (int j = 0; j < N; j++) {
        if (roll[0] == angel[j]) {
            dp[0][j][0] = 1;
        }
        if (roll[0] == devil[j]) {
            dp[1][j][0] = 1;
        }
    }

    for (int k = 1; k < L; k++) {
        for (int j = 1; j < N; j++) {
            if (roll[k] == angel[j]) {
                for (int p = 0; p < j; p++) {
                    dp[0][j][k] += dp[1][p][k - 1];
                }
            }
            if (roll[k] == devil[j]) {
                for (int p = 0; p < j; p++) {
                    dp[1][j][k] += dp[0][p][k - 1];
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < N; j++) {
        ans += dp[0][j][L - 1];
        ans += dp[1][j][L - 1];
    }

    std::cout << ans;

    return 0;
}