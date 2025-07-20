// https://www.acmicpc.net/problem/17143
// 낚시왕
// 골드 1

/*
알고리즘 문제: 핵심을 깨달으면 쉬움
구현 문제: 깨달을 핵심이 너무 많음
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Shark {
    int row;
    int col;
    int speed;
    int dir;
    int size;
};

std::vector<Shark> sharks;

int RemoveSharkAndGetSize(int C) {
    int closest_row = 101;
    auto target = sharks.end();
    // 이거 std::min_element로 lambda 표현식 사용해서 찾는 방법도 있는데 난 함수 설명을 봐도 모르겠어..
    for (auto it = sharks.begin(); it != sharks.end(); it++) {
        if (it->col == C && it->row < closest_row) {
            closest_row = it->row;
            target = it;
        }
    }

    if (target != sharks.end()) {
        int size = target->size;
        sharks.erase(target);

        return size;
    }

    return 0; // 못 찾음
}

void MoveShark(const int& R, const int& C) {
    for (auto& shark: sharks) {
        if (shark.dir == 1) {
            int cycle = 2 * (R - 1); // 상어 속도의 주기는 2 * (R - 1)
            shark.speed = shark.speed % cycle;
            if (shark.row - 1 < shark.speed) {
                if (R + shark.row - 2 < shark.speed) { // 방향이 두 번 바뀜
                    shark.row = 2 * R - shark.speed + shark.row - 2;
                }
                else { // 방향이 한 번 바뀜
                    shark.dir = 2;
                    shark.row = shark.speed - shark.row + 2;
                }
            }
            else { // 방향이 안 바뀜
                shark.row = shark.row - shark.speed;
            }
        }
        else if (shark.dir == 2) {
            int cycle = 2 * (R - 1);
            shark.speed = shark.speed % cycle;
            if (R - shark.row < shark.speed) {
                if (2 * R - shark.row - 1 < shark.speed) { // 방향이 두 번 바뀜
                    shark.row = shark.speed - 2 * R + shark.row + 2;
                }
                else { // 방향이 한 번 바뀜
                    shark.dir = 1;
                    shark.row = 2 * R - shark.speed - shark.row;
                }
            }
            else { // 방향이 안 바뀜
                shark.row = shark.row + shark.speed;
            }
        }
        else if (shark.dir == 3) {
            int cycle = 2 * (C - 1);
            shark.speed = shark.speed % cycle;
            if (C - shark.col < shark.speed) {
                if (2 * C - shark.col - 1 < shark.speed) { // 방향이 두 번 바뀜
                    shark.col = shark.speed - 2 * C + shark.col + 2;
                }
                else { // 방향이 한 번 바뀜
                    shark.dir = 4;
                    shark.col = 2 * C - shark.speed - shark.col;
                }
            }
            else { // 방향이 안 바뀜
                shark.col = shark.col + shark.speed;
            }
        }
        else {
            int cycle = 2 * (C - 1);
            shark.speed = shark.speed % cycle;
            if (shark.col - 1 < shark.speed) {
                if (C + shark.col - 2 < shark.speed) { // 방향이 두 번 바뀜
                    shark.col = 2 * C - shark.speed + shark.col - 2;
                }
                else { // 방향이 한 번 바뀜
                    shark.dir = 3;
                    shark.col = shark.speed - shark.col + 2;
                }
            }
            else { // 방향이 안 바뀜
                shark.col = shark.col - shark.speed;
            }
        }
    }
}

std::vector<Shark> GetSurvivedSharksAfterMoving(const int& R, const int& C) {
    std::vector<std::vector<Shark>> board(R + 1, std::vector<Shark> (C + 1));
    std::vector<Shark> survived_sharks;
    for (auto& shark : sharks) {
        int r = shark.row;
        int c = shark.col;
        int z = shark.size;

        if (board[r][c].size == 0) {
            board[r][c] = shark;
        }
        else {
            if (z > board[r][c].size) {
                board[r][c] = shark;
            }
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (board[i][j].row != 0) {
                survived_sharks.emplace_back(board[i][j]);
            }
        }
    }

    return survived_sharks;
}

int answer = 0;
int Simulate(const int& R, const int& C) {
    for (int i = 1; i <= C; i++) {
        answer += RemoveSharkAndGetSize(i);
        MoveShark(R, C);
        sharks = GetSurvivedSharksAfterMoving(R, C);
    }

    return answer;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C, M;
    std::cin >> R >> C >> M;

    sharks.resize(M);
    int r, c, s, d, z;
    for (int i = 0; i < M; i++) {
        std::cin >> r >> c >> s >> d >> z;
        sharks[i].row = r;
        sharks[i].col = c;
        sharks[i].speed = s;
        sharks[i].dir = d;
        sharks[i].size = z;
    }

    std::cout << Simulate(R, C);

    return 0;
}