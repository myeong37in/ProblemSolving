/*
재귀
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> board;

static inline int GetSecondMin(int a, int b, int c, int d) {
    std::vector<int> vec = {a, b, c, d};
    std::sort(vec.begin(), vec.end());
    return vec[1];
}

static int Recursion(int sr, int er, int sc, int ec) {
    if (er - sr == 1 || ec - sc == 1) {
        return GetSecondMin(board[sr][sc], board[sr + 1][sc], board[sr][sc + 1], board[sr + 1][sc + 1]);
    }

    int mr = (sr + er) / 2;
    int mc = (sc + ec) / 2;
    return GetSecondMin(Recursion(sr, mr, sc, mc), Recursion(sr, mr, mc + 1, ec), Recursion(mr + 1, er, sc, mc), Recursion(mr + 1, er, mc + 1, ec));
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    board.assign(N, std::vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> board[i][j];
        }
    }

    if (N == 1) { // Aㅏ...
        std::cout << board[0][0];
        return 0;
    }

    std::cout << Recursion(0, N - 1, 0, N - 1);

    return 0;
}