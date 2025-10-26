#include <iostream>
#include <numeric>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int a, b;
        std::cin >> a >> b;

        std::cout << std::lcm(a, b) << " " << std::gcd(a, b) << "\n";
    }

    return 0;
}