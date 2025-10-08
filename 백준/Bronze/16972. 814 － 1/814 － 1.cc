/*
무작위로 막 찍으면 안 걸리겠지? 점수를 볼까
*/

#include <iostream>
#include <random>
#include <chrono>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(-8140, 8140);
    for (int i = 0; i < 814; i++) {
        std::cout << dist(rng) << " " << dist(rng) << "\n";
    }

    return 0;
}