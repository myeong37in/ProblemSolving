/*
제곱이니까 언제나 가장 짧은 거리를 가는 것이 이득임
-> 젠장. 한국어 능력도 퇴화했나.. 간단한 반례가 있거늘

대충 O(N^2) DP로 해결될 듯
*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::string str;
    std::cin >> N >> str;

    constexpr int INF = 2e9;
    std::vector<int> dp(N, INF);
    dp[0] = 0;
    for (int s = 0; s < N - 1; s++) {
        char target;
        if (str[s] == 'B') {
            target = 'O';
        }
        else if (str[s] == 'O') {
            target = 'J';
        }
        else {
            target = 'B';
        }

        for (int e = s + 1; e < N; e++) {
            if (str[e] == target) {
                dp[e] = std::min(dp[e], dp[s] + (e - s) * ( e - s));
            }
        }
    }

    std::cout << (dp[N - 1] == INF ? -1 : dp[N - 1]);
    
    return 0;
}