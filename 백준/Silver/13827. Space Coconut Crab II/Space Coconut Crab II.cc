/*
세 변의 합이 T이고 세 변의 길이가 모두 소수인 삼각형의 개수

가장 짧은 변의 길이를 a라고 하면 a <= T/3

30,000 이하의 소수의 개수 대략 3,000개
10,000 이하의 소수의 개수 대략 1,000개

변의 길이 오름차순으로, a와 b를 정하면 c는 이분 탐색이고 나머지 가지치기로 되지 않을까
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> primes;
static void Sieve(int n) {
    std::vector<int> is_prime(n + 1, true);

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
    
    Sieve(30'000);
    
    int T;
    while (std::cin >> T) {
        if (T == 0) {
            break;
        }

        int sz = primes.size();
        int a_limit = T / 3;
        int ans = 0;
        for (int a = 0; a < sz; a++) {
            if (primes[a] > a_limit) {
                break;
            }

            for (int b = a; b < sz; b++) {
                int c = std::lower_bound(primes.begin(), primes.end(), T - primes[a] - primes[b]) - primes.begin();
                
                if (c < b) {
                    break;
                }

                // 끝 체크
                if (c == sz) {
                    continue;
                }

                if (primes[c] >= primes[a] + primes[b]) {
                    continue;
                }

                if (primes[a] + primes[b] + primes[c] == T) {
                    ans++;
                }
            }
        }

        std::cout << ans << "\n";
    }
    
    return 0;
}