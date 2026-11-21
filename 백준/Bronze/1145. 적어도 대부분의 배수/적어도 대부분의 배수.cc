#include <iostream>
#include <numeric>
#include <vector>
#include <limits>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> vec(5);
    for (int i = 0; i < 5; i++) {
        std::cin >> vec[i];
    }

    int min_val = std::numeric_limits<int>::max();
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 5; k++) {
                min_val = std::min(min_val, std::lcm(std::lcm(vec[i], vec[j]), vec[k]));
            }
        }
    }

    std::cout << min_val;

    return 0;
}