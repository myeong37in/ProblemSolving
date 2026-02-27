#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    long long prev = -9e18;
    long long A;
    for (int i = 0; i < N; i++) {
        std::cin >> A;
        if (A == prev) {
            std::cout << 0;
            return 0;
        }
        prev = A;
    }

    std::cout << 1;

    return 0;
}