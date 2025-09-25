/*
에라토스테네스의 체
입력이 123456까지니까 123456*2까지의 소수를 미리 계산 후 저장
소수의 벡터는 정렬되어 있으므로 이분 탐색으로 시작, 끝 확인. 개수 출력
*/

#define MAX 123456

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> GetPrimes(const int& num) {
    std::vector<bool> is_prime(num + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= num; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= num; j += i) {
                is_prime[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= num; i++) {
        if (is_prime[i]) {
            primes.emplace_back(i);
        }
    }

    return primes;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> primes = GetPrimes(MAX * 2);
    int n;
    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }
        int start_idx = std::upper_bound(primes.begin(), primes.end(), n) - primes.begin();
        int end_idx = std::upper_bound(primes.begin(), primes.end(), 2 * n) - primes.begin() - 1;

        std::cout << end_idx - start_idx + 1<< "\n";
    }

    return 0;
}