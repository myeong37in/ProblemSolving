/*
N(x-K) >= x

(N-1)x >= NK

x >= NK / (N - 1)

N이 1이면 항상 손해
*/

#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long K, N;
    std::cin >> K >> N;

    if (N == 1) {
        std::cout << -1;
        return 0;
    }

    std::cout << (N * K + N - 2) / (N - 1);

    return 0;
}