/*
DP로 각 칸에서 출발했을 때 최대 몇 칸 갈 수 있는지를 정하면

DFS 재귀를 쓰면 메모이제이션으로 시간 단축 가능

근데 문제 설명이 잘못되어 있는데? 이동할 수 있는 칸이 아니라 방문할 수 있는 칸이라고 해야지
*/

#include <iostream>
#include <vector>

std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};
int dfs(const std::vector<std::vector<int>>& board, std::vector<std::vector<int>>& dp, const int& cur_row, const int& cur_col, const int& N) {
    if (dp[cur_row][cur_col] != 0) {
        return dp[cur_row][cur_col];
    }

    dp[cur_row][cur_col] = 1; // 일단 놓는 것도 한 칸으로 셈
    for (int i = 0; i < 4; i++) {
        int next_row = cur_row + dr[i];
        int next_col = cur_col + dc[i];

        if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= N || board[next_row][next_col] <= board[cur_row][cur_col]) {
            continue;
        }

        dp[cur_row][cur_col] = std::max(dp[cur_row][cur_col], dfs(board, dp, next_row, next_col, N) + 1);
    }

    return dp[cur_row][cur_col];
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> board(n, std::vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> board[i][j];
        }
    }

    int answer = 0;
    std::vector<std::vector<int>> dp(n, std::vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer = std::max(answer, dfs(board, dp, i, j, n));
        }
    }

    std::cout << answer;

    return 0;
}