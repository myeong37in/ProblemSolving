/*
끼야악 조합 귀신이다

inclusion-exclusion principle

13개의 랭크에 각각에 대해 A_r: 랭크가 r인 4개의 문양이 모두 포함되는 사건으로 보면

A_r의 합집합
summation from k = 1 to k = ⌊N/4⌋​, ((-1)^(k - 1) * (13개 랭크 중 four of a kind를 완성할 k개의 랭크를 뽑는 경우의 수) * (52장의 카드 중 앞서 뽑은 k개의 four of a kind 쌍을 포함한 뒤 남은 N - 4k개의 카드를 뽑는 경우의 수))

즉슨, C(13, k) * C(52 - 4k, N - 4k)
*/

#include <iostream>

constexpr int MOD = 10007;

static inline int GetCombination(int n, int k) {
    long long res = 1;
    // C(52, 26)은 대략 4.96 * 10^14
    for (int i = k + 1; i <= n; i++) {
        res *= i;
        res /= i - k;
    }

    return static_cast<int>(res % MOD);
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    if (N <= 3) {
        std::cout << 0;
        return 0;
    }

    int ans = 0;
    for (int k = 1; k <= N / 4; k++) {
        int val = (GetCombination(13, k) * GetCombination(52 - 4 * k, N - 4 * k)) % MOD;
        if (k & 1) {
            ans = (ans + val) % MOD;
        }
        else {
            ans = (ans + MOD - val) % MOD;
        }
    }

    std::cout << ans;

    return 0;
}