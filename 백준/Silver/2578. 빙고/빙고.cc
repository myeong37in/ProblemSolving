#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::pair<int, int>> pos(26);
    std::vector<std::vector<int>> board(5, std::vector<int> (5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> board[i][j];
            pos[board[i][j]] = {i, j};
        }
    }

    int n;
    for (int k = 1; k <= 25; k++) {
        std::cin >> n;
        auto [r, c] = pos[n];
        board[r][c] = 0;

        int bingo_cnt = 0;
        for (int i = 0; i < 5; i++) { // 가로 빙고
            int sum = 0;
            for (int j = 0; j < 5; j++) {
                sum += board[i][j];
            }

            if (sum == 0) {
                bingo_cnt++;
            }
        }

        for (int j = 0; j < 5; j++) { // 세로 빙고
            int sum = 0;
            for (int i = 0; i < 5; i++) {
                sum += board[i][j];
            }

            if (sum == 0) {
                bingo_cnt++;
            }
        }

        if (board[0][0] + board[1][1] + board[2][2] + board[3][3] + board[4][4] == 0) {
            bingo_cnt++;
        }
        if (board[4][0] + board[3][1] + board[2][2] + board[1][3] + board[0][4] == 0) {
            bingo_cnt++;
        }

        if (bingo_cnt >= 3) {
            std::cout << k;
            return 0;
        }

    }

    return 0;
}