/*
정렬
수 하나를 한 번 이동하여 정해진 위치로

대충 O(N^2)으로 해결 가능
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    if (N == 1) {
        std::cout << 0;
        return 0;
    }

    std::vector<int> seq(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }

    int cnt = 0;
    std::vector<std::pair<int, int>> ops;
    for (int target = 1; target <= N - 1; target++) {
        int pos = target;
        for (; pos <= N; pos++) {
            if (seq[pos] == target) {
                break;
            }
        }

        if (pos == target) {
            continue;
        }

        int L = std::min(pos, target), R = std::max(pos, target);
        std::reverse(seq.begin() + L, seq.begin() + R + 1); // [__first, __last)
        cnt++;
        ops.emplace_back(L, R);
    }

    std::cout << cnt << "\n";
    for (auto& p : ops) {
        std::cout << p.first << " " << p.second << "\n";
    }

    return 0;
}