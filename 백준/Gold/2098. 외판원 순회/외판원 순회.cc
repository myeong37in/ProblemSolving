/*
i: 방문한 전체 도시의 집합을 bit 조합으로 계산한 값, j: 현재 도시, dp[i][j]: 방문한 도시 조합에서 현재 j번 도시에 있을 때 정점(도시) 연결 비용의 최솟값
*/

#define INF 1e9

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> W(N, std::vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> W[i][j];
            if (W[i][j] == 0) {
                W[i][j] = INF; // 자기 자신으로 가는 경로는 선택하지 못하게 함
            }
        }
    }

    int total_combo = pow(2, N);
    std::vector<std::vector<int>> dp(total_combo, std::vector<int> (N, INF));
    dp[1][0] = 0; // 0번째 도시에서 시작
    for (int mask = 1; mask <= total_combo; mask++) {
        for (int current = 0; current < N; current++) {
            // 아니 이 거지같은 게 if (mask & (1 << current) == 1)이면 (1 << current) == 1이 먼저 계산되고 그 다음 mask와 그 결과를 bitwise AND한다고? 난 비트마스킹이 싫어요
            if (mask & (1 << current)) { // 이렇게 써야 한다고.. 현재 조합에서 current를 방문했어야 함
                for (int next = 0; next < N; next++) {
                    if (mask & (1 << next)) { // 현재 조합에서 next를 이미 방문했으면 continue
                        continue;
                    }
                    else {
                        dp[mask | (1 << next)][next] = std::min(dp[mask | (1 << next)][next], dp[mask][current] + W[current][next]);
                    }
                }
            }
        }
    }

    int answer = INF;
    for (int current = 1; current < N; current++) {
        if (dp[total_combo - 1][current] + W[current][0] < answer) {
            answer = dp[total_combo - 1][current] + W[current][0]; // 전체를 방문한 후 현재 1번부터 N - 1번 도시에 있을 때 0번 도시로 돌아오는 비용을 더해 최솟값 채택
        }
    }

    std::cout << answer;

    return 0;
}