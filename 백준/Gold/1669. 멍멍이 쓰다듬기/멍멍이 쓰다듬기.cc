/*
1011번이잖아.

차이가 diff일 때 (1 + 2 + 3 + ... + k) + (k-1 + k-2 + ... + 1) <= diff인 가장 큰 k를 찾으면 다음의 식이 성립한다.

(1 + 2 + ... + k) + (k - 1 + k - 2 + ... + 1) <= diff < (1 + 2 + ... + k + 1) + (k + k - 1 + ... + 1)

k^2 <= diff < (k+1)^2 = k^2 + 2k + 1

k^2 <= diff < k^2 + k + 1 < k^2 + 2k + 1

k^2 == diff이면 단조 증가 후 단조 감소로 들어온다. 2k - 1일 소요
k^2 + 1 <= diff <= k^2 + k이라면 중간에 1에서 k 사이의 성장을 추가로 한 번 해서 들어온다. 2k일 소요
k^2 + k + 1 <= diff < k^2 + 2k + 1이면 1에서 k 사이의 성장을 추가로 두 번 해서 들어온다. 2k + 1일 소요
*/

#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int X, Y;
    std::cin >> X >> Y;

    if (X == Y) {
        std::cout << 0;
        return 0;
    }
    
    int d = Y - X;

    int n = static_cast<int>(std::sqrt(d));
    if (n * n == d) {
        std::cout << 2 * n - 1 << "\n";
    }
    else if (n * n + n + 1 <= d) {
        std::cout << 2 * n + 1 << "\n";
    }
    else {
        std::cout << 2 * n << "\n";
    }
    return 0;
}