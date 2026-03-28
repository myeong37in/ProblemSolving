/*
이게 정답률이 왜 이러지..?
*/

#include <iostream>
#include <cmath>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;

    long long sqrt_n = std::sqrt(n);
    if (sqrt_n * sqrt_n >= n) {
        std::cout << sqrt_n;
    }
    else {
        std::cout << sqrt_n + 1;
    }

    return 0;
}