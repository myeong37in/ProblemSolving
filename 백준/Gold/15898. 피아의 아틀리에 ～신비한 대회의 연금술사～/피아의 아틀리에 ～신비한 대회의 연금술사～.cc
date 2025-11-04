/*
재료 고르기 + 순서 정하기 P(10, 3)
3개를 넣을 위치와 회전 16^3
25칸 변경을 3번 변경
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Cell {
    int val;
    char color;
};

std::vector<std::vector<std::vector<std::vector<Cell>>>> ingredients;

std::vector<std::vector<Cell>> RotateClockWise(std::vector<std::vector<Cell>>& orig) {
    std::vector<std::vector<Cell>> res(4, std::vector<Cell> (4));
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            res[r][c] = orig[3 - c][r];
        }
    }

    return res;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    ingredients.assign(n, std::vector<std::vector<std::vector<Cell>>> (4, std::vector<std::vector<Cell>> (4, std::vector<Cell> (4))));
    for (int i = 0; i < n; i++) {
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                std::cin >> ingredients[i][0][r][c].val;
            }
        }

        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                std::cin >> ingredients[i][0][r][c].color;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int dir = 1; dir < 4; dir++) {
            ingredients[i][dir] = RotateClockWise(ingredients[i][dir - 1]);
        }
    }

    std::vector<int> ids(n);
    for (int i = n - 1; i >= n - 3; i--) {
        ids[i] = 1;
    }

    std::vector<std::vector<Cell>> board(5, std::vector<Cell> (5, {0, 'W'}));
    // 투입 시작 칸과 회전 여부
    std::vector<std::vector<int>> pos = {{0, 0, 0}, {0, 0, 1}, {0, 0, 2}, {0, 0, 3}, 
                                         {0, 1, 0}, {0, 1, 1}, {0, 1, 2}, {0, 1, 3},
                                         {1, 0, 0}, {1, 0, 1}, {1, 0, 2}, {1, 0, 3},
                                         {1, 1, 0}, {1, 1, 1}, {1, 1, 2}, {1, 1, 3}
                                        };
    int best = 0;
    do { // 재료 정하기
        std::vector<int> selected;
        for (int i = 0; i < n; i++) {
            if (ids[i]) {
                selected.emplace_back(i);
            }
        }

        do { // 순서 정하기
            for (int pos_0 = 0; pos_0 < 16; pos_0++) { // 위치 정하기
                for (int pos_1 = 0; pos_1 < 16; pos_1++) {
                    for (int pos_2 = 0; pos_2 < 16; pos_2++) {
                        std::vector<std::vector<Cell>> tmp = board;

                        // 재료 1 투입
                        int cur = selected[0];
                        int sr = pos[pos_0][0];
                        int sc = pos[pos_0][1];
                        int dir = pos[pos_0][2];
                        
                        for (int r = sr; r < sr + 4; r++) {
                            for (int c = sc; c < sc + 4; c++) {
                                int new_val = tmp[r][c].val + ingredients[cur][dir][r - sr][c - sc].val;
                                new_val = std::max(0, new_val);
                                new_val = std::min(9, new_val);

                                tmp[r][c].val = new_val;
                                char new_color = ingredients[cur][dir][r - sr][c - sc].color;
                                if (new_color != 'W') {
                                    tmp[r][c].color = new_color;
                                }
                            }
                        }

                        // 재료 2 투입
                        cur = selected[1];
                        sr = pos[pos_1][0];
                        sc = pos[pos_1][1];
                        dir = pos[pos_1][2];

                        for (int r = sr; r < sr + 4; r++) {
                            for (int c = sc; c < sc + 4; c++) {
                                int new_val = tmp[r][c].val + ingredients[cur][dir][r - sr][c - sc].val;
                                new_val = std::max(0, new_val);
                                new_val = std::min(9, new_val);

                                tmp[r][c].val = new_val;
                                char new_color = ingredients[cur][dir][r - sr][c - sc].color;
                                if (new_color != 'W') {
                                    tmp[r][c].color = new_color;
                                }
                            }
                        }

                        // 재료 3 투입
                        cur = selected[2];
                        sr = pos[pos_2][0];
                        sc = pos[pos_2][1];
                        dir = pos[pos_2][2];

                        for (int r = sr; r < sr + 4; r++) {
                            for (int c = sc; c < sc + 4; c++) {
                                int new_val = tmp[r][c].val + ingredients[cur][dir][r - sr][c - sc].val;
                                new_val = std::max(0, new_val);
                                new_val = std::min(9, new_val);

                                tmp[r][c].val = new_val;
                                char new_color = ingredients[cur][dir][r - sr][c - sc].color;
                                if (new_color != 'W') {
                                    tmp[r][c].color = new_color;
                                }
                            }
                        }

                        // 결과 계산
                        int blue_sum = 0, red_sum = 0, green_sum = 0, yellow_sum = 0;
                        for (int r = 0; r < 5; r++) {
                            for (int c = 0; c < 5; c++) {
                                char color = tmp[r][c].color;
                                if (color == 'R') {
                                    red_sum += tmp[r][c].val;
                                }
                                else if (color == 'B') {
                                    blue_sum += tmp[r][c].val;
                                }
                                else if (color == 'G') {
                                    green_sum += tmp[r][c].val;
                                }
                                else if (color == 'Y') {
                                    yellow_sum += tmp[r][c].val;
                                }
                            }
                        }

                        best = std::max(best, 7 * red_sum + 5 * blue_sum + 3 * green_sum + 2 * yellow_sum);
                    }
                }
            }
        } while (std::next_permutation(selected.begin(), selected.end()));
    } while (std::next_permutation(ids.begin(), ids.end()));

    std::cout << best;

    return 0;
}