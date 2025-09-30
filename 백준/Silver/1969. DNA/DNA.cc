/*
그리디
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> vec(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i];
    }

    std::string best_str;
    int best_dist = 0;
    for (int i = 0; i < M; i++) {
        std::vector<int> cnt(4);
        for (int j = 0; j < N; j++) {
            if (vec[j][i] == 'A') {
                cnt[0]++;
            }
            else if (vec[j][i] == 'C') {
                cnt[1]++;
            }
            else if (vec[j][i] == 'G') {
                cnt[2]++;
            }
            else {
                cnt[3]++;
            }
        }

        auto it = std::max_element(cnt.begin(), cnt.end());
        if (it == cnt.begin()) {
            best_str += 'A';
            best_dist += cnt[1] + cnt[2] + cnt[3];
        }
        else if (it == cnt.begin() + 1) {
            best_str += 'C';
            best_dist += cnt[0] + cnt[2] + cnt[3];
        }
        else if (it == cnt.begin() + 2) {
            best_str += 'G';
            best_dist += cnt[0] + cnt[1] + cnt[3];
        }
        else {
            best_str += 'T';
            best_dist += cnt[0] + cnt[1] + cnt[2];
        }
    }

    std::cout << best_str << "\n" << best_dist;

    return 0;
}