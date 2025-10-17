/*
이건 DP네
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> board(N, std::vector<int> (M)), dp(N, std::vector<int> (M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> board[i][j];
        }
    }

    dp[0][0] = board[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i + 1 < N) {
                dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j] + board[i + 1][j]);
            }
            if (j + 1 < M) {
                dp[i][j + 1] = std::max(dp[i][j + 1], dp[i][j] + board[i][j + 1]);
            }
            if (i + 1 < N && j + 1 < M) {
                dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] + board[i + 1][j + 1]);
            }
        }
    }

    std::cout << dp[N - 1][M - 1];

    return 0;
}