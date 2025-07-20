// https://www.codetree.ai/ko/frequent-problems/samsung-sw/problems/two-candies/description
// 2개의 사탕
// Lv. 15

/*
10^4면 4차원 벡터도 충분
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct State {
    int red_row;
    int red_col;
    int blue_row;
    int blue_col;
    int time;
};

struct BallState {
    int row;
    int col;
    int dist;
    bool hole_hit;
};

std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};

BallState MoveBall(const std::vector<std::vector<char>>& board, const int& row, const int& col, const int& dir) {
    int N = board.size();
    int M = board[0].size();
    int dist = 1;
    bool hole_hit = false;

    while (true) {
        int nr = row + dr[dir] * dist;
        int nc = col + dc[dir] * dist;
        if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
            dist--;
            break;
        }

        if (board[nr][nc] == '#') {
            dist--;
            break;
        }
        if (board[nr][nc] == 'O') {
            hole_hit = true;
            break;
        }

        dist++;
    }

    return {row + dr[dir] * dist, col + dc[dir] * dist, dist, hole_hit};
}

int bfs(const std::vector<std::vector<char>>& board, const std::pair<int, int>& red, const std::pair<int, int>& blue) {
    int N = board.size();
    int M = board[0].size();
    std::vector<std::vector<std::vector<std::vector<bool>>>> visited(N, std::vector<std::vector<std::vector<bool>>> (M, std::vector<std::vector<bool>> (N, std::vector<bool> (M))));

    std::queue<State> q;
    q.push({red.first, red.second, blue.first, blue.second, 1});
    visited[red.first][red.second][blue.first][blue.second] = true;

    while (!q.empty()) {
        auto [red_row, red_col, blue_row, blue_col, time] = q.front();
        q.pop();

        if (time > 10) {
            return -1;
        }

        for (int i = 0; i < 4; i++) {
            auto next_red = MoveBall(board, red_row, red_col, i);
            auto next_blue = MoveBall(board, blue_row, blue_col, i);

            if (next_blue.hole_hit) {
                continue;
            }

            if (next_red.hole_hit) {
                return time;
            }

            // 이동 후 겹치게 되면 이동 거리가 더 긴 쪽은 나중에 그 자리에 온 것이므로 한 칸 물리기
            if (next_red.row == next_blue.row && next_red.col == next_blue.col) {
                if (next_red.dist < next_blue.dist) {
                    next_blue.row -= dr[i];
                    next_blue.col -= dc[i];
                }
                else {
                    next_red.row -= dr[i];
                    next_red.col -= dc[i];
                }
            }

            if (!visited[next_red.row][next_red.col][next_blue.row][next_blue.col]) {
                q.push({next_red.row, next_red.col, next_blue.row, next_blue.col, time + 1});
                visited[next_red.row][next_red.col][next_blue.row][next_blue.col] = true;
            }
        }
    }

    return -1;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<char>> board(N, std::vector<char> (M));
    std::string line;
    int red_row, red_col, blue_row, blue_col;
    for (int i = 0; i < N; i++) {
        std::cin >> line;
        for (int j = 0; j < M; j++) {
            board[i][j] = line[j];

            if (board[i][j] == 'R') {
                red_row = i;
                red_col = j;
            }
            else if (board[i][j] == 'B') {
                blue_row = i;
                blue_col = j;
            }
        }
    }

    int answer = bfs(board, {red_row, red_col}, {blue_row, blue_col});
    std::cout << answer;
    
    return 0;
}
