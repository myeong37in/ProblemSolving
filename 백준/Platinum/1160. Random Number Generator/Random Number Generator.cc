/*
transition matrix를 이용한 행렬식
[ X_n+1 ] = [ a c ] x [ X_n ]
[   1   ]   [ 0 1 ]   [  1  ]

[  X_n  ] = [ a c ]^n x [ X_0 ]
[   1   ]   [ 0 1 ]     [  1  ]
*/   

#include <iostream>
#include <vector>

using u128 = __uint128_t;

long long m, a, c, x0, n, g;

std::vector<std::vector<u128>> I = {{1, 0}, {0, 1}}; // Identity matrix

std::vector<std::vector<u128>> MatMul22x22(const std::vector<std::vector<u128>>& a, const std::vector<std::vector<u128>>& b) {
    std::vector<std::vector<u128>> res(2, std::vector<u128> (2));
    res[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % m; 
    res[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % m;
    res[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % m;
    res[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % m;

    return res;
}

std::vector<std::vector<u128>> MatPow(std::vector<std::vector<u128>> mat, long long exp) {
    if (exp == 0) {
        return I;
    }
    else if (exp == 1) {
        return mat;
    }

    std::vector<std::vector<u128>> half = MatPow(mat, exp / 2);
    if (exp & 1) {
        return MatMul22x22(MatMul22x22(half, half), mat);
    }
    else {
        return MatMul22x22(half, half);
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> m >> a >> c >> x0 >> n >> g;

    if (m == 1) {
        std::cout << 0;
        return 0;
    }

    std::vector<std::vector<u128>> T = {{static_cast<u128>(a), static_cast<u128>(c)}, {0, 1}};
    std::vector<std::vector<u128>> ans = MatPow(T, n);

    std::cout << static_cast<long long>((x0 * ans[0][0] + ans[0][1]) % m) % g;

    return 0;
}