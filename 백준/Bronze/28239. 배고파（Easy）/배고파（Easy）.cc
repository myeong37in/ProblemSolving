/*
bruteforcing
y는 최대 59.
*/

#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    long long m;
    while (n--) {
        std::cin >> m;

        int shift = 0;
        while (true) {
            long long cur = m - (1LL << shift);
            if ((-cur & cur) == cur) {
                std::cout << shift << " " << std::log2(cur) << "\n";
                break;
            }
            shift++;
        }
    }

    return 0;
}