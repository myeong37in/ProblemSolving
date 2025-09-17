/*
정렬 후 앞에서부터 채우면서 커버 범위의 끝을 유지
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, K;
        std::cin >> N >> K;
        
        int ans = 0;
        int last_end = -1;

        std::vector<std::pair<int, int>> intervals(N);
        for (int i = 0; i < N; i++) {
            std::cin >> intervals[i].first >> intervals[i].second;
        }

        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
           
        for (int i = 0; i < N; i++) {
            auto& [s, e] = intervals[i];

            if (e <= last_end) {
                continue;
            }

            if (s < last_end) {
                s = last_end;
            }

            int q = (e - s + K - 1) / K;
            int rem = (e - s) % K;

            ans += q;
            last_end = s + q * K;
        }

        std::cout << "Case #" << tc << ": " << ans << "\n";
    }

    return 0;
}