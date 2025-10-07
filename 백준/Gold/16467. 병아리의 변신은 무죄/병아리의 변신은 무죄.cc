/*
chick[i]: i일째 병아리의 수
egg[i]: i일째 알의 수

chick[i] = chick[i - K] + chick[i - K - 1]
egg[i] = egg[i - 1] + chick[i - 1] - chick[i - K - 1]

v_i = [chick[i], chick[i - 1], chick[i - 2] ... chick[i - K]]^T일 때
v_i+1 = [chick[i + 1], chick[i], chick[i - 1] ... chick[i - K + 1]]^T

v_i+1[0] = v_i[0] + v_i[K]
v_i+1[j] = v_i[j - 1] (j > 0)

Transition matrix
[1 0 0 ... 0 0 1]
[1 0 0 ... 0 0 0]
[0 1 0 ... 0 0 0]
[      ...      ]
[0 0 0 ... 0 1 0]

C[N] = v_N[0] = (T^N v_0)[0] = T^N[0][0]
*/

#include <iostream>
#include <vector>

constexpr int MOD = 1e8 + 7; // what..?

std::vector<std::vector<long long>> Identity(int M) {
    std::vector<std::vector<long long>> I(M, std::vector<long long> (M));
    for (int i = 0; i < M; i++) {
        I[i][i] = 1;
    }

    return I;
}

// MxM matrix의 행렬곱 행렬 반환
std::vector<std::vector<long long>> MatMul(const std::vector<std::vector<long long>>& a, const std::vector<std::vector<long long>>& b) {
    int M = a.size();
    std::vector<std::vector<long long>> res(M, std::vector<long long> (M));
    for (int i = 0; i < M; i++) {
        for (int k = 0; k < M; k++) {
            for (int j = 0; j < M; j++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }

    return res;
}

std::vector<std::vector<long long>> Solve(const std::vector<std::vector<long long>>& T, int exp) {
    if (exp == 0) {
        int M = T.size();
        return Identity(M);
    }

    std::vector<std::vector<long long>> half = Solve(T, exp / 2);
    if (exp & 1) {
        return MatMul(MatMul(T, half), half);
    }
    else {
        return MatMul(half, half);
    }
}

long long ModPow(int base, int exp) {
    long long res = 1;
    while (exp) {
        if (exp & 1) {
            res = (res * base) % MOD;
        }

        base = (1LL * base * base) % MOD;
        exp >>= 1;
    }

    return res;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc;
    std::cin >> tc;

    int K, N;
    while (tc--) {
        std::cin >> K >> N;

        if (K == 0) {
            std::cout << ModPow(2, N) << "\n";
            continue;
        }

        int M = K + 1;
        std::vector<std::vector<long long>> T(M, std::vector<long long> (M));
        T[0][0] = 1;
        T[0][K] = 1;
        for (int r = 1; r < M; r++) {
            T[r][r - 1] = 1;
        }

        std::cout << (Solve(T, N)[0][0]) % MOD << "\n";
    }

    return 0;
}