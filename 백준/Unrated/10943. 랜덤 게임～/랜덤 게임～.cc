#include <iostream>
#include <random>
#include <chrono>

int main(int argc, char* argv[]) {
    auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::mt19937 engine(seed);

    std::uniform_int_distribution<int> num(0, 9);

    std::cout << num(engine);
}