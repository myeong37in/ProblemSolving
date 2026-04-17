/*
(a + b) % K == 0

a % K = i일 때, b % K = K - i

그러면 K로 나눈 나머지가 1에서 절반(N / 2)까지 되는 수 개수 세면

특정 조합 i, K - i (1 <= i <= N / 2)에 대해

K로 나눈 나머지가 i인 수의 개수가 x, K - i인 수의 개수가 y리면

어떤 부분집합이 

K로 나눈 나머지가 i인 수를 포함하는 경우 2^x - 1

K로 나눈 나머지가 K - i인 수를 포함하는 경우 2^y - 1

두 수는 양립할 수 없으므로
나머지가 i인 수만 고르는 경우 + 나머지가 K - i인 수만 고르는 경우 + 둘 다 안 고르는 경우

나머지가 i인 수만 고르는 경우 2^x - 1

나머지가 K - i인 수만 고르는 경우 2^y - 1

둘 다 안 고르는 경우 1

합해서 2^x + 2^y - 1

이것을 가능한 i에 대해 반복

이 결과를 total이라고 하면, total에는 크기가 1인 집합이 N개 있을 것. 공집합 1개 고려하면 T - N - 1

i = 0, N이 짝수일 때 N / 2인 경우에는 두 개 이상 고를 수 없으므로 경우의 수는 개
*/

#include <iostream>
#include <vector>

constexpr int MOD = 1e9 + 7;

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, K;
    std::cin >> N >> K;

    std::vector<int> cnts(K);
    int A;
    for (int i = 0; i < N; i++) {
        std::cin >> A;

        cnts[A % K]++;
    }

    // pow2[i] = 2^i % MOD
    std::vector<long long> pow2(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    long long total = 1;

    // 나머지 0
    total = total * (cnts[0] + 1) % MOD;

    for (int i = 1; i < (K + 1) / 2; i++) {
        int j = K - i;
        long long cur = (pow2[cnts[i]] + pow2[cnts[j]] - 1 + MOD) % MOD;
        total = (total * cur) % MOD;
    }

    if ((K & 1) == 0) {
        total = total * (cnts[K / 2] + 1) % MOD;
    }

    std::cout << (total - N - 1 + MOD) % MOD;
    
    return 0;
}