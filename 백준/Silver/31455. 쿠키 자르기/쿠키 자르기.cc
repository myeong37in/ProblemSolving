/*
재gui
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int>> board;

// 인자로 받은 격자 범위에서 문제의 답 반환
static int Recursion(int sr, int sc, int er, int ec) {
    if (sr == er && sc == ec) {
        return board[sr][sc];
    }

    int mr = sr + (er - sr) / 2;
    int mc = sc + (ec - sc) / 2;

    int sum = 0;
    for (int r = sr; r <= er; r++) {
        for (int c = sc; c <= ec; c++) {
            sum += board[r][c];
        }
    }

    int quadrant = sum % 4;
    if (quadrant == 0) {
        // 2, 3, 4사분면
        return Recursion(sr, mc + 1, mr, ec) + Recursion(mr + 1, sc, er, mc) + Recursion(mr + 1, mc + 1, er, ec);
    }
    else if (quadrant == 1) {
        // 1, 3, 4사분면
        return Recursion(sr, sc, mr, mc) + Recursion(mr + 1, sc, er, mc) + Recursion(mr + 1, mc + 1, er, ec);
    }
    else if (quadrant == 2) {
        // 1, 2, 4사분면
        return Recursion(sr, sc, mr, mc) + Recursion(sr, mc + 1, mr, ec) + Recursion(mr + 1, mc + 1, er, ec);
    }
    else {
        // 1, 2, 3사분면
        return Recursion(sr, sc, mr, mc) + Recursion(sr, mc + 1, mr, ec) + Recursion(mr + 1, sc, er, mc);
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;

    int N;
    std::string line;
    while (T--) {
        std::cin >> N;
        board.assign(N, std::vector<int> (N, 0));
        for (int r = 0; r < N; r++) {
            std::cin >> line;
            for (int c = 0; c < N; c++) {
                board[r][c] = line[c] - '0';
            }
        }

        int ans = Recursion(0, 0, N - 1, N - 1);
        std::cout << ans << "\n";
    }
    
    return 0;
}