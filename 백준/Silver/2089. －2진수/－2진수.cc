/*
어떤 수 N을 만들 때 양수면 1 + 4 + 16 + ...의 합이 N 이상이어야 함. 음수면 abs(-2 + (-8) + (-32) + ...)의 합이 abs(N) 이상이어야 함
*/

#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N;
    std::cin >> N;

    if (N == 0) {
        std::cout << 0;
        return 0;
    }

    std::string res;
    int prev = -1;
    while (N) {
        long long pow, pos;
        long long sum = 0;
        if (N < 0) { 
            sum = pow = -2;
            pos = 1;
        }
        else {
            sum = pow = 1;
            pos = 0;
        }

        while (std::abs(N) > std::abs(sum)) {
            pow *= 4;
            sum += pow;
            pos += 2;
        }

        N -= pow;
        if (prev == -1) {
            prev = pos;
            res += '1';
            continue;
        }

        int zero_cnt = prev - pos - 1; // 1과 1 사이에 들어갈 0의 개수
        while (zero_cnt--) {
            res += '0';
        }
        res += '1';
        prev = pos;
    }

    while (prev--) { // 하위 bit 채우기
        res += '0';
    }

    std::cout << res;

    return 0;
}