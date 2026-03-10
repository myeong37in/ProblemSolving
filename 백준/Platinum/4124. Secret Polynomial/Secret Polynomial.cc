/*
f(1) = a, f(a) = b

모든 coefficient가 0 이상의 정수이므로 음수가 나오면 불가능

a = 0일 때 b = 0이면 0. 아니면 IMPOSSIBLE

a = 1일 때 b != 1이면 IMPOSSIBLE, 1이면 AMBIGUOUS(x, x^2, x^3 등등 있음)

f(a) = b에서 a > b면 IMPOSSIBLE

a == b라면 f(1) = a, f(a) = a이므로 상수항 f(x) = a

a >= 2일 때

d차식이라고 보고 d차항의 coefficient가 c_d라면

c_d * x^d + c_(d-1) * x^(d-1) + ... c_1 * x + c_0

f(1) = c_d       + c_(d-1)           + ... c_1     + c_0 = a
f(a) = c_d * a^d + c_(d-1) * a^(d-1) + ... c_1 * a + c_0 = b

모든 계수의 합이 a가 되어야 함

b를 a진법으로 나타내면 각 계수를 구할 수 있을 듯..? 계수의 합이 a가 아니면 IMPOSSIBLE

그러려면 d차항의 계수 c_d가 0에서 a -1 사이여야 하는데 이 경우에서는 유일하게 결정될 것.

하지만 c_d = a일 수도 있잖아. f(x) = 7x^2에서 입력이 "7 343"

그러면 b가 a의 거듭제곱인지 보면 되겠군. 문제 조건 상 최대 입력은 2^31 - 1이고 최고차항은 a = 2일 때 30임
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    long long a, b;
    while (n--) {
        std::cin >> a >> b;

        if (a < 0 || b < 0) {
            std::cout << "IMPOSSIBLE\n";
            continue;
        }

        if (a == 0) {
            if (b == 0) {
                std::cout << "0\n";
            }
            else {
                std::cout << "IMPOSSIBLE\n";
            }
            continue;
        }

        if (a == 1) {
            if (b == 1) {
                std::cout << "AMBIGUOUS\n";
            }
            else {
                std::cout << "IMPOSSIBLE\n";
            }
            continue;
        }

        if (a > b) {
            std::cout << "IMPOSSIBLE\n";
            continue;
        }

        if (a == b) {
            std::cout << a << "\n";
            continue;
        }

        // b가 a의 거듭제곱인지 확인
        long long tmp = a;
        int d = 0;
        while (tmp < b) {
            tmp *= a;
            d++;
        }

        // 거듭제곱이면 f(x) = a * x^d꼴.
        if (tmp == b) {
            // a 0 0 0 .. 0 0
            std::cout << a << " ";
            while (d--) {
                std::cout << "0 ";
            }
            std::cout << "\n";
            continue;
        }

        // 아니면 a진법 변환
        std::vector<long long> digits;
        long long sum = 0;
        while (b) {
            digits.emplace_back(b % a);
            sum += b % a;
            b /= a;
        }

        if (sum != a) {
            std::cout << "IMPOSSIBLE\n";
        }
        else {
            for (int i = digits.size() - 1; i >= 0; i--) {
                std::cout << digits[i] << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}