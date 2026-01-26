/*
분모
1
12
321
1234
54321
...

분자
1
21
123
4321
12345
...

묶음에서 가장 큰 수가 x일 때 x(x+1)/2 >= n인 최소 x

x^2 + x - 2n >= 0, x >= (-1 + sqrt(1 + 8n)) / 2

맞왜틀

또 너냐 double
*/

#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long n;
    std::cin >> n;

    long long x = std::ceil((-1.0L + sqrtl(1.0L + 8 * n)) / 2);
    long long rem = x * (x + 1) / 2 - n;
    long long denominator, numerator;
    if (x & 1) { // 분자 1부터 x까지
        numerator = x - rem;
        denominator = 1 + rem;
    }
    else { // 분자 x부터 1까지
        numerator = 1 + rem;
        denominator = x - rem;
    }

    std::cout << numerator << "/" << denominator;
    
    return 0;
}