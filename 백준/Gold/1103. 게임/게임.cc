/*
대충 메모이제이션

dp[r][c]: (r, c) 시작 최대 이동 횟수

사이클은 -1
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<char>> board;
std::vector<std::vector<int>> dp;
std::vector<std::vector<bool>> in_cycle;

std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};

bool inf = false;
int N, M;

static int dfs(int cr, int cc) {
    if (dp[cr][cc]) {
        return dp[cr][cc];
    }
    
    in_cycle[cr][cc] = true;

    for (int dir = 0; dir < 4; dir++) {
        int nr = cr + (board[cr][cc] - '0') * dr[dir];
        int nc = cc + (board[cr][cc] -'0') * dc[dir];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == 'H') {
            dp[cr][cc] = std::max(dp[cr][cc], 1);
            continue;
        }

        if (in_cycle[nr][nc]) {
            inf = true;
            return -1;
        }

        dp[cr][cc] = std::max(dp[cr][cc], 1 + dfs(nr, nc));
    }

    in_cycle[cr][cc] = false;
    return dp[cr][cc];
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;

    board.assign(N, std::vector<char> (M));
    std::string line;
    for (int r = 0; r < N; r++) {
        std::cin >> line;
        for (int c = 0; c < M; c++) {
            board[r][c] = line[c];
        }
    }

    in_cycle.assign(N, std::vector<bool> (M));
    dp.assign(N, std::vector<int> (M));
    dfs(0, 0);

    if (inf) {
        std::cout << -1;
        return 0;
    }
    
    std::cout << dp[0][0];
   
    return 0;
}