/*
간단한 구현인 듯
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> board(N + 1, std::vector<int> (N + 1));
    std::vector<std::vector<std::pair<int, int>>> viruses(K + 1);
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            std::cin >> board[r][c];
            if (board[r][c]) {
                viruses[board[r][c]].emplace_back(r, c);
            }
        }
    }

    int S, X, Y;
    std::cin >> S >> X >> Y;

    std::vector<int> dr = {-1, 1, 0, 0};
    std::vector<int> dc = {0, 0, -1, 1};
    for (int t = 0; t < S; t++) {
        for (int virus = 1; virus <= K; virus++) {
            std::vector<std::pair<int, int>> next_pos;
            for (const auto& [r, c] : viruses[virus]) {
                for (int dir = 0; dir < 4; dir++) {
                    int nr = r + dr[dir];
                    int nc = c + dc[dir];

                    if (nr < 1 || nr > N || nc < 1 || nc > N || board[nr][nc] != 0) {
                        continue;
                    }

                    board[nr][nc] = virus;
                    next_pos.emplace_back(nr, nc);
                }
            }

            std::swap(viruses[virus], next_pos);
        }
    }

    std::cout << board[X][Y];

    return 0;
}