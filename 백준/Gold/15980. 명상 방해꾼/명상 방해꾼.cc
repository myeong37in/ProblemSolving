/*
다 있을 때의 결과를 저장해 두고 하나씩 빼는 시뮬레이션
L에 있는 새를 뺐을 때 특정 시간에서 1이었으면 R 방향으로 1 더하면 됨. 반대도 마찬가지

O(NM)
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<char, std::string>> birds(N);
    for (int i = 0; i < N; i++) {
        std::cin >> birds[i].first >> birds[i].second;
    }

    std::vector<int> val(M); // L 방향으로 -1, R 방향으로 +1
    for (int i = 0; i < M; i++) {
        if (i > 0) {
            val[i] = val[i - 1];
        }

        for (auto& [pos, str] : birds) {
            if (pos == 'L') {
                val[i] -= str[i] - '0';
            }
            else {
                val[i] += str[i] - '0';
            }
        }
    }

    int best_val = 2e9;
    int best_id = 1;
    for (int i = 0; i < N; i++) {
        auto& [pos, str] = birds[i];
        int max_val = 0; // i번 새를 뺐을 때 절댓값의 최댓값
        int delta = 0; // i번 새를 뺐을 때 변화량 누적
        for (int j = 0; j < M; j++) {
            int cur_orig_val = val[j]; 
            if (pos == 'L') {
                delta += str[j] - '0';
            }
            else {
                delta -= str[j] - '0';
            }

            cur_orig_val += delta;
            max_val = std::max(max_val, std::abs(cur_orig_val));
        }

        if (best_val > max_val) {
            best_val = max_val;
            best_id = i + 1;
        }
    }

    std::cout << best_id << "\n" << best_val;
    
    return 0;
}