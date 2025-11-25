/*
간단
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::vector<char>> board(N, std::vector<char> (N));
    std::vector<std::pair<int, int>> empties;
    std::vector<std::pair<int, int>> teachers;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> board[i][j];

            if (board[i][j] == 'X') {
                empties.emplace_back(i, j);
            }
            else if (board[i][j] == 'T') {
                teachers.emplace_back(i, j);
            }
        }
    }

    int sz = empties.size();
    std::vector<int> selected(sz);
    for (int i = sz - 1; i >= sz - 3; i--) {
        selected[i] = 1;
    }

    std::vector<int> dr = {-1, 1, 0, 0};
    std::vector<int> dc = {0, 0, -1, 1};

    bool okay = false;
    do {
        // 장애물 추가
        for (int i = 0; i < sz; i++) {
            if (selected[i]) {
                auto& [r, c] = empties[i];
                board[r][c] = 'O';
            }
        }

        bool found = false; // 학생 발견
        for (const auto& [sr, sc] : teachers) {
            for (int dir = 0; dir < 4; dir++) {
                int dist = 1;
                while (true) {
                    int nr = sr + dr[dir] * dist;
                    int nc = sc + dc[dir] * dist;

                    if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == 'O') {
                        break;
                    }

                    if (board[nr][nc] == 'S') {
                        found = true;
                        break;
                    }
                    dist++;
                }

                if (found) {
                    break;
                }
            }
        }

        if (!found) {
            okay = true;
            break;
        }

        // 되돌리기
        for (int i = 0; i < sz; i++) {
            if (selected[i]) {
                auto& [r, c] = empties[i];
                board[r][c] = 'X';
            }
        }
    } while (std::next_permutation(selected.begin(), selected.end()));

    std::cout << (okay ? "YES" : "NO");

    return 0;
}