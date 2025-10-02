/*
정렬을 하고 더하는 것과 빼는 것을 따로 고려해 보면

임의의 수를 포함하는 조합은 2^N - 1개 있음

따라서 가장 작은 수는 2^N - 1번 빼야 함
두 번째로 작은 수는 2^(N - 1) - 1번 빼야 함
...
두 번째로 큰 수는 2^(1 - 1) - 1 = 1번 빼야 함
가장 큰 수는 2^0 - 1 = 0번 빼야 함

마찬가지로
가장 큰 수는 2^N - 1번 더해야 함
두 번째로 큰 수는 2^(N - 1) - 1번 더해야 함
...
두 번째로 작은 수는 1번 더해야 함
가장 작은 수는 0번 더해야 함

O(N log N)?
*/

#include <iostream>
#include <vector>
#include <algorithm>

constexpr int MOD = 1e9 + 7;

long long ModPow(int base, int exp) {
    long long res = 1;
    while (exp) {
        if (exp & 1) {
            res = (res * base) % MOD;
        }
        base = (1LL * base * base) % MOD;
        exp >>= 1;
    }

    return res;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<long long> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    std::sort(seq.begin(), seq.end());

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long t = (ModPow(2, i) - 1 + MOD) % MOD;
        ans = (ans + seq[i] * t) % MOD;
        t = (ModPow(2, N - i - 1) - 1 + MOD) % MOD;
        ans = (ans - seq[i] * t) % MOD;
    }

    std::cout << ((ans % MOD) + MOD) % MOD;

    return 0;
}