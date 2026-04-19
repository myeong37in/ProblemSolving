/*
전체 참가자 RS명.

어떤 등수가 방 우승자의 등수라면 어떤 방의 첫 번째 사람, 우승자가 아니라면 우승자가 나온 방에 들어가는 다른 사람

현재까지 우승자가 i명 나왔다면 그 뒤에 나올 수 있는 우승자가 아닌 참가자의 수는 최대 i(S-1)명

앞부터 어떤 시점까지 우승자가 i명 아닌 사람이 j명일 때

j <= i(S - 1)

dp[i][j]: 우승자가 i명, 아닌 사람이 j명일 때 가능한 접두 개수. 이때 j <= i(S - 1)

dp[0][0] = 1

i + 1번 등수가 우승자일 경우

dp[i + 1][j] += dp[i][j] (i < R)

i + 1번 등수가 우승자가 아닐 경우

dp[i][j + 1] += dp[i][j]

최종 답은 dp[R][R(S - 1)] * R!
*/

#include <iostream>
#include <vector>

constexpr long long MOD = 1e9 + 7;

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, S;
    std::cin >> R >> S;

    int L = R * (S - 1); // 우승자 아니 사람 수

    std::vector<std::vector<long long>> dp(R + 1, std::vector<long long>(L + 1));
    dp[0][0] = 1;

    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= L; j++) {
            if (dp[i][j] == 0) {
                continue;
            }

            // i + 1번이 방 우승자
            if (i < R) {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            }

            // 우승자 아님
            if (j < L && i > 0 && j < i * (S - 1)) {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }
        }
    }

    long long fact = 1;
    for (int i = 2; i <= R; i++) {
        fact = (fact * i) % MOD;
    }

    std::cout << (dp[R][L] * fact) % MOD;

    return 0;
}