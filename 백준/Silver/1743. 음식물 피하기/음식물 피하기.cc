/*
연결 요소
*/

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> board;
std::vector<std::vector<bool>> visited;

std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};

int bfs(int sr, int sc, int N, int M) {
    std::queue<std::pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    int cnt = 0;

    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();

        cnt++;

        for (int dir = 0; dir < 4; dir++) {
            int nr = cr + dr[dir];
            int nc = cc + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                continue;
            }

            if (board[nr][nc] == 0 || visited[nr][nc]) {
                continue;
            }

            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }

    return cnt;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, K;
    std::cin >> N >> M >> K;

    board.assign(N, std::vector<int> (M));
    int r, c;
    for (int i = 0; i < K; i++) {
        std::cin >> r >> c;
        board[r - 1][c - 1] = 1;
    }

    visited.assign(N, std::vector<bool> (M));
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && board[i][j]) {
                ans = std::max(ans, bfs(i, j, N, M));
            }
        }
    }

    std::cout << ans;

    return 0;
}