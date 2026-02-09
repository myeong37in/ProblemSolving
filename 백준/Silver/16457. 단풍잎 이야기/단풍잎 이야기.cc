/*
C(20, 10)
*/

#include <iostream>
#include <vector>

std::vector<int> quest_keys;

int best = 0;
static void backtrack(int start, int selected, int cnt, int n) {
    if (cnt == n) {
        int cur = 0;
        for (auto& mask : quest_keys) {
            if ((selected & mask) == mask) { // selected의 모든 bit가 mask의 모든 bit 포함
                cur++;
            }
        }

        best = std::max(best, cur);
        return;
    }

    for (int i = start; i <= 2 * n; i++) {
        backtrack(i + 1, selected | (1 << i), cnt + 1, n);
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        int mask = 0;
        int num;
        for (int j = 0; j < k; j++) {
            std::cin >> num;
            mask |= (1 << num);
        }

        quest_keys.emplace_back(mask);
    }

    backtrack(1, 0, 0, n);

    std::cout << best;
    
    return 0;
}