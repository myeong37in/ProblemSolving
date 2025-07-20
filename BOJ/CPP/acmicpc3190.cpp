// https://www.acmicpc.net/problem/3190
// 뱀
// 골드 4

#include <iostream>
#include <vector>
#include <deque>

// 0: 상, 1: 하, 2: 좌, 3: 우
std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};

// 현재 이동 방향과 회전 방향을 받아 다음 이동 방향을 반환하는 함수
int DetermineDir(const int& cur_dir, const char& rotation) {
    if (cur_dir == 0) {
        if (rotation == 'L') {
            return 2; // 상 -> 좌
        }
        else if (rotation == 'D') {
            return 3; // 상 -> 우
        }
    }
    else if (cur_dir == 1) {
        if (rotation == 'L') {
            return 3; // 하 -> 우
        }
        else if (rotation == 'D') {
            return 2; // 하 -> 좌
        }
    }
    else if (cur_dir == 2) {
        if (rotation == 'L') {
            return 1; // 좌 -> 하
        }
        else if (rotation == 'D') {
            return 0; // 좌 -> 상
        }
    }
    else if (cur_dir == 3) {
        if (rotation == 'L') {
            return 0; // 우 -> 상
        }
        else if (rotation == 'D') {
            return 1; // 우 -> 하
        }
    }

    return -1; // 실행될 일은 없음
}

int Sim(std::vector<std::vector<int>>& board, const std::vector<std::pair<int, char>>& action) {
    int cur_dir = 3; // 초기 방향: 우측
    int time = 0;
    board[0][0] = 1; // (0, 0)에서 시작

    int cur_row = 0;
    int cur_col = 0;
    int N = board.size();
    int upcoming_action = 0; // 다음 나올 action에서의 인덱스
    std::deque<std::pair<int, int>> trace; // 사과가 없을 때 꼬리를 삭제하기 위해 머리가 지나간 위치를 저장하는 deque. 삭제 연산을 한다면 vector는 O(N), deque은 O(1)
    trace.push_back({0, 0});
    while (true) {
        int next_row = cur_row + dr[cur_dir];
        int next_col = cur_col + dc[cur_dir];
        time++;

        // 뱀에 부딪힐 때도 게임 종료
        if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= N || board[next_row][next_col] == 1) {
            return time;
        }

        trace.push_back({next_row, next_col});
        if (board[next_row][next_col] != 2) { // 해당 칸에 사과가 없으면 꼬리 줄이기
            auto [tail_row, tail_col] = trace.front();
            board[tail_row][tail_col] = 0;
            trace.pop_front();
        }
        board[next_row][next_col] = 1;

        if (upcoming_action != action.size() && time == action[upcoming_action].first) {
            char rotation = action[upcoming_action].second;
            cur_dir = DetermineDir(cur_dir, rotation);
            upcoming_action++;
        }

        cur_row = next_row;
        cur_col = next_col;
    }

    return time;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> board(N, std::vector<int> (N)); // 값이 0: 빈칸, 1: 뱀, 2: 사과

    int K;
    std::cin >> K;
    int r, c;
    for (int i = 0; i < K; i++) {
        std::cin >> r >> c;
        board[r - 1][c - 1] = 2; // 0-indexing
    }

    int L;
    std::cin >> L;
    std::vector<std::pair<int, char>> action(L); // 뱀의 방향 전환을 {시간, 방향}으로 저장하는 벡터
    for (int i = 0; i < L; i++) {
        std::cin >> action[i].first >> action[i].second;
    }

    std::cout << Sim(board, action);

    return 0;
}