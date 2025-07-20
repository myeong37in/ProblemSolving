// https://www.codetree.ai/ko/frequent-problems/samsung-sw/problems/2048-game/description
// 2048 게임
// Lv. 14

/*
4^5 = 1,024

가지치기 중요도 낮음
*/

#include <iostream>
#include <vector>

int global_max = 0;
void CalcMaxVal(const std::vector<std::vector<int>>& board) {
    int N = board.size();

    int cur_max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cur_max = std::max(cur_max, board[i][j]);
        }
    }

    global_max = std::max(global_max, cur_max);
}

std::vector<std::vector<int>> MoveUp(const std::vector<std::vector<int>>& board) {
    int N = board.size();
    std::vector<std::vector<int>> res(N, std::vector<int> (N));

    for (int c = 0; c < N; c++) {
        std::vector<int> row_blocks;
        for (int r = 0; r < N; r++) { // 위 -> 아래로 블록 조사
            if (board[r][c] != 0) {
                row_blocks.emplace_back(board[r][c]);
            }
        }

        if (row_blocks.empty()) {
            continue;
        }
        else if (row_blocks.size() == 1) {
            res[0][c] = row_blocks[0];
            continue;
        }

        int sz = row_blocks.size();
        int idx = 0;
        for (int i = 0; i < sz; i++) {
            if (i == sz - 1) { // 마지막 블록이면 그냥 결정
                res[idx][c] = row_blocks[i];
            }
            else if (row_blocks[i] == row_blocks[i + 1]) { // 블록 두 개가 합쳐지는 경우
                res[idx++][c] = 2 * row_blocks[i];
                i++;
            }
            else { // 합쳐지지 않는 경우 위의 블록만 결정, 아래 블록은 더 아래 블록과 합쳐질 수 있음
                res[idx++][c] = row_blocks[i];
            }
        }
    }

    return res;
}

std::vector<std::vector<int>> MoveDown(const std::vector<std::vector<int>>& board) {
    int N = board.size();
    std::vector<std::vector<int>> res(N, std::vector<int> (N));

    for (int c = 0; c < N; c++) {
        std::vector<int> row_blocks;
        for (int r = N - 1; r >= 0; r--) { // 아래 -> 위로 블록 조사
            if (board[r][c] != 0) {
                row_blocks.emplace_back(board[r][c]);
            }
        }

        if (row_blocks.empty()) {
            continue;
        }
        else if (row_blocks.size() == 1) {
            res[N - 1][c] = row_blocks[0];
            continue;
        }

        int sz = row_blocks.size();
        int idx = N - 1;
        for (int i = 0; i < sz; i++) {
            if (i == sz - 1) {
                res[idx][c] = row_blocks[i];
            }
            else if (row_blocks[i] == row_blocks[i + 1]) {
                res[idx--][c] = 2 * row_blocks[i];
                i++;
            }
            else {
                res[idx--][c] = row_blocks[i];
            }
        }
    }

    return res;
}

std::vector<std::vector<int>> MoveLeft(const std::vector<std::vector<int>>& board) {
    int N = board.size();
    std::vector<std::vector<int>> res(N, std::vector<int> (N));

    for (int r = 0; r < N; r++) {
        std::vector<int> col_blocks;
        for (int c = 0; c < N; c++) { // 왼쪽 -> 오른쪽으로 블록 조사
            if (board[r][c] != 0) {
                col_blocks.emplace_back(board[r][c]);
            }
        }

        if (col_blocks.empty()) {
            continue;
        }
        else if (col_blocks.size() == 1) {
            res[r][0] = col_blocks[0];
            continue;
        }

        int sz = col_blocks.size();
        int idx = 0;
        for (int i = 0; i < sz; i++) {
            if (i == sz - 1) {
                res[r][idx] = col_blocks[i];
            }
            else if (col_blocks[i] == col_blocks[i + 1]) {
                res[r][idx++] = 2 * col_blocks[i];
                i++;
            }
            else {
                res[r][idx++] = col_blocks[i];
            }
        }
    }

    return res;
}

std::vector<std::vector<int>> MoveRight(const std::vector<std::vector<int>>& board) {
    int N = board.size();
    std::vector<std::vector<int>> res(N, std::vector<int> (N));

    for (int r = 0; r < N; r++) {
        std::vector<int> col_blocks;
        for (int c = N - 1; c >= 0; c--) { // 오른쪽 -> 왼쪽으로 블록 조사
            if (board[r][c] != 0) {
                col_blocks.emplace_back(board[r][c]);
            }
        }

        if (col_blocks.empty()) {
            continue;
        }
        else if (col_blocks.size() == 1) {
            res[r][N - 1] = col_blocks[0];
            continue;
        }

        int sz = col_blocks.size();
        int idx = N - 1;
        for (int i = 0; i < sz; i++) {
            if (i == sz - 1) {
                res[r][idx] = col_blocks[i];
            }
            else if (col_blocks[i] == col_blocks[i + 1]) {
                res[r][idx--] = 2 * col_blocks[i];
                i++;
            }
            else {
                res[r][idx--] = col_blocks[i];
            }
        }
    }

    return res;
}

void Sim(const std::vector<std::vector<int>>& board, const int& depth) {
    CalcMaxVal(board);

    if (depth >= 6) {
        return;
    }

    Sim(MoveUp(board), depth + 1);
    Sim(MoveDown(board), depth + 1);
    Sim(MoveLeft(board), depth + 1);
    Sim(MoveRight(board), depth + 1);
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> board(N, std::vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> board[i][j];
        }
    }

    Sim(board, 1);

    std::cout << global_max;

    return 0;
}
