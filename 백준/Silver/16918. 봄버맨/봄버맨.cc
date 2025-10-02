/*
sim

짝수 턴에 설치, 홀수 턴에 폭발

O(NRC)
*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C, N;
    std::cin >> R >> C >> N;

    std::vector<std::vector<int>> board(R, std::vector<int> (C));
    std::string line;
    for (int i = 0; i < R; i++) {
        std::cin >> line;
        for (int j = 0; j < C; j++) {
            if (line[j] == 'O') {
                board[i][j] = 3;
            }
        }
    }

    std::vector<int> dr = {-1, 1, 0, 0};
    std::vector<int> dc = {0, 0, -1, 1};

    int time = 1;
    while (time < N) {
        time++;

        if (time & 1) {
            std::vector<std::pair<int, int>> boom;
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    if (board[r][c] == time) {
                        boom.emplace_back(r, c);
                    }
                }
            }

            for (const auto& p : boom) {
                board[p.first][p.second] = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nr = p.first + dr[dir];
                    int nc = p.second + dc[dir];

                    if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                        continue;
                    }

                    board[nr][nc] = 0;
                }
            }
        }
        else {
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    if (board[r][c] == 0) {
                        board[r][c] = time + 3;
                    }
                }
            }
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c]) {
                std::cout << 'O';
            }
            else {
                std::cout << '.';
            }
        }
        std::cout << "\n";
    }

    return 0;
}