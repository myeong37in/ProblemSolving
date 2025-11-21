#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        
        std::vector<int> seq(N);
        std::vector<int> team_cnt(201); // 각 팀의 인원 수
        int t;
        for (int i = 0; i < N; i++) {
            std::cin >> t;
            seq[i] = t;
            team_cnt[t]++;
        }

        int score = 1;
        std::vector<std::vector<int>> teams(201);
        for (int i = 0; i < N; i++) {
            int team = seq[i];
            if (team_cnt[team] != 6) {
                continue;
            }

            teams[team].emplace_back(score++); // 6명인 팀의 점수 목록
        }

        for (int i = 1; i <= 200; i++) {
            std::sort(teams[i].begin(), teams[i].end());
        }

        int best_sum = 2e9;
        int best_fifth = 2e9;
        int best_team = 0;

        for (int i = 1; i <= 200; i++) {
            if (teams[i].size() != 6) {
                continue;
            }

            int sum = 0;
            int fifth = teams[i][4];
            for (int j = 0; j < 4; j++) {
                sum += teams[i][j];
            }

            if (best_sum > sum || (best_sum == sum && best_fifth > fifth)) {
                best_sum = sum;
                best_fifth = fifth;
                best_team = i;
            }
        }

        std::cout << best_team << "\n";
    }

    return 0;
}