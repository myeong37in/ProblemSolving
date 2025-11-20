/*
방향을 바꿔
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    // std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int C, R, K;
    std::cin >> C >> R >> K;

    if (C * R < K) {
        std::cout << 0;
        return 0;
    }

    std::vector<std::vector<int>> board(R, std::vector<int> (C));

    std::vector<int> dr = {-1, 0, 1, 0};
    std::vector<int> dc = {0, 1, 0, -1};
    int dir = 0;
    int id = 1;
    int sr = R;
    int sc = 0;
    while (id <= C * R) {
        int nr = sr + dr[dir];
        int nc = sc + dc[dir];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C || board[nr][nc] != 0) {
            dir = (dir + 1) % 4;

            nr = sr + dr[dir];
            nc = sc + dc[dir];
        }

        board[nr][nc] = id;

        if (id == K) {
            std::cout << nc + 1 << " " << R - nr;
            
            return 0;
        }

        id++;
        sr = nr;
        sc = nc;
    }

    return 0;
}