/*
제거해 보면 될 듯

벽 10,000개, BFS
*/

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> visited;

std::vector<int> dr = {0, -1, 0, 1};
std::vector<int> dc = {-1, 0, 1, 0};

int N, M;

int visit_cnt = 1;
int GetArea(int sr, int sc, std::vector<std::vector<int>>& board) {
    std::queue<std::pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = visit_cnt;
    int ans = 0;

    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();

        ans++;

        for (int dir = 0; dir < 4; dir++) {
            int nr = cr + dr[dir];
            int nc = cc + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] == visit_cnt) {
                continue;
            }

            if (board[cr][cc] & (1 << dir)) { // 그 방향에 벽 있음
                continue;
            }

            q.push({nr, nc});
            visited[nr][nc] = visit_cnt;
        }
    }

    return ans;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> M >> N;

    std::vector<std::vector<int>> board(N, std::vector<int> (M));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            std::cin >> board[r][c];
        }
    }

    int room_cnt = 0;
    int max_area = 0;

    visited.assign(N, std::vector<int> (M));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (visited[r][c] != visit_cnt) {
                room_cnt++;
                max_area = std::max(max_area, GetArea(r, c, board));
            }
        }
    }

    int max_area_two = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            for (int dir = 0; dir < 4; dir++) {
                if (board[r][c] & (1 << dir)) { // 벽 있음
                    board[r][c] ^= (1 << dir); // 제거
                    max_area_two = std::max(max_area_two, GetArea(r, c, board));
                    board[r][c] ^= (1 << dir); // 복원
                    
                    visit_cnt++;
                }
            }
        }
    }

    std::cout << room_cnt << "\n" << max_area << "\n" << max_area_two;

    return 0;
}