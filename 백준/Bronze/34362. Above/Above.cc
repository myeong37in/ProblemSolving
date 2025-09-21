#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double N;
    std::cin >> N;

    std::cout << std::fixed << std::setprecision(4) << N - 0.3;

    return 0;
}