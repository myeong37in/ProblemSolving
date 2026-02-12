/*
기약분수 꼴로 a/b, c/d를 만듦

GCD : gcd(a, c) / (bd / gcd(b, d))
LCM: (ac / gcd(a, c)) / gcd(b, d)
*/

#include <iostream>
#include <numeric>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;

    long long a, b, c, d;
    while (T--) {
        std::cin >> a >> b >> c >> d;
        
        int gcd1 = std::gcd(a, b);
        int gcd2 = std::gcd(c, d);
        a /= gcd1;
        b /= gcd1;
        c /= gcd2;
        d /= gcd2;

        std::cout << std::gcd(a, c) << "/" << b * d / std::gcd(b, d) << " ";
        std::cout << a * c / std::gcd(a, c) << "/" << std::gcd(b, d) << "\n";
    }
    
    return 0;
}