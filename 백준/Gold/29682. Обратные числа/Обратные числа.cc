/*
FLT넹

a^p-1 ≡ 1 (mod p)

a * a^p-2 ≡ 1 (mod p)

따라서 a^p-2 ≡ b (mod p)
*/

#include <iostream>

int ModPow(int base, int exp, int mod) {
    int res = 1;
    while (exp) {
        if (exp & 1) {
            res = (1LL * res * base) % mod;
        }
        base = (1LL * base * base) % mod;
        exp >>= 1;
    }

    return res;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, m;
    std::cin >> a >> m;

    std::cout << ModPow(a, m - 2, m);

    return 0;
}