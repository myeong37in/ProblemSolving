#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, F;
    std::cin >> N >> F;

    int n = (N / 100) * 100;
    for (; n < N + 100; n++) {
        if (n % F == 0) {
            break;
        }
    }

    std::cout << std::setw(2) << std::setfill('0') << n % 100;

    return 0;
}