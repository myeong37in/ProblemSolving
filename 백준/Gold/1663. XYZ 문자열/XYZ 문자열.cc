/*
DP긴 한데

dp[i][j]: i단계에서 j번 문자의 개수(0: X, 1: Y, 2: Z)

dp[1] = {1, 0, 0}

dp[i][0] = dp[i - 1][2]
dp[i][1] = dp[i - 1][0]
dp[i][2] = dp[i - 1][0] + dp[i - 1][1]
(i >= 2)

i단계의 길이는 dp[i][0] + dp[i][1] + dp[i][2]

길이와 각 문자의 개수는 쉽다. 그럼 위치는?

i단계의 문자열을 str[i]라고 하면
str[1] = "X", str[2] = "YZ", str[3] = "ZX"
str[i] = str[i - 3] + str[i - 2] (i >= 4)임을 간단히 알 수 있음

k번째 문자를 알고 싶다면 

최초 i = N번째 문자열에서 뒤로가기

1 <= k <= len(str[i - 3])이라면 str[i - 3]에 대해 다시 k를 찾기 

len(str[i - 3]) < k <= len(str[i])라면 str[i - 2]에 대해 k - len(str[i - 3])을 찾기

하면 되겠군요

아 자료형
*/

#include <iostream>
#include <string>
#include <vector>


int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int type, N;
    long long k;
    char c;
    std::cin >> type >> N;

    std::vector<std::vector<long long>> dp(N + 1, std::vector<long long> (3));
    std::vector<long long> str_len(N + 1);

    dp[1] = {1, 0, 0};
    str_len[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][2];
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1];

        str_len[i] = dp[i][0] + dp[i][1] + dp[i][2];
    }

    if (type == 1) {
        std::cout << str_len[N];
    }
    else if (type == 2) {
        std::cin >> k;

        std::string str[4] = {"", "X", "YZ", "ZX"};

        int cur = N;
        while (cur > 3) {
            if (1 <= k && k <= str_len[cur - 3]) {
                cur -= 3;
            }
            else {
                k -= str_len[cur - 3];
                cur -= 2;
            }
        }

        std::cout << str[cur][k - 1]; // 0-based
    }
    else {
        std::cin >> c;

        if (c == 'X') {
            std::cout << dp[N][0];
        }
        else if (c == 'Y') {
            std::cout << dp[N][1];
        }
        else {
            std::cout << dp[N][2];
        }
    }
    
    return 0;
}