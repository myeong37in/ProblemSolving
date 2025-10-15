/*
모듈러 7을 기준으로 같은 일

일 중 일부를 고른 합 sum에 대해 sum % 7 = 4면 성공
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
        seq[i] %= 7;

        if (seq[i] == 4) { // 바로 월->금
            std::cout << "YES";
            return 0;
        }
    }

    std::vector<bool> dp(7); // dp[i]: 나머지가 i가 되도록 수를 고를 수 있는지
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        std::vector<bool> next_dp = dp;
        for (int j = 0; j < 7; j++) {
            if (dp[j]) {
                next_dp[(j + seq[i]) % 7] = true;
            }
        }

        if (next_dp[4]) {
            std::cout << "YES";
            return 0;
        }

        std::swap(dp, next_dp);
    }

    std::cout << "NO";

    return 0;
}