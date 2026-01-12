#include <iostream>
#include <vector>
#include <string>

struct Coord {
    int r, c;
};

int R, C;

std::vector<std::vector<char>> board;

std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};

static Coord Move(int pr, int pc, char d, std::vector<Coord>& targets) {
    int dir = 0;
    if (d == 'U') {
        dir = 0;
    }
    else if (d == 'D') {
        dir = 1;
    }
    else if (d == 'L') {
        dir = 2;
    }
    else {
        dir = 3;
    }

    int nr = pr + dr[dir];
    int nc = pc + dc[dir];

    if (board[nr][nc] == '+' || board[nr][nc] == '.') {
        if (board[nr][nc] == '+') { // 목표 지점으로 이동은 'W'
            board[nr][nc] = 'W';
        }
        else {
            board[nr][nc] = 'w';
        }
        
        // 이전에 서있었던 곳이 목표 지점이면 '+'로. 아니면 '.'로
        bool is_prev_target = false;
        for (auto& [tr, tc] : targets) {
            if (tr == pr && tc == pc) {
                board[pr][pc] = '+';
                is_prev_target = true;
                break;
            }
        }

        if (!is_prev_target) {
            board[pr][pc] = '.';
        }

        return {nr, nc}; // 이동
    }
    else if (board[nr][nc] == '#') {
        return {pr, pc}; // 이동 x
    }
    else { // 이동하려고 하는 방향에 박스
        int nnr = nr + dr[dir];
        int nnc = nc + dc[dir];

        // 벽이나 박스가 또 있음
        if (board[nnr][nnc] == '#' || board[nnr][nnc] == 'b' || board[nnr][nnc] == 'B') {
            return {pr, pc}; // 이동 x
        }

        // 박스 밀기
        if (board[nnr][nnc] == '+') {
            board[nnr][nnc] = 'B';
        }
        else if (board[nnr][nnc] == '.') {
            board[nnr][nnc] = 'b';
        }

        // 다음 칸(원래 박스가 있었던 칸)과 이전 칸(원래 캐릭터가 있었던 칸) 수정
        bool is_prev_target = false;
        bool is_next_target = false;
        for (auto& [tr, tc] : targets) {
            if (nr == tr && nc == tc) {
                board[nr][nc] = 'W';
                is_next_target = true;
            }
            else if (pr == tr && pc == tc) {
                board[pr][pc] = '+';
                is_prev_target = true;
            }
        }

        if (!is_next_target) {
            board[nr][nc] = 'w';
        }

        if (!is_prev_target) {
            board[pr][pc] = '.';
        }

        return {nr, nc};
    }
}

static bool CheckCompleted(std::vector<Coord>& targets) {
    for (auto& [r, c] : targets) {
        if (board[r][c] == '+' || board[r][c] == 'W') {
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    while (std::cin >> R >> C) {
        if (R == 0) {
            break;
        }

        board.assign(R, std::vector<char> (C));
        std::vector<Coord> targets; // 목표점 위치
        int pr, pc; // 캐릭터 위치
        std::string line;
        for (int r = 0; r < R; r++) {
            std::cin >> line;
            for (int c = 0; c < C; c++) {
                board[r][c] = line[c];
                if (board[r][c] == '+' || board[r][c] == 'B') {
                    targets.emplace_back(Coord {r, c});
                }
                else if (board[r][c] == 'w') {
                    pr = r;
                    pc = c;
                }
                else if (board[r][c] == 'W') {
                    pr = r;
                    pc = c;
                    targets.emplace_back(Coord {r, c});
                }
            }
        }

        std::string moves;
        std::cin >> moves;

        bool complete = false;
        for (char ch : moves) {
            Coord nxt = Move(pr, pc, ch, targets);
            pr = nxt.r;
            pc = nxt.c;
            if (CheckCompleted(targets)) {
                complete = true;
                break;
            }
        }

        std::cout << "Game " << tc << ": " << (complete ? "complete\n" : "incomplete\n");
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                std::cout << board[r][c];
            }
            std::cout << "\n";
        }

        tc++;
    }
    
    return 0;
}