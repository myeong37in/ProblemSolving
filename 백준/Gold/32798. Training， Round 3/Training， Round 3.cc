/*
k * p > n이면 0, k = 1이면 1

확률
1 - (모든 주에서 각 (C(이전 주까지 뽑지 않고 남은 문제 수, p) / C(n, p))의 곱)

예제1
1 - C(3, 1)/C(3, 1) * C(2, 1)/C(3, 1) * C(1, 1)/C(3, 1) = 7/9

1 - C(n, p)/C(n, p) * C(n-p, p)/C(n, p) * C(n-2p, p)/C(n, p) * ... * C(n - (k-1)p, p)/C(n, p)

정리

1 - ((((n!)/(n-p)!(p!)) * (((n-p)!)/((n-2p)!)(p!)) * ... * (((n-(k-1)p)!)/((n-kp)!)(p!))) / C(n, p)^k

= 1 - (n!/((n-kp)!p!)) / ((n!)^k/((n-p)!^k * (p!)^k))

= 1 - ((n-p)!)^k / ((n-kp)! * (n!)^k-1)

= ((n-kp)! * (n!)^(k-1) - ((n-p)!)^k) / ((n-kp)! * (n!)^(k-1))

분자와 분모가 각각 x, y인데 이거 약분되면 어캄

몰라 일단 MOD = 998244353일 때

r ≡ x * y^(-1) (mod MOD)

= ((n-kp)! * (n!)^(k-1) - ((n-p)!)^k) * ((n-kp)!)^(-1) * (n!)^(1-k) (mod MOD)

어찌 되었든 MOD가 소수이므로

(n-kp)!)^(-1) ≡ (n-kp)!^(MOD - 2)

(n!)^(1-k) ≡ (n!)^(MOD - k)

((n-kp)! * (n!)^(k-1) - ((n-p)!)^k) * ((n-kp)!)^(-1) * (n!)^(1-k)

≡ ((n-kp)! * (n!)^(k-1) - ((n-p)!)^k) * ((n-kp)!)^(MOD - 2) * (n!)^(MOD - k) (mod MOD)

≡ (n-kp)^(MOD - 1) * (n!)^(MOD - 1) - (n-p)!^k * ((n-kp)!)^(MOD - 2) * (n!)^(MOD - k) (mod MOD)

≡ 1 - (n-p)!^k * ((n-kp)!)^(MOD - 2) * (n!)^(MOD - k) (mod MOD)

팩토리얼 어떻게 구함?

뭘 어떻게 구해 최대 10^7이니까 반복문이지
*/

#include <iostream>
#include <vector>

static __int128_t ModPow(long long base, long long mod, long long exp) {
    __int128_t res = 1;
    while (exp) {
        if (exp & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;        
        exp >>= 1;
    }

    return res;
}

std::vector<__int128_t> fact;

static void ModFact(long long n, long long mod) {
    __int128_t res = 1;
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; i++) {
        res = (res * i) % mod;
        fact[i] = res;
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long n, k, p;
    std::cin >> n >> k >> p;

    if (k * p > n) {
        std::cout << 1;
        return 0;
    }
    else if (k == 1) {
        std::cout << 0;
        return 0;
    }

    fact.resize(n + 1);

    constexpr long long MOD = 998244353;
    ModFact(n, MOD);

    __int128_t ans;
    ans = (static_cast<__int128_t>(1) - ModPow(fact[n - p], MOD, k) * ModPow(fact[n - k * p], MOD, MOD - 2) * ModPow(fact[n], MOD, MOD - k)) % MOD + MOD;
    std::cout << static_cast<long long>(ans);
    
    return 0;
}