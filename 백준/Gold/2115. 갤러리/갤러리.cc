/*
모든 행, 모든 열에서 인접한 두 칸에서 양옆에 X와 .이 있는지 조사하면 200만 개의 칸 조사
*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int M, N;
    std::cin >> M >> N;

    std::vector<std::vector<char>> board(M, std::vector<char> (N));
    std::string line;
    for (int r = 0; r < M; r++) {
        std::cin >> line;
        for (int c = 0; c < N; c++) {
            board[r][c] = line[c];
        }
    }

    int ans = 0;
    // 가로(좌 -> 우 탐색)
    for (int r = 1; r < M; r++) {
        for (int c = 1; c < N - 1; c++) {
            // 위가 벽, 아래가 빈 공간인 경우
            if (board[r - 1][c] == 'X' && board[r - 1][c + 1] == 'X' && board[r][c] == '.' && board[r][c + 1] == '.') {
                c++; // 겹치지 않으므로 다음 열 건너뜀
                ans++;
            }

            // 위가 빈 공간, 아래가 벽인 경우
            if (board[r - 1][c] == '.' && board[r - 1][c + 1] == '.' && board[r][c] == 'X' && board[r][c + 1] == 'X') {
                c++;
                ans++;
            }
        }
    }

    // 세로(상 -> 하 탐색)
    for (int c = 1; c < N; c++) {
        for (int r = 1; r < M - 1; r++) {
            // 왼쪽이 벽, 오른쪽이 빈 공간인 경우
            if (board[r][c - 1] == 'X' && board[r + 1][c - 1] == 'X' && board[r][c] == '.' && board[r + 1][c] == '.') {
                r++; // 겹치지 않으므로 다음 행 건너뜀
                ans++;
            }

            // 왼쪽이 빈 공간, 오른쪽이 벽인 경우
            if (board[r][c - 1] == '.' && board[r + 1][c - 1] == '.' && board[r][c] == 'X' && board[r + 1][c] == 'X') {
                r++;
                ans++;
            }
        }
    }

    std::cout << ans;
    
    return 0;
}