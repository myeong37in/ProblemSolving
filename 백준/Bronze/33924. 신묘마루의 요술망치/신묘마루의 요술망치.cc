/*
뇌 빼고 풀기
*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int r, c;
    std::cin >> r >> c;

    std::vector<std::vector<int>> board(4, std::vector<int> (2));
    board[r - 1][c - 1] = 1;

    int K;
    std::string seq;
    std::cin >> K >> seq;
    
    for (const char& ch : seq) {
        if (ch == 'A') {
            std::vector<std::vector<int>> temp(2, std::vector<int> (2));
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    temp[i][j] = board[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    board[i][j] = board[i + 2][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    board[i + 2][j] = temp[i][j];
                }
            }
        }
        else if (ch == 'B') {
            std::swap(board[0][0], board[1][1]);
            std::swap(board[1][0], board[0][1]);
            std::swap(board[2][0], board[3][1]);
            std::swap(board[3][0], board[2][1]);
        }
        else if (ch == 'C') {
            std::swap(board[0][0], board[3][1]);
            std::swap(board[0][1], board[3][0]);
            std::swap(board[1][0], board[2][1]);
            std::swap(board[2][0], board[1][1]);
        }
        else {
            int temp = board[0][0];
            board[0][0] = board[1][0];
            board[1][0] = board[2][0];
            board[2][0] = board[3][0];
            board[3][0] = board[3][1];
            board[3][1] = board[2][1];
            board[2][1] = board[1][1];
            board[1][1] = board[0][1];
            board[0][1] = temp;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            if (board[i][j]) {
                std::cout << i + 1 << " " << j + 1;
            }
        }
    }

    return 0;
}
