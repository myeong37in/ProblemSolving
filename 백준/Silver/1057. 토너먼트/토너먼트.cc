/*
두 수가 (c - 1) * 2^n + 1에서 c * 2^n의 범위에 공통으로 들어갈 때 n이 라운드 수가 되겠다. (c >= 1 and n >= 1)
*/

#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Kim, Lim;
    std::cin >> N >> Kim >> Lim;

    if (Kim > Lim) {
        std::swap(Kim, Lim);
    }

    for (int rounds = 1; rounds <= 17; rounds++) { // 2^17 = 131,072
        int div = 1;
        while ((div - 1) * (1 << rounds) + 1 <= N) {
            if ((div - 1) * (1 << rounds) + 1 <= Kim && div * (1 << rounds) >= Lim) {
                std::cout << rounds;
                return 0;
            }
            div++;
        }
    }

    return 0;
}