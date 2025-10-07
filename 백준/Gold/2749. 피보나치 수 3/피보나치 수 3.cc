/*
11444번을 먼저 풀었음.
*/

#define MOD 1000000

#include <iostream>
#include <vector>

std::vector<std::vector<long long>> A = {{1, 1}, {1, 0}};

// 2x2 행렬끼리의 행렬곱을 반환하는 함수
std::vector<std::vector<long long>> MatMul(const std::vector<std::vector<long long>>& a, const std::vector<std::vector<long long>>& b) {
    std::vector<std::vector<long long>> result(2, std::vector<long long> (2));
    result[0][0] = ((a[0][0] * b[0][0]) % MOD + (a[0][1] * b[1][0]) % MOD) % MOD;
    result[0][1] = ((a[0][0] * b[0][1]) % MOD + (a[0][1] * b[1][1]) % MOD) % MOD;
    result[1][0] = ((a[1][0] * b[0][0]) % MOD + (a[1][1] * b[1][0]) % MOD) % MOD;
    result[1][1] = ((a[1][0] * b[0][1]) % MOD + (a[1][1] * b[1][1]) % MOD) % MOD;

    return result;
}

std::vector<std::vector<long long>> Fib(long long n) {
    if (n == 1) {
        return A;
    }

    std::vector<std::vector<long long>> half = Fib(n / 2);
    if (n % 2 == 0) {
        return MatMul(half, half);
    }
    else {
        return MatMul(MatMul(half, half), A);
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;

    if (n == 1) {
        std::cout << 1;
        return 0;
    }

    std::cout << Fib(n - 1)[0][0];

    return 0;
}