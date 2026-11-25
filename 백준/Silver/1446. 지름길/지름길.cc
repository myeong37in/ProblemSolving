/*
dp[i]: i까지 가는 최소 거리

dp[0] = 0
dp[i] = min(dp[i - 1] + 1, i가 도차 지점이고 시작 지점이 s, 거리가 d인 모든 지름길에 대해 dp[s] + d)
*/

#include <iostream>
#include <vector>

struct Path {
    int s, e, d;
};

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, D;
    std::cin >> N >> D;

    std::vector<Path> paths(N);
    for (int i = 0; i < N; i++) {
        std::cin >> paths[i].s >> paths[i].e >> paths[i].d;
    }

    std::vector<int> dp(D + 1);
    for (int i = 1; i <= D; i++) {
        dp[i] = dp[i - 1] + 1;
        for (const auto& [s, e, d] : paths) {
            if (e == i) {
                dp[i] = std::min(dp[i], dp[s] + d);
            }
        }
    }


    std::cout << dp[D];

    return 0;
}