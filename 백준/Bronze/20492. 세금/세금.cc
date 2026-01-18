#include <iostream>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long N;
    std::cin >> N;
    
    std::cout << N * 78 / 100 << " " << N - N * 20 * 22 / 10000;
}