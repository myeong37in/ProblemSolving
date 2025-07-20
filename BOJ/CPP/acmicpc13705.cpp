// https://www.acmicpc.net/problem/13705
// Ax+Bsin(x)=C
// 다이아몬드 5

/*
14786번보다 더 정밀한 정확도를 어떻게 달성할까?

문제를 보고 떠오른 생각이 2개 있다.
1) sin 함수의 Taylor series 표현. 항이 충분히 많다면 <cmath>의 sin보다 더 정밀한 값을 얻을 수 있을 것이다.
2) 그 정밀한 결과를 저장하기 위한 더 정밀한 부동소수점 자료형. long double같은 것.

sin(x): summation from n = 0 to n = inf, (-1)^n * x^(2n+1) / (2n+1)!
= x - x^3/3! + x^5/5! - x^7/7! + x^9/9! ...

float128 자료형 사용
*/

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286Q

#include <iostream>
#include <iomanip>
#include <vector>

typedef __float128 float128;

// float128 TaylorSin(const float128& x) { // 일단 항 12개. 사실 long long의 한계로 따로 처리 없이는 이거 이상 쓰지도 못함.
//     return x - x*x*x/6 + x*x*x*x*x/120 - x*x*x*x*x*x*x/5040 + x*x*x*x*x*x*x*x*x/362880 - 
//     x*x*x*x*x*x*x*x*x*x*x/39916800 + x*x*x*x*x*x*x*x*x*x*x*x*x/6227020800 - x*x*x*x*x*x*x*x*x*x*x*x*x*x*x/1307674368000 + 
//     x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x/355687428096000 - x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x/121645100408832000;
// }

// WA의 원인으로 std::sin의 정밀도가 의심됨. 일반항 사용
float128 TaylorSin(const float128& x) {
    float128 term = x;
    float128 sum = term;

    for (int i = 1; i <= 30; i++) { // 일단 30개
        term *= - x * x / (static_cast<float128>(2 * i) * static_cast<float128>(2 * i + 1));
        sum += term;
    }

    return sum;
}

// 가장 고전적인 방법
void PrintFloat128(const float128& x, const int& n) { 
    int integer_part = static_cast<int>(x);

    float128 fraction = x - static_cast<float128>(integer_part);

    std::vector<int> digit(n);
    for (int i = 0; i < n; i++) {
        fraction *= 10;
        digit[i] = static_cast<int>(fraction);
        fraction -= static_cast<float128>(digit[i]);
    }

    fraction *= 10;
    int digit7 = static_cast<int>(fraction);
    
    if (digit7 >= 5) {
        digit[5] += 1;
    }
    
    // carry도 처리
    for (int i = 5; i > 0; i--) {
        if (digit[i] == 10) {
            digit[i] = 0;
            digit[i - 1] += 1;
        }
        else {
            break;
        }
    }

    if (digit[0] == 10) {
        digit[0] = 0;
        integer_part += 1;
    }

    std::cout << integer_part << ".";
    for (const int& d : digit) {
        std::cout << d;
    }
}

// 가장 고전적인 방법 2
float128 GetRemainder(const float128& x, const float128& y) {
    float128 original = x;
    while (original >= y) {
        original -= y;
    }
    return original;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A, B, C;
    std::cin >> A >> B >> C;

    float128 left = static_cast<float128>(C - B) / A;
    float128 right = static_cast<float128>(C + B) / A;

    while (right - left > 1e-28) { // double -> long double -> __float128로 바뀌면서 임계값이 계속 줄어듦
        float128 mid = (left + right) / 2;
        float128 reduced = GetRemainder(mid, PI * 2);
        float128 result = mid * A + TaylorSin(reduced) * B;

        if (result > C) {
            right = mid;
        }
        else if (result <= C) {
            left = mid;
        }
    }

    float128 answer = (left + right) / 2; // 이건 cout도 안 됨;
    PrintFloat128(answer, 6);

    return 0;
}