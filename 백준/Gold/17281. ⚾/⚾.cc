/*
경우의 수 8!
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> res(N, std::vector<int> (10)); // i번 이닝에서 j번 타자 결과
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= 9; j++) {
            std::cin >> res[i][j];
        }
    }

    std::vector<int> tmp = {2, 3, 4, 5, 6, 7, 8, 9};
    int best_score = 0;
    do {
        // next_permutation으로 얻은 순서에서 4번째에 1번 끼워넣기
        std::vector<int> order(9);
        for (int i = 0; i < 3; i++) {
            order[i] = tmp[i];
        }
        order[3] = 1;
        for (int i = 4; i < 9; i++) {
            order[i] = tmp[i - 1];
        }

        int score = 0;
        int hitter_idx = 0; // 0-8
        for (int inning = 0; inning < N; inning++) {
            int runner_mask = 0; // MSB: 3루, LSB: 1루. 111: 모든 루에 주자 있음. 000: 주자 없음.
            int out = 0;
            while (true) {
                int hitter_num = order[hitter_idx];
                int r = res[inning][hitter_num];
                if (r == 0) {
                    out++;
                }
                else {
                    // 주자들 진루하고 타자 진루
                    runner_mask = ((runner_mask << r) | (1 << (r - 1)));
                    score += __builtin_popcount(runner_mask >> 3);
                    runner_mask %= 8;
                }
                hitter_idx = (hitter_idx + 1) % 9;

                if (out >= 3) {
                    break;
                }
            }
        }
        
        best_score = std::max(best_score, score);
    } while (std::next_permutation(tmp.begin(), tmp.end()));

    std::cout << best_score;
    
    return 0;
}