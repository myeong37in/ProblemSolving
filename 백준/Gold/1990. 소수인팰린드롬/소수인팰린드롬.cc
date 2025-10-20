/*
이래서 정수론을 끊을 수가 없어. 너무 신기하고 재밌자너

명제: 자릿수가 짝수인 팰린드롬이면서 소수인 자연수는 11 하나뿐이다.
증명: 
1) 두 자릿수인 팰린드롬 11a. a = 1일 때를 제외하면 모두 11의 배수인 합성수이다.
2) 네 자릿수인 팰린드롬 1000a + 100b + 10b + a = 1001a + 110b = 11(91a + 10b).
3) 10^k ≡ (-1)^k (mod 11)이므로 1000a + 100b + 10b + a = 1001a + 110b ≡ -a + b - b + a = 0 (mod 11)
4) 자릿수가 둘 늘어날 때마다 일반성을 잃지 않고 항상 어떤 숫자와 대응되는 같은 숫자가 홀-짝 관계를 이루므로 11로 나눈 나머지를 합해서 0이 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> palindrome_primes;

static inline bool IsPalindrome(const std::string& str) {
    int L = str.size();
    for (int i = 0; i < L / 2; i++) {
        if (str[i] != str[L - 1 - i]) {
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

    int a, b;
    std::cin >> a >> b;

    Sieve(std::min(b, 9'999'999)); // 100,000,000은 소수가 아니고 여덟 자리 수는 팰린드롬 소수가 아니므로

    int lo = std::lower_bound(palindrome_primes.begin(), palindrome_primes.end(), a) - palindrome_primes.begin();
    int hi = std::upper_bound(palindrome_primes.begin(), palindrome_primes.end(), b) - palindrome_primes.begin();
    for (int i = lo; i < hi; i++) {
        std::cout << palindrome_primes[i] << "\n";
    }
    std::cout << -1;

    return 0;
}