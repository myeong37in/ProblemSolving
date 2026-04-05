/*
기댓값 E(d) = 1/(n - d) * (m - d^2f^2) = (m - d^2f^2) / (n - d)를 최대화하는 d를 찾아라?

미분이지 뭐..

∂((m - d^2f^2) / (n - d)) / ∂d

= (f^2 * d^2 - 2 * n * f^2 * d + m) / (n - d)^2

d < n이므로 (n - d)^2는 항상 양수. 분자만 보면 됨

f^2 * d^2 - 2 * n * f^2 * d + m = 0

d^2 - 2 * n * d + m/f^2 = 0

(d - n)^2 + m/f^2 - n^2 = 0

d = n ± sqrt(n^2 - m/f^2)

d < n에 의해 d = n - sqrt(n^2 - m/f^2)

1) n^2 - m/f^2 <= 0인 경우 
    n^2 * f^2 < m
    E(d) = (m - d^2 * f^2) / (n - d)에서, m = n^2 * f^2일 때 E(d) = f^2 * (n + d). 즉, 양수
    m이 이것보다 크거나 같다는 것이므로 항상 양수임. 증가함수니까 d = n - 1일 때 최댓값
    
3) m/f^2 - n^2 > 0인 경우
    d = n - sqrt(n^2 - m/f^2)일 때 극댓값을 가짐
    d는 정수여야 하므로 이와 가까운 정수 둘
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long double n, m, f; // std::numeric_limits<long double>::digits = 64
    std::cin >> n >> m >> f;

    if ((n * n - m / (f * f)) <= 0) {
        // d = n - 1
        std::cout << std::fixed << std::setprecision(8) << m - (n - 1) * (n - 1) * f * f;
    }
    else {
        long double d = n - std::sqrt(n * n - m / (f * f));
        
        long long d1 = static_cast<long long>(std::floor(d));
        long long d2 = d1 + 1;

        long double ans = std::max((m - f * f * d1 * d1) / (n - d1), (m - f * f * d2 * d2) / (n - d2));

        std::cout << std::fixed << std::setprecision(8) << ans;
    }

    return 0;
}