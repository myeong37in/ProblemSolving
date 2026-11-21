#include <iostream>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cur = 0;
    int max = 0;

    int in, out;
    for (int i = 0; i < 10; i++) {
        std::cin >> out >> in;
        cur += (in - out);
        max = std::max(max, cur);
    }
    
    std::cout << max;

    return 0;
}