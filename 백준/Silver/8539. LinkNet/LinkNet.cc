/*
20에서 겹쳐서 3인 거구만
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i].first >> seq[i].second;
    }

    std::sort(seq.begin(), seq.end(), [](const auto& a, const auto& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        auto& [s, e] = seq[i];

        while (!pq.empty() && pq.top() < s) {
            pq.pop();
        }

        pq.push(e);
        ans = std::max(ans, static_cast<int>(pq.size()));
    }

    std::cout << ans;
    
    return 0;
}