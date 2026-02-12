/*
끝나는 날짜 기준으로 정렬해 두고 

dp[i]: i일까지의 답으로 하면

최초 dp[i] = i (아무 여행도 안 가는 경우)

i일에서 dp[i] = min(max(i - j의 끝 날짜, dp[j의 시작 날짜 - 1])) for (i일, 혹은 그 이전에 끝나는 모든 여행 j)
    i - j의 끝 날짜: j의 끝부터 i일까지의 공백

dp[N]이 답

O(NM logM)
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> trips(M);
    int s, e;
    for (int i = 0; i < M; i++) {
        std::cin >> s >> e;
        trips[i] = {s, e};
    }

    std::sort(trips.begin(), trips.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    std::vector<int> dp(N + 1);
    for (int i = 1; i <= N; i++) { // 여행 x
        dp[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        // trips의 요소 중 second가 i보다 작거나 같은 첫 번째 요소 찾기
        auto it = std::upper_bound(trips.begin(), trips.end(), i, [](int val, const auto& p) {
            return val < p.second;
        });

        if (it == trips.begin()) {
            continue;
        }
        else {
            int idx = std::prev(it) - trips.begin();
            for (int j = 0; j <= idx; j++) {
                dp[i] = std::min(dp[i], std::max(i - trips[j].second, dp[trips[j].first - 1]));
            }
        }
    }

    std::cout << dp[N];
    
    return 0;
}