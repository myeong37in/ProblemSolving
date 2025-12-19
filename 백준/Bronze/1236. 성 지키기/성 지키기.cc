/*
행방향, 열방향으로 비어 있는 개수 중 큰 값
*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<char>> board(N, std::vector<char> (M));
    std::string line;
    for (int i = 0; i < N; i++) {
        std::cin >> line;
        for (int j = 0; j < M; j++) {
            board[i][j] = line[j];
        }
    }

    int row_cnt = N, col_cnt = M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'X') {
                row_cnt--;
                break;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (board[j][i] == 'X') {
                col_cnt--;
                break;
            }
        }
    }

    std::cout << std::max(row_cnt, col_cnt);

    return 0;
}