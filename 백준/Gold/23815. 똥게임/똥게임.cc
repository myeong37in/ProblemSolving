/*
DP인 듯. 2차원으로

dp[i][0]: i번까지 스킵 없이 갔을 때 최대 인원
dp[i][1]: i번까지 한 번 스킵했을 때 최대 인원
(0 < i <= N)
*/

#include <iostream>
#include <vector>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> dp(N + 1, std::vector<int> (2));
    dp[0][0] = dp[0][1] = 1;

    constexpr int INVALID = -1e9;

    std::string option1, option2;
    for (int i = 1; i <= N; i++) {
        std::cin >> option1 >> option2;

        int option1_non_skip, option1_skip, option2_non_skip, option2_skip;
        
        char op = option1[0];
        if (op == '+') {
            option1_non_skip = dp[i - 1][0] + static_cast<int>(option1[1] - '0');
            option1_skip = std::max(dp[i - 1][1] + static_cast<int>(option1[1] - '0'), dp[i - 1][0]); // 스킵했을 때 최대 = max(이전에 스킵했다면 이번 선택지 계산, 이전에 스킵하지 않았다면 스킵)
        }
        else if (op == '*') {
            option1_non_skip = dp[i - 1][0] * static_cast<int>(option1[1] - '0');
            option1_skip = std::max(dp[i - 1][1] * static_cast<int>(option1[1] - '0'), dp[i - 1][0]);
        }
        else if (op == '-') {
            option1_non_skip = dp[i - 1][0] - static_cast<int>(option1[1] - '0');
            option1_skip = std::max(dp[i - 1][1] - static_cast<int>(option1[1] - '0'), dp[i - 1][0]);
        }
        else if (op == '/') {
            option1_non_skip = dp[i - 1][0] / static_cast<int>(option1[1] - '0');
            option1_skip = std::max(dp[i - 1][1] / static_cast<int>(option1[1] - '0'), dp[i - 1][0]);
        }

        op = option2[0];
        if (op == '+') {
            option2_non_skip = dp[i - 1][0] + static_cast<int>(option2[1] - '0');
            option2_skip = std::max(dp[i - 1][1] + static_cast<int>(option2[1] - '0'), dp[i - 1][0]);
        }
        else if (op == '*') {
            option2_non_skip = dp[i - 1][0] * static_cast<int>(option2[1] - '0');
            option2_skip = std::max(dp[i - 1][1] * static_cast<int>(option2[1] - '0'), dp[i - 1][0]);
        }
        else if (op == '-') {
            option2_non_skip = dp[i - 1][0] - static_cast<int>(option2[1] - '0');
            option2_skip = std::max(dp[i - 1][1] - static_cast<int>(option2[1] - '0'), dp[i - 1][0]);
        }
        else if (op == '/') {
            option2_non_skip = dp[i - 1][0] / static_cast<int>(option2[1] - '0');
            option2_skip = std::max(dp[i - 1][1] / static_cast<int>(option2[1] - '0'), dp[i - 1][0]);
        }

        dp[i][0] = std::max(option1_non_skip, option2_non_skip);
        dp[i][1] = std::max(option1_skip, option2_skip);

        // 중간에 0 이하로 떨어지는 경로는 못 감
        if (dp[i][0] <= 0) {
            dp[i][0] = INVALID;
        }
        
        if (dp[i][1] <= 0) {
            dp[i][1] = INVALID;
        }

        if (dp[i][0] == INVALID && dp[i][1] == INVALID) {
            std::cout << "ddong game";
            return 0;
        }
    }

    std::cout << std::max(dp[N][0] , dp[N][1]);

    return 0;
}