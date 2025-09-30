/*
n >= 7일 때
    n이 짝수라면 2를 6개, 나머지 3으로. -> 6 * 2^2 + (n - 6) * 3^2
    6, 3^2은 3의 배수이고 2^2, n - 6은 2의 배수이므로 2와 3으로 나누어 떨어진다.

    n이 홀수라면 2를 3개, 나머지 3으로. -> 3 * 2^2 + (n - 3) * 3^2
    3, 3^2은 3의 배수이고 2^2, n - 3은 2의 배수이므로 2와 3으로 나누어 떨어진다.

n = 2, 3, 4일 때 -> 150 이하의 소수에 대해 bruteforcing
n = 5일 때 2, 2, 2, 3, 3
n = 6일 때 2, 2, 3, 3, 3, 5
*/

#include <iostream>
#include <vector>

std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149};

bool backtrack(std::vector<int>& selected, int depth, int N) {
    if (depth == N) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += selected[i] * selected[i];
        }

        if (sum == N * selected[0] * selected[0]) { // 다 같은 경우
            return false;
        }

        for (int i = 0; i < N; i++) {
            if (sum % selected[i]) {
                return false;
            }
        }

        for (int i = 0; i < N; i++) {
            std::cout << selected[i] << " ";
        }
        return true;
    }

    for (int i = 0; i < primes.size(); i++) {
        selected.emplace_back(primes[i]);
        if (backtrack(selected, depth + 1, N)) {
            return true;
        }
        selected.pop_back();
    }

    return false;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    if (N == 5) {
        std::cout << "2 2 2 3 3";
        return 0;
    }

    if (N == 6) {
        std::cout << "2 2 3 3 3 5";
        return 0;
    }

    if (N >= 7) {
        if (N & 1) {
            std::cout << "2 2 2 ";
            for (int i = 0; i < N - 3; i++) {
                std::cout << "3 ";
            }
        }
        else {
            std::cout << "2 2 2 2 2 2 ";
            for (int i = 0; i < N - 6; i++) {
                std::cout << "3 ";
            }
        }
        return 0;
    }

    std::vector<int> selected;
    if (!backtrack(selected, 0, N)) {
        std::cout << "-1";
    }

    return 0;
}