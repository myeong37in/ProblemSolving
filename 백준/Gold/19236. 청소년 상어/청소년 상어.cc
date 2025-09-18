/*
허
*/

#define SHARK 20
#include <iostream>
#include <vector>

struct Fish {
    int num;
    int dir;
};

struct FishMoveHistory {
    int fish1_num, fish1_row, fish1_col, fish1_dir; // 이동의 주체가 된 물고기
    int fish2_num, fish2_row, fish2_col, fish2_dir; // 자리를 바꿔치기당한 물고기
    bool moved; // 이동했으면 true
};

struct SharkMoveHistory {
    int shark_row, shark_col, target_num, target_dir;
};

std::vector<int> dr = {-1, -1, 0, 1, 1, 1, 0, -1};
std::vector<int> dc = {0, -1, -1, -1, 0, 1, 1, 1};

std::vector<std::vector<Fish>> board; // 물고기, 상어 저장
std::vector<std::pair<int, int>> fish_pos(17); // 물고기 위치만 따로 저장

int best_score = 0;
void Sim(const int& shark_row, const int& shark_col, const int& shark_dir, const int& score) {
    std::vector<FishMoveHistory> fish_history;
    
    for (int cur_fish = 1; cur_fish <= 16; cur_fish++) {
        auto [r, c] = fish_pos[cur_fish];

        if (r == -1) { // 먹혀서 없음
            continue;
        }

        int cur_dir = board[r][c].dir;
        int next_dir, next_row, next_col;
        bool can_move = false;
        for (int k = 0; k < 8; k++) {
            next_dir = (cur_dir + k) % 8;
            next_row = r + dr[next_dir];
            next_col = c + dc[next_dir];

            if (next_row < 0 || next_row >= 4 || next_col < 0 || next_col >= 4) {
                continue;
            }
            
            if (board[next_row][next_col].num == SHARK) {
                continue;
            }

            can_move = true;
            break;
        }

        if (!can_move) {
            fish_history.emplace_back(FishMoveHistory {cur_fish, r, c, cur_dir, 0, 0, 0, 0, false});
        }
        else {
            int another_fish = board[next_row][next_col].num;
            int another_dir = board[next_row][next_col].dir;

            fish_history.emplace_back(FishMoveHistory {cur_fish, r, c, cur_dir, another_fish, next_row, next_col, another_dir, true});

            board[r][c] = {another_fish, another_dir};
            if (another_fish > 0) { // 비어있는 경우 제외
                fish_pos[another_fish] = {r, c};
            }

            board[next_row][next_col] = {cur_fish, next_dir};
            fish_pos[cur_fish] = {next_row, next_col};
        }
    }

    bool shark_moved = false;
    for (int speed = 1; ; speed++) { // 상어의 이동 거리
        int next_shark_row = shark_row + speed * dr[shark_dir];
        int next_shark_col = shark_col + speed * dc[shark_dir];

        // 이동 끝
        if (next_shark_row < 0 || next_shark_row >= 4 || next_shark_col < 0 || next_shark_col >= 4) {
            break;
        }

        int target_fish = board[next_shark_row][next_shark_col].num;
        int target_dir = board[next_shark_row][next_shark_col].dir;
        if (target_fish == 0) {
            continue;
        }

        shark_moved = true;

        SharkMoveHistory shark_history = {shark_row, shark_col, target_fish, target_dir};
        
        board[shark_row][shark_col] = {0, 0};
        board[next_shark_row][next_shark_col].num = SHARK;
        fish_pos[target_fish] = {-1, -1};

        Sim(next_shark_row, next_shark_col, target_dir, score + target_fish);

        // 되돌리기
        board[shark_history.shark_row][shark_history.shark_col] = {SHARK, 0};
        board[next_shark_row][next_shark_col]= {shark_history.target_num, shark_history.target_dir};
        fish_pos[shark_history.target_num] = {next_shark_row, next_shark_col};
    }

    // 상어읭 움직임이 끝나면 최종 점수 계산
    if (!shark_moved) {
        best_score = std::max(best_score, score);
    }

    // 물고기 움직임 되돌리기. 역순으로 해야 함
    for (int i = fish_history.size() - 1; i >= 0; i--) {
        const auto& history = fish_history[i];

        if (!history.moved) { // 실제로 안 움직였으면 방향만 되돌리기
            board[history.fish1_row][history.fish1_col].dir = history.fish1_dir;
            continue;
        }

        board[history.fish1_row][history.fish1_col] = {history.fish1_num, history.fish1_dir};
        fish_pos[history.fish1_num] = {history.fish1_row, history.fish1_col};

        board[history.fish2_row][history.fish2_col] = {history.fish2_num, history.fish2_dir};
        if (history.fish2_num > 0) {
            fish_pos[history.fish2_num] = {history.fish2_row, history.fish2_col};
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    board.assign(4, std::vector<Fish> (4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> board[i][j].num >> board[i][j].dir;
            board[i][j].dir--;
            fish_pos[board[i][j].num] = {i, j};
        }
    }

    int shark_row = 0;
    int shark_col = 0;
    int shark_dir = board[0][0].dir;
    int score = board[0][0].num;

    int init_fish = board[0][0].num;
    fish_pos[init_fish] = {-1, -1};
    board[0][0].num = SHARK;

    Sim(shark_row, shark_col, shark_dir, score);

    std::cout << best_score;

    return 0;
}