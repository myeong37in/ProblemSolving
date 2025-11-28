/*
x1 - x2 ≡ (a * (seed - x1)) % m

a ≡ (x1 - x2) * (seed - x1)^(-1) mod m
  ≡ (x1 - x2) * (seed - x1)^(m-2) mod m     (seed - x1)^(m-1) mod m = 1 (x1 != seed일 때, FLT. 둘이 같으면 seed = x1 = x2일 것이고 여러 개의 a, c 존재)

a가 구해지면 c = (x1 - (a * seed) % m + m) % m으로
*/

#include <iostream>

long long ModPow(long long base, long long exp, long long mod) {
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

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long m, seed, x1, x2;
    std::cin >> m >> seed >> x1 >> x2;

    if (x1 == seed) {
        std::cout << "1 0"; // 가장 간단한 답으로
        return 0;
    }
    
    long long a = ((x1 - x2 + m) * ModPow(seed - x1 + m, m - 2, m)) % m;
    long long c = (x1 - (a * seed) % m + m) % m;

    std::cout << a << " " << c;

    return 0;
}