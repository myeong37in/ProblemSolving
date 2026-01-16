/*
한 번만 칠해야 한다는 조건이 없으므로 모든 도장을 한 번씩 찍어보면 될 듯

O(PRCWS)
*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    // std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int W, S;
    std::cin >> W >> S;

    std::string line;
    std::vector<std::vector<char>> board(W, std::vector<char> (S));
    for (int r = 0; r < W; r++) {
        std::cin >> line;
        for (int c = 0; c < S; c++) {
            board[r][c] = line[c];
        }
    }

    std::vector<std::vector<bool>> complete(W, std::vector<bool> (S));

    int P, R, C;
    std::cin >> P;
    for (int i = 0; i < P; i++) {
        std::cin >> R >> C;
        std::vector<std::vector<char>> stamp(R, std::vector<char> (C));
        for (int r = 0; r < R; r++) {
            std::cin >> line;
            for (int c = 0; c < C; c++) {
                stamp[r][c] = line[c];
            }
        }

        // 위에서부터 빈 행 찾기
        bool empty = true;
        int filled_r_start = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (stamp[r][c] == '#') {
                    empty = false;
                    break;
                }
            }

            if (!empty) {
                break;
            }

            filled_r_start++;
        }

        // 왼쪽부터 빈 열 찾기
        empty = true;
        int filled_c_start = 0;
        for (int c = 0; c < C; c++) {
            for (int r = 0; r < R; r++) {
                if (stamp[r][c] == '#') {
                    empty = false;
                    break;
                }
            }

            if (!empty) {
                break;
            }

            filled_c_start++;
        }

        // 아래에서부터 빈 행 찾기
        empty = true;
        int filled_r_end = R - 1;
        for (int r = R - 1; r >= 0; r--) {
            for (int c = 0; c < C; c++) {
                if (stamp[r][c] == '#') {
                    empty = false;
                    break;
                }
            }

            if (!empty) {
                break;
            }

            filled_r_end--;
        }

        // 오른쪽부터 빈 열 찾기
        empty = true;
        int filled_c_end = C - 1;
        for (int c = C - 1; c >= 0; c--) {
            for (int r = 0; r < R; r++) {
                if (stamp[r][c] == '#') {
                    empty = false;
                    break;
                }
            }

            if (!empty) {
                break;
            }

            filled_c_end--;
        }

        if (filled_r_start == R || filled_c_start == C) { // 완전히 빈 도장
            continue;
        }

        R = filled_r_end - filled_r_start + 1;
        C = filled_c_end - filled_c_start + 1;
        std::vector<std::vector<char>> real_stamp(R, std::vector<char> (C));
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                real_stamp[r][c] = stamp[r + filled_r_start][c + filled_c_start];
            }
        }

        for (int sr = 0; sr < W - R + 1; sr++) {
            for (int sc = 0; sc < S - C + 1; sc++) {
                bool okay = true;
                for (int r = sr; r < sr + R; r++) {
                    for (int c = sc; c < sc + C; c++) {
                        if (real_stamp[r - sr][c - sc] == '#' && board[r][c] == '.') { // 못 찍음
                            okay = false;
                            break;
                        }
                    }

                    if (!okay) {
                        break;
                    }
                }

                if (!okay) {
                    continue;
                }

                for (int r = sr; r < sr + R; r++) {
                    for (int c = sc; c < sc + C; c++) {
                        if (real_stamp[r - sr][c - sc] == '#') {
                            complete[r][c] = true;
                        }
                    }
                }
            }
        }
    }

    for (int r = 0; r < W; r++) {
        for (int c = 0; c < S; c++) {
            if (complete[r][c] == false && board[r][c] == '#') {
                std::cout << "NIE";
                return 0;
            }
        }
    }

    std::cout << "TAK";
    
    return 0;
}