/*
1, 2번은 a < c, b < c이므로 최대 2500^2 = 625만 번의 반복
    이지만 
    1) 서로 다른 거 구하는 거니까 a < b
    2) 그리고 a + b > c여야 하므로
    이것보다는 훨씬 작을 것
3, 4번은 2500^2 + x^2 = y^2이어야 하는데,
2500^2 + x^2 < (x+1)^2이 되는 최초 x가 최댓값

2x + 1 > 2500^2

대충 3,125,000
*/

#include <iostream>
#include <numeric>
#include <cmath>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long n;
    std::cin >> n;

    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (long long a = 1; a < n; a++) {
        for (long long b = a + 1; b < n; b++) {
            if (a + b <= n) {
                continue;
            }

            if (a * a + b * b == n * n) {
                if (std::gcd(std::gcd(a, b), n) == 1) {
                    cnt1++;
                }
                else {
                    cnt2++;
                }
            }
        }
    }

    for (long long x = 1; x <= 3'125'000; x++) {
        long long squared = x * x + n * n;
        long long square_root = std::sqrt(squared);
        if (square_root * square_root == squared) {
            if (std::gcd(std::gcd(x, n), square_root) == 1) {
                cnt3++;
            }
            else {
                cnt4++;
            }
        }
    }

    std::cout << cnt1 << " " << cnt2 << " " << cnt3 << " " << cnt4;
    
    return 0;
}