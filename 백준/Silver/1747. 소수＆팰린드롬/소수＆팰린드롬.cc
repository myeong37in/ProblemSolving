/*
오.. 여섯 자릿수 자연수 중 팰린드롬인 소수가 없네

N >= 98689일 때 답: 1,003,001
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> palindrome_primes;

static inline bool IsPalindrome(const std::string& str) {
    int sz = str.size();
    for (int i = 0; i < sz / 2; i++) {
        if (str[i] != str[sz - i - 1]) {
            return false;
        }
    }

    return true;
}

static void Sieve(int N) {
    std::vector<bool> is_prime(N + 1, true);
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && IsPalindrome(std::to_string(i))) {
            palindrome_primes.emplace_back(i);
        }
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    if (N >= 98689) {
        std::cout << 1003001;
        return 0;
    }

    Sieve(1e5);

    std::cout << palindrome_primes[std::lower_bound(palindrome_primes.begin(), palindrome_primes.end(), N) - palindrome_primes.begin()];

    return 0;
}