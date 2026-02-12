#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> primes;

static void Sieve(int n) {
    std::vector<bool> is_prime(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.emplace_back(i);
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    Sieve(n);

    // 이게 될까? 100만 넣어보면 되지.
    // 되네
    std::unordered_set<int> invalid, valid;
    for (int prime : primes) {
        std::unordered_set<int> trace;
        int cur = prime;
        while (true) {
            int sum = 0;
            while (cur) {
                int digit = cur % 10;
                sum += digit * digit;
                cur /= 10;
            }

            if (invalid.find(sum) != invalid.end()) {
                break;
            }
            else if (valid.find(sum) != valid.end()) {
                std::cout << prime << "\n";
                break;
            }

            if (trace.insert(sum).second == false) {
                invalid.insert(trace.begin(), trace.end());
                break;
            }
            else if (sum == 1) {
                valid.insert(trace.begin(), trace.end());
                std::cout << prime << "\n";
                break;
            }

            cur = sum;
        }
    }
    
    return 0;
}