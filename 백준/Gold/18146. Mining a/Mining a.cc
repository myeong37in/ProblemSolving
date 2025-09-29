/*
Let a ⊕ b = x

1/n = 1/x + 1/b = (x + b) / xb

x = nb / (b - n)

b > n이고 nb를 (b - n)이 나눌 때 정수 x가 됨

b = n + y(y는 양의 정수)라면 x = n^2/y + n

x = n^2 / y + n, b = n + y

a = x ⊕ b = (n^2 / y + n) ⊕ (n + y)

y에 1을 넣으면 예제 출력이 나오는데

그야 한쪽의 값을 n^2 + n으로 만드는 것이 최대이고 다른 쪽을 n + 1로 만드는 것이 최소이므로 두 수의 차이가 최대한 커야 MSB의 위치가 가장 커지지 않겠어?
*/

#include <iostream>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        long long n;
        std::cin >> n;

        std::cout << ((n * n + n) ^ (n + 1)) << "\n";
    }

    return 0;
}