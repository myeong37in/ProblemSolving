/*
정렬하고 투 포인터 쓰면 되겠군
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    if (M == 0) {
        std::cout << 0;
        return 0;
    }

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    std::sort(seq.begin(), seq.end());

    int left = 0, right = 0;
    int best = 2e9;
    while (right < N) {
        int diff = seq[right] - seq[left];
        if (diff >= M) {
            best = std::min(best, diff);
            left++;
        }
        else {
            right++;
        }
    }

    std::cout << best;

    return 0;
}