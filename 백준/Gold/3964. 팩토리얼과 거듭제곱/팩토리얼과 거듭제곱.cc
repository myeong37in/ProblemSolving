/*
팩토리얼과 거듭제곱이 싸운다고요? Finger crossed for David..

10^6까지 소수 판정

Legendre's theorem
*/

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> primes;

void Sieve(int N) {
    std::vector<bool> is_prime(N + 1, true);
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.emplace_back(i);
        }
    }
}

std::unordered_map<long long, int> PrimeFactorize(long long k) {
    long long tmp = k;
    std::unordered_map<long long, int> res;
    for (const int& prime : primes) {
        if (1LL * prime * prime > tmp) {
            break;
        }

        while (tmp % prime == 0) {
            res[prime]++;
            tmp /= prime;
        }
    }

    if (tmp > 1) {
        res[tmp]++;
    }

    return res;
}

long long Legendre(long long prime, long long n) {
    long long ans = 0;
    long long tmp = n;

    while (tmp) {
        ans += tmp / prime;
        tmp /= prime;
    }
    return ans;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Sieve(1'000'000);

    int T;
    std::cin >> T;

    while (T--) {
        long long n, k;
        std::cin >> n >> k;

        std::unordered_map<long long, int> prime_factors = PrimeFactorize(k);
        long long best = 9e18;
        for (const auto& p : prime_factors) {
            long long prime = p.first;
            best = std::min(best, Legendre(prime, n) / p.second);
        }

        std::cout << best << "\n";
    }

    return 0;
}