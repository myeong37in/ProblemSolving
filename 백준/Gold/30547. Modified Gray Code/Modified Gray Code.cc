/*
바뀌는 상태 수 C(10, 2) + C(10, 4) + C(10, 6) + C(10, 8) + C(10, 10) = 511

전체 511 * 500 * alpha

최대 수 2^10 - 1 = 1023
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int MAX = (1 << 10) - 1;
    std::vector<bool> used(MAX + 1);
    used[0] = true;
    std::vector<int> codes = {0};
    int prev = 0;
    for (int i = 1; i <= 500; i++) {
        int next_min = MAX;
        for (int mask = 1; mask <= MAX; mask++) {
            if ((__builtin_popcount(mask) & 1) == 0) {
                int next_num = prev ^ mask;
                
                if (!used[next_num]) {
                    next_min = std::min(next_min, next_num);
                }
            }
        }

        codes.emplace_back(next_min);
        used[next_min] = true;
        prev = next_min;
    }

    int N, K;
    std::cin >> N;
    while (N--) {
        std::cin >> K;

        int decimal = codes[K];
        for (int i = 9; i >= 0; i--) {
            if (decimal & (1 << i)) {
                std::cout << 1;
            }
            else {
                std::cout << 0;
            }
        }
        std::cout << "\n";
    }

    return 0;
}