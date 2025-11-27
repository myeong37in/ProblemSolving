/*
높이를 높이를 h, B의 좌표를 (0, 0), C의 좌표를 (2a, 0)이라고 하면 A의 좌표는 (a, h)

이때 BC 위의 임의의 점 P의 x좌표를 b라고 하면 B는 (b, 0)

AP^2 + BP * CP = (a - b)^2 + h^2 + b * (2a - b) = a^2 + h^2 = N^2

P를 어디로 잡느냐에 관계 없이 N^2 고정 
*/

#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N, K;
    std::cin >> N >> K;

    std::cout << N * N * K;

    return 0;
}