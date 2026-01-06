/*
정렬하고 양옆에서 하나씩

중복 계산 방지 위해 한 번 계산하고 차이나는 개체 수만큼 빼기

O(N logN)
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> vec(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i].first >> vec[i].second;
    }

    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    int l_idx = 0, r_idx = N - 1;
    int best = 0;
    while (l_idx <= r_idx) {
        best = std::max(best, vec[l_idx].second + vec[r_idx].second);

        if (l_idx == r_idx) { // 마지막에 중간 지점에서 같은 것끼리 비교
            break;
        }

        int& l_rem = vec[l_idx].first;
        int& r_rem = vec[r_idx].first;

        int tmp = l_rem;
        l_rem = std::max(0, tmp - r_rem);
        r_rem = std::max(0, r_rem - tmp);

        if (l_rem == 0) {
            l_idx++;
        }
        if (r_rem == 0) {
            r_idx--;
        }
    }

    std::cout << best;
    
    return 0;
}