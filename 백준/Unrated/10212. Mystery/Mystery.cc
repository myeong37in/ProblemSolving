#include <iostream>
#include <chrono>
#include <random>

int main(int argc, char* argv[]) {
    auto seed = std::chrono::steady_clock::now().time_since_epoch().count();

    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dd(0, 1);

    int num = dd(rng);
    std::cout << (num ? "Yonsei" : "Korea");
}