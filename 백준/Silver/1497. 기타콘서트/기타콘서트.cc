/*
기타 10개 -> 10! 조합
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::string guitar_name, can_play;
    std::vector<std::string> guitars(N);

    bool all_false = true;
    for (int i = 0; i < N; i++) {
        std::cin >> guitar_name >> can_play;
        for (const char& ch : can_play) {
            if (!all_false) {
                break;
            }

            if (ch == 'Y') {
                all_false = false;
                break;
            }
        }
        guitars[i] = can_play;
    }

    if (all_false) {
        std::cout << -1;
        return 0;
    }

    int global_max_cnt = -1; // 최대 플레이 곡 수 
    int global_min_guitar = 1e9; // 최소 기타 수
    for (int guitar_cnt = 1; guitar_cnt <= N; guitar_cnt++) { // 기타 수
        std::vector<bool> selected(N);
        for (int i = N - 1; i >= N - guitar_cnt; i--) {
            selected[i] = true;
        }

        do {
            std::vector<bool> songs(M);
            for (int i = 0; i < N; i++) {
                if (selected[i]) {
                    for (int j = 0; j < M; j++) {
                        if (guitars[i][j] == 'Y') {
                            songs[j] = true;
                        }
                    }
                }
            }

            int cur_playable = 0;
            for (int i = 0; i < M; i++) {
                if (songs[i] == true) {
                    cur_playable++;
                }
            }

            if (global_max_cnt < cur_playable) { // 플레이 가능 곡의 수를 갱신할 때만 기타 수 갱신
                global_max_cnt = cur_playable;
                global_min_guitar = guitar_cnt;
            }
        } while (std::next_permutation(selected.begin(), selected.end()));
    }

    std::cout << global_min_guitar;

    return 0;
}