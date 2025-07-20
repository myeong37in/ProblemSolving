// https://www.acmicpc.net/problem/14890
// 경사로
// 골드 3

/*
총 2N개의 행, 열에 대해 검사

1) 값이 모두 같으면 카운트
2) 인접한 칸의 높이 차이가 2 이상이면 컷
3) 인접한 칸의 높이 차이가 1이면서
    3-1) 다음 칸이 더 높았으면 이전 L개의 칸의 높이가 같은지 확인. 아니면 컷
    3-2) 이전 칸의 높이가 더 높았으면 다음 L개의 칸의 높이가 같은지 확인. 아니면 컷
4) 컷되지 않았으면 경사를 놓았음을 표시하고 다음 인덱스로
5) 모든 인덱스에서 컷되지 않으면 카운트
*/

#include <iostream>
#include <vector>

bool CheckValidRow(std::vector<std::vector<int>>& board, const int& N, const int& L, const int& row_idx) {
    int start = board[row_idx][0];
    bool all_same = true;
    for (int i = 1; i < N; i++) {
        if (board[row_idx][i] != start) {
            all_same = false;
            break;
        }
    }

    if (all_same) {
        // std::cout << row_idx << " ";
        return true;
    }

    std::vector<bool> can_place_slope(N, true);
    for (int i = 0; i < N - 1; i++) {
        int cur = board[row_idx][i];
        int next = board[row_idx][i + 1];

        if (cur == next) {
            continue;
        }

        if (cur > next) { // 현재 칸이 다음 칸보다 높은 경우
            if (cur > next + 1) { // 두 칸 이상 높은 경우
                return false;
            }

            if (N - 1 - i < L) { // 다음으로 L개의 칸을 놓을 수 없는 경우
                return false;
            }

            for (int j = i + 1; j < i + L + 1; j++) { // L개의 칸의 높이가 모두 같지 않은 경우, 혹은 이미 다른 경사로를 놓은 경우
                if (board[row_idx][j] != next || !can_place_slope[j]) {
                    return false;
                }
            }

            for (int j = i + 1; j < i + L + 1; j++) { // 모두 통과했으면 경사로를 이어서 이 칸에 다시 경사로를 놓지 못하게 한다.
                can_place_slope[j] = false;
            }
        }
        else if (cur < next) { // 다음 칸이 현재 칸보다 높은 경우
            if (cur + 1 < next) { // 두 칸 이상 높은 경우
                return false;
            }

            if (i + 1 < L) { // 이전으로 L개의 칸을 놓을 수 없는 경우
                return false;
            }

            for (int j = i - L + 1; j <= i; j++) { // L개의 칸의 높이가 모두 같지 않은 경우, 혹은 이미 다른 경사로를 놓은 경우
                if (board[row_idx][j] != cur || !can_place_slope[j]) {
                    return false;
                }
            }

            for (int j = i - L + 1; j <= i; j++) { // 모두 통과했으면 경사로를 이어서 이 칸에 다시 경사로를 놓지 못하게 한다.
                can_place_slope[j] = false;
            }
        }
    }

    // std::cout << row_idx << " ";
    return true;
}

bool CheckValidCol(std::vector<std::vector<int>>& board, const int& N, const int& L, const int& col_idx) {
    int start = board[0][col_idx];
    bool all_same = true;
    for (int i = 1; i < N; i++) {
        if (board[i][col_idx] != start) {
            all_same = false;
            break;
        }
    }

    if (all_same) {
        // std::cout << col_idx << " ";
        return true;
    }

    std::vector<bool> can_place_slope(N, true);
    for (int i = 0; i < N - 1; i++) {
        int cur = board[i][col_idx];
        int next = board[i + 1][col_idx];

        if (cur == next) {
            continue;
        }

        if (cur > next) { // 현재 칸이 다음 칸보다 높은 경우
            if (cur > next + 1) { // 두 칸 이상 높은 경우
                return false;
            }

            if (N - 1 - i < L) { // 다음으로 L개의 칸을 놓을 수 없는 경우
                return false;
            }

            for (int j = i + 1; j < i + L + 1; j++) { // L개의 칸의 높이가 모두 같지 않은 경우, 혹은 이미 다른 경사로를 놓은 경우
                if (board[j][col_idx] != next || !can_place_slope[j]) {
                    return false;
                }
            }

            for (int j = i + 1; j < i + L + 1; j++) { // 모두 통과했으면 경사로를 이어서 이 칸에 다시 경사로를 놓지 못하게 한다.
                can_place_slope[j] = false;
            }
        }
        else if (cur < next) { // 다음 칸이 현재 칸보다 높은 경우
            if (cur + 1 < next) { // 두 칸 이상 높은 경우
                return false;
            }

            if (i + 1 < L) { // 이전으로 L개의 칸을 놓을 수 없는 경우
                return false;
            }

            for (int j = i - L + 1; j <= i; j++) { // L개의 칸의 높이가 모두 같지 않은 경우, 혹은 이미 다른 경사로를 놓은 경우
                if (board[j][col_idx] != cur || !can_place_slope[j]) {
                    return false;
                }
            }

            for (int j = i - L + 1; j <= i; j++) { // 모두 통과했으면 경사로를 이어서 이 칸에 다시 경사로를 놓지 못하게 한다.
                can_place_slope[j] = false;
            }
        }
    }

    // std::cout << col_idx << " ";
    return true;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, L;
    std::cin >> N >> L;

    std::vector<std::vector<int>> board(N, std::vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> board[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (CheckValidRow(board, N, L, i)) {
            count++;
        }
        if (CheckValidCol(board, N, L, i)) {
            count++;
        }
    }

    std::cout << count;

    return 0;
}