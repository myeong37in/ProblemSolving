#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int K, N, M;
    std::cin >> K >> N >> M;

    std::cout << std::max(0, K * N - M);

    return 0;
}