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

static long long ModPow(long long base, long long mod, long long exp) {
    long long res = 1;
    while (exp) {
        if (exp & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;        
        exp >>= 1;
    }

    return res;
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

    constexpr long long MOD = 998244353;

    long long fact_n_sub_kp = 1;
    for (int i = 2; i <= n - k * p; i++) {
        fact_n_sub_kp = (fact_n_sub_kp * i) % MOD;
    }
    
    long long fact_n_sub_p = fact_n_sub_kp;
    for (int i = n - k * p + 1; i <= n - p; i++) {
        fact_n_sub_p = (fact_n_sub_p * i) % MOD;
    }

    long long fact_n = fact_n_sub_p;
    for (int i = n - p + 1; i <= n; i++) {
        fact_n = (fact_n * i) % MOD;
    }

    long long ans;
    ans = ((1LL - ((ModPow(fact_n_sub_p, MOD, k) * ModPow(fact_n_sub_kp, MOD, MOD - 2)) % MOD) * ModPow(fact_n, MOD, MOD - k)) % MOD + MOD) % MOD;
    std::cout << ans;
    
    return 0;
}