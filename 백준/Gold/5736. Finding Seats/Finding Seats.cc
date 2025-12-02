/*
누적 합, 슬라이딩 윈도우로 찾기
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C, K;

    constexpr int INF = 2e9;

    while (true) {
        std::cin >> R >> C >> K;
        if (R == 0) {
            break;
        }

        std::vector<std::vector<char>> board(R, std::vector<char> (C));
        std::string line;
        for (int r = 0; r < R; r++) {
            std::cin >> line;
            for (int c = 0; c < C; c++) {
                board[r][c] = line[c];
            }
        }

        int ans = INF;
        for (int top = 0; top < R; top++) {
            std::vector<int> cols(C);
            for (int bottom = top; bottom < R; bottom++) {
                int h = bottom - top + 1;

                for (int c = 0; c < C; c++) {
                    if (board[bottom][c] == '.') {
                        cols[c]++;
                    }
                }

                int sum = 0;
                int left = 0;
                int best_width = INF;

                for (int right = 0; right < C; right++) {
                    sum += cols[right];

                    while (left <= right && sum - cols[left] >= K) {
                        sum -= cols[left];
                        left++;
                    }

                    if (sum >= K) {
                        best_width = std::min(best_width, right - left + 1);
                    }
                }

                if (best_width != INF) 
                ans = std::min(ans, h * best_width);
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}