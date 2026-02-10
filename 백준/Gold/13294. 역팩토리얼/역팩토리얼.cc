/*
정밀도를 봅시다.

n! = N일 때 10진수 N에서 앞의 수 18개를 뽑은 18자릿수 자연수 x를 잡으면 x * 10^(L - 18) <= N < (x + 1) * 10^(L - 18)

따라서 log(x) + (L - 18) * log(10) <= log(N) < log(x + 1) + (L - 18) * log(10)

log(N) = log(n!) = log(1) + log(2) + ... log(n)

따라서 n까지 log값을 더하면서 저 사이에 들어가는 n이 나오면 끝
*/

#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;

    int L = str.size();
    
    if (L <= 18) {
        long long N = std::stoll(str);
        long long fact = 1;
        int mult = 1;
        while (true) {
            fact *= mult;
            
            if (fact == N) {
                break;
            }
            mult++;
        }

        std::cout << mult;
        return 0;
    }

    long double x = 0;
    for (int i = 0; i < 18; i++) {
        x = x * 10 + (str[i] - '0');
    }

    long double sum = 0;
    long double lo = std::log(x) + (L - 18) * std::log(10);
    long double hi = std::log(x + 1) + (L - 18) * std::log(10);
    int mult = 2;
    // 오차 고려
    while (true) {
        sum += std::log(mult);
        if (sum < lo) {
            mult++;
        }
        else if (sum > lo) { // 넘었으면 이전 값
            std::cout << mult - 1;
            break;
        }
        else {
            std::cout << mult;
            break;
        }
    }

    return 0;
}