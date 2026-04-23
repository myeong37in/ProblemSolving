/*
몰라 일단 해봐
*/

#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long p, q, e, C;
    std::cin >> p >> q >> e >> C;

    long long n = p * q;
    long long phi_n = n - (p + q - 1);

    long long d; // ..이거 어떻게 하더라? 기억 안 나니까 완전 탐색 ㄱ
    for (d = 1; d < phi_n; d++) {
        if ((d * e) % phi_n == 1) {
            break;
        }
    }

    long long M = 1;
    for (int i = 0; i < d; i++) {
        M = (M * C) % n;
    }

    std::cout << M;

    return 0;
}