/*
a = 0일 때 1개

1/1
1/2
...
1/N

2/2(1/1과 동일)
2/3
2/4(1/2와 동일)
2/N

이렇게 완전탐색으로 a = 1부터 N까지, b는 a부터 N까지 GCD를 구하면 되는데 문제는 이게 O(N^2)...인데요?

각각의 b에 대해 a/b를 판별하면, a와 b가 서로소여야 카운트. Euler phi function이네

소인수도 구해야 하고 함숫값 구하는 상수도 큰데 O(TN) 가능? 

구한 값을 저장해 두면 중복 계산은 피할 수 있군

일단 해봅시다.
*/

#include <iostream>
#include <vector>

std::vector<int> primes;

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
        if (is_prime[i]) {
            primes.emplace_back(i);
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Sieve(10'001);
    
    int t;
    std::cin >> t;

    std::vector<int> ans(10'001);
    ans[0] = 1;
    ans[1] = 1;

    int N;
    while (t--) {
        std::cin >> N;

        int total = 0;
        for (int num = 0; num <= N; num++) {
            if (ans[num]) {
                total += ans[num];
                continue;
            }

            int idx = 0;
            int tmp = num;
            while (idx < primes.size() && primes[idx] <= num) {
                if ((num % primes[idx]) == 0) {
                    tmp = tmp * (primes[idx] - 1) / primes[idx];
                }
                idx++;
            }

            ans[num] = tmp;
            total += tmp;
        }

        std::cout << total << "\n";
    }

    return 0;
}