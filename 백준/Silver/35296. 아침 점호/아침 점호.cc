/*
세로 인접만 가능. N = 1일 때 예외
*/

#include <iostream>
#include <vector>
#include <string>

struct Op {
    int cnt, a, b;
};

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<char>> board(N + 1, std::vector<char> (M + 1));
    std::string line;
    for (int r = 1; r <= N; r++) {
        std::cin >> line;
        for (int c = 1; c <= M; c++) {
            board[r][c] = line[c - 1];
        }
    }

    std::vector<Op> ops;

    if (N == 1) {
        // 가로 인접 가능
        for (int c = 1; c <= M; c++) {
            if (board[1][c] != 'X') {
                continue;
            }

            if (c + 1 <= M && board[1][c + 1] == 'X') {
                ops.emplace_back(Op {2, c, c + 1});
                c++;
            }
            else {
                ops.emplace_back(Op {1, c, 0});
            }
        }
    }
    else {
        for (int c = 1; c <= M; c++) {
            for (int r = 1; r <= N; r++) {
                if (board[r][c] != 'X') {
                    continue;
                }

                if (r + 1 <= N && board[r + 1][c] == 'X') {
                    ops.emplace_back(Op {2, r + N * (c - 1), r + 1 + N * (c - 1)});
                    r++;
                }
                else {
                    ops.emplace_back(Op {1, r + N * (c - 1), 0});
                }
            }
        }
    }
    
    std::cout << ops.size() << "\n";
    for (auto& [cnt, a, b] : ops) {
        if (cnt == 1) {
            std::cout << cnt << " " << a << "\n";
        }
        else {
            std::cout << cnt << " " << a << " " << b << "\n";
        }
    }

    return 0;
}