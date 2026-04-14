/*
well-known은 빠르게 해결합시다.

transition matrix
[1 1]
[1 0]
*/

#include <iostream>
#include <vector>

std::vector<std::vector<long long>> transition_mat = {{1, 1}, {1, 0}};
std::vector<std::vector<long long>> identity_mat = {{1, 0}, {0, 1}};

constexpr int MOD = 1e9;

static std::vector<std::vector<long long>> matmult2x2by2x2(const std::vector<std::vector<long long>>& a, const std::vector<std::vector<long long>>& b) {
    std::vector<std::vector<long long>> res(2, std::vector<long long> (2));
    res[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    res[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    res[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    res[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;

    return res;
}

static std::vector<std::vector<long long>> matmult2x2by2x1(const std::vector<std::vector<long long>>& a, const std::vector<std::vector<long long>>& b) {
    std::vector<std::vector<long long>> res(2, std::vector<long long> (1));
    res[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    res[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;

    return res;
}

static std::vector<std::vector<long long>> MatPow(long long n) {
    if (n == 0) {
        return identity_mat;
    }

    if (n == 1) {
        return transition_mat;
    }

    std::vector<std::vector<long long>> half = MatPow(n / 2);
    
    if (n & 1) {
        return matmult2x2by2x2(transition_mat, matmult2x2by2x2(half, half));
    }
    else {
        return matmult2x2by2x2(half, half);
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    std::vector<std::vector<long long>> init = {{1}, {1}};

    long long x;
    while (t--) {
        std::cin >> x;

        if (x <= 2) {
            std::cout << 1 << "\n";
            continue;
        }

        std::cout << matmult2x2by2x1(MatPow(x - 2), init)[0][0] << "\n";
    }

    return 0;
}