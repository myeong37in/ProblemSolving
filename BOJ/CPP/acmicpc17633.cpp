// https://www.acmicpc.net/problem/17633
// 제곱수의 합 (More Huge)
// 다이아몬드 3

/*
1은 바로 나온다.

일반화된 페르마의 두 제곱수 정리에 의해 2를 판별할 수 있다.
    n = x^2 + y^2 (x, y는 정수) iff n의 소인수 중 4k + 3꼴인 소수의 지수는 짝수

라그랑주의 네 제곱수 정리와 르장드르의 세 제곱수 정리에 의해 3과 4도 나온다.

그럼 됐군. Miller-Rabin과 Pollard's Rho로 소인수분해
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>
#include <unordered_map>
using ull = unsigned long long;

// ull끼리의 곱을 일시적으로 __int128로 캐스팅하여 계산 후 ull로 반환하는 함수
ull MulMod(const ull& a, const ull& b, const ull& mod) {
    __int128 prod = static_cast<__int128>(a) * b;
    prod %= mod;

    return static_cast<ull>(prod);
}

// base^d % mod를 계산하여 반환하는 함수
ull ModPow(ull base, ull d, const ull& mod) {
    ull result = 1;
    base = base % mod;

    while (d) {
        if (d % 2 == 1) {
            result = MulMod(result, base, mod);
        }
        base = MulMod(base, base, mod);
        d = d >> 1;
    }

    return result;
}

bool IsComposite(const ull& base, const ull& n, const ull& d, const int& s) {
    if (n % base == 0) {
        return true;
    }

    ull temp = ModPow(base, d, n);
    if (temp == 1 || temp == n - 1) {
        return false;
    }

    for (int i = 1; i < s; i++) {
        temp = MulMod(temp, temp, n);
        if (temp == n - 1) {
            return false;
        }
    }

    return true;
}

std::vector<ull> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool IsPrime(const ull& n) {
    ull d = n - 1; // n - 1 = d * 2^s
    int s = 0;

    while (d % 2 == 0) {
        d = d >> 1;
        s++;
    }

    for (const ull& base : bases) {
        if (n == base) {
            return true;
        }

        if (IsComposite(base, n, d, s)) {
            return false;
        }
    }

    return true;
}

auto seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 engine(seed);
ull GetRandNum(const ull& left, const ull& right) {
    std::uniform_int_distribution<ull> dist(left, right);
    return dist(engine);
}

ull CalcFunc(const ull& x, const ull& c, const ull& mod) {
    ull x_square = MulMod(x, x, mod);
    return (x_square + c) % mod;
}

ull PollardsRho(const ull& n) {
    if (n % 2 == 0) {
        return 2;
    }

    while (true) {
        ull c = GetRandNum(1, n - 1);
        ull x = GetRandNum(2, n - 2);
        ull y = x;
        ull d = 1;

        while (d == 1) {
            x = CalcFunc(x, c, n);
            y = CalcFunc(CalcFunc(y, c, n), c, n);
            ull diff = (x > y) ? x - y : y - x;

            d = std::gcd(diff, n);
            if (d == n) { // 실패했으므로 다른 x, c값을 시도
                break;
            }
        }
        if (d > 1 && d < n) {
            return d;
        }
    }
}

// n을 재귀적으로 인수분해하는 함수
void GetFactors(std::unordered_map<ull, int>& factors, const ull& n) {
    if (n == 1) {
        return;
    }
    if (IsPrime(n)) {
        factors[n]++;
        return;
    }

    ull d = PollardsRho(n);
    GetFactors(factors, d);
    GetFactors(factors, n / d);
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull n;
    std::cin >> n;

    ull square_root = std::sqrt(n);
    if (square_root * square_root == n) {
        std::cout << 1;
        return 0;
    }

    std::unordered_map<ull, int> factors;
    GetFactors(factors, n);

    // 일반화된 페르마의 두 제곱수 정리
    bool okay = true;
    for (const auto& p : factors) {
        auto [factor, count] = p;
        if (factor % 4 == 3) {
            if (count % 2 == 1) {
                okay = false;
                break;
            }
        } 
    }

    if (okay) {
        std::cout << 2;
        return 0;
    }

    // 르장드르의 세 제곱수 정리 + 라즈랑주의 네 제곱수 정리
    while (n % 4 == 0) {
        n /= 4;
    }

    if (n % 8 == 7) {
        std::cout << 4;
    }
    else { 
        std::cout << 3;
    }

    return 0;
}