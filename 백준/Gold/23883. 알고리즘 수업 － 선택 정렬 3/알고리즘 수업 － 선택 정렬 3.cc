/*
수마다 현재 위치를 저장해 두면 가장 큰 수에서부터 내려오면서 스왑 잘하기. O(N logN)에 가능할 듯
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, K;
    std::cin >> N >> K;

    std::vector<int> seq(N), tmp(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
        tmp[i] = seq[i];
    }

    std::sort(tmp.begin(), tmp.end());

    std::unordered_map<int, int> num_to_pos; // 수가 현재 몇 번에 있는지
    for (int i = 0; i < N; i++) {
        num_to_pos[seq[i]] = i;
    }

    for (int i = N - 1; i >= 1; i--) {
        // 가장 큰 수부터
        int cur_val = tmp[i];
        int cur_pos = num_to_pos[cur_val];
        if (cur_pos == i) {
            continue;
        }

        // tmp[i] <-> seq[i];
        int swap_val = seq[i];
        int swap_pos = num_to_pos[swap_val];

        std::swap(seq[cur_pos], seq[swap_pos]);
        num_to_pos[cur_val] = swap_pos;
        num_to_pos[swap_val] = cur_pos;

        if (--K == 0) {
            std::cout << swap_val << " " << cur_val;
            return 0;
        }
    }

    std::cout << -1;
    
    return 0;
}