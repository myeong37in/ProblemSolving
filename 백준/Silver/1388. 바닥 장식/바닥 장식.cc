/*
ㅇㅇ..
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
    std::vector<std::vector<bool>> visited(N, std::vector<bool> (M));

    std::string line;
    for (int r = 0; r < N; r++) {
        std::cin >> line;
        for (int c = 0; c < M; c++) {
            board[r][c] = line[c];
        }
    }

    int cnt = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (!visited[r][c]) {
                if (board[r][c] == '-') {
                    int nc = c;
                    while (nc < M && board[r][nc] == '-') {
                        visited[r][nc] = true;
                        nc++;
                    }
                }
                else {
                    int nr = r;
                    while (nr < N && board[nr][c] == '|') {
                        visited[nr][c] = true;
                        nr++;
                    }
                }

                cnt++;
            }
        }
    }
    
    std::cout << cnt;

    return 0;
}