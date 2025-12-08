#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::vector<char>> board(N, std::vector<char> (N));
    std::string line;
    for (int r = 0; r < N; r++) {
        std::cin >> line;
        for (int c = 0; c < N; c++) {
            board[r][c] = line[c];
        }
    }

    int horizontal_cnt = 0, vertical_cnt = 0;
    for (int r = 0; r < N; r++) {
        int valid_col = 0;
        for (int c = 0; c < N; c++) {
            if (board[r][c] == 'X') {
                if (c - valid_col >= 2) {
                    horizontal_cnt++;
                }
                valid_col = c + 1;
            }
        }

        if (N - valid_col >= 2) {
            horizontal_cnt++;
        }
    }

    for (int c = 0; c < N; c++) {
        int valid_row = 0;
        for (int r = 0; r < N; r++) {
            if (board[r][c] == 'X') {
                if (r - valid_row >= 2) {
                    vertical_cnt++;
                }
                valid_row = r + 1;
            }
        }

        if (N - valid_row >= 2) {
            vertical_cnt++;
        }
    }

    std::cout << horizontal_cnt << " " << vertical_cnt;

    return 0;
}