/*
정직하게 가자고
*/

#include <iostream>
#include <vector>

static inline std::vector<std::vector<int>> RotateClockwise(const std::vector<std::vector<int>>& sticker) {
    int R = sticker.size();
    int C = sticker[0].size();
    std::vector<std::vector<int>> res(C, std::vector<int> (R));
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            res[c][r] = sticker[R - r - 1][c];
        }
    }

    return res;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::vector<std::vector<int>>> stickers(K);
    int R, C;
    for (int i = 0; i < K; i++) {
        std::cin >> R >> C;
        stickers[i].assign(R, std::vector<int> (C));
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                std::cin >> stickers[i][r][c];
            }
        }
    }

    std::vector<std::vector<int>> board(N, std::vector<int> (M));
    for (int idx = 0; idx < K; idx++) {
        for (int dir = 0; dir < 4; dir++) {
            // (sr, sc)를 좌상단으로 하여 넣어보기
            bool found = false;
            int sr, sc;
            int R = stickers[idx].size();
            int C = stickers[idx][0].size();

            for (sr = 0; sr < N; sr++) {
                for (sc = 0; sc < M; sc++) {
                    if (sr + R > N || sc + C > M) {
                        continue;
                    }

                    bool okay = true;
                    for (int r = sr; r < sr + R; r++) {
                        for (int c = sc; c < sc + C; c++) {
                            if (stickers[idx][r - sr][c - sc] && board[r][c]) {
                                okay = false;
                                break;
                            }
                        }

                        if (!okay) {
                            break;
                        }
                    }

                    if (okay) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    break;
                }
            }

            if (found) {
                for (int r = sr; r < sr + R; r++) {
                    for (int c = sc; c < sc + C; c++) {
                        // 스티커의 0인 칸이 덮어쓰지 않도록
                        board[r][c] = std::max(board[r][c], stickers[idx][r - sr][c - sc]);
                    }
                }
                break;
            }
            else {
                stickers[idx] = RotateClockwise(stickers[idx]);
            }
        }
    }

    int ans = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            ans += board[r][c];
        }
    }

    std::cout << ans;

    return 0;
}