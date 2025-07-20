// https://www.acmicpc.net/problem/5977
// Mowing the Lawn
// 플래티넘 3

/*
기본적으로 누적합을 사용하면 점화식
dp[i]: i번째 수까지 얻을 수 있는 최대 합
i번째 수를 선택하지 않을 때: dp[i] = dp[i-1]
i번째 수를 선택할 때 연속 구간의 길이가 j이면: dp[i] = dp[i-j-1] + psum[i] - psum[i-j] (1 <= j <= K)
즉,
dp[i] = max(dp[i-1], dp[i-2] + psum[i] - psum[i-1], dp[i-3] + psum[i] - psum[i-2], ... dp[i-K-1] + psum[i] - psum[i-K])

근데 문제는 O(NK)라 결국 문제의 조건대로면 O(N^2)이란 말이지
식을 변형할 필요가 있다.

dp[i] = max(dp[i-1], dp[i-2] + psum[i] - psum[i-1], dp[i-3] + psum[i] - psum[i-2], ..., dp[i-K-1] + psum[i] - psum[i-K])
      = max(dp[i-1] - psum[i], dp[i-2] - psum[i-1], dp[i-3] - psum[i-2], ... dp[i-K-1] - psum[i-K]) + psum[i]

seq = {1, 2, 3, 4, 5, 6, 7}이고 K = 3일 때
dp[1] = 1
dp[2] = 3
dp[3] = 6
dp[4] = max(dp[3] - psum[4], dp[2] - psum[3], dp[1] - psum[2], dp[0] - psum[1]) + psum[4]

이 상태로도 여전히 O(NK)이지만
dp[i-j-1] - psum[i-j]를 하나의 식으로 묶어서 deque을 이용해 최댓값을 O(1)에 찾는 트릭을 쓰면??

1) 인덱스를 저장하는 deque을 구성
2) i = 1에서 N까지 dp[deq.back() - 1] - psum[deq.back()]이 dp[i - 1] - psum[i]보다
    2-1) 크거나 같다면 i를 그냥 넣기 (최댓값 후보 유지)
    2-2) 작다면 dp[deq.back() - 1] - psum[deq.back()] >= dp[i-1] - psum[i]가 될 때까지 deq.pop.back() (최댓값 후보 교체)
3) deq.front()가 현재 범위를 벗어나면 deq.pop_front() (i - K > deq.front())
4) deq.front()가 범위 내 최댓값의 인덱스가 된다. dp[i] = dp[deq.front() - 1] - psum[deq.front()] + psum[i]
*/

#include <iostream>
#include <vector>
#include <deque>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<int> seq(N + 1);
    std::vector<long long> psum(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
        psum[i] = psum[i - 1] + seq[i];
    }

    std::vector<long long> dp(N + 1);
    for (int i = 1; i <= K; i++) {
        dp[i] = psum[i];
    }

    // deque trick
    std::deque<int> deq;
    for (int i = 1; i <= N; i++) {
        while (!deq.empty() && (dp[deq.back() - 1] - psum[deq.back()]) < ((dp[i - 1] - psum[i]))) {
            deq.pop_back();
        }
        deq.push_back(i);

        if (i - K > deq.front()) {
            deq.pop_front();
        }

        if (i > K) {
            dp[i] = dp[deq.front() - 1] - psum[deq.front()] + psum[i];
        }
    }

    std::cout << dp[N];

    return 0;
}