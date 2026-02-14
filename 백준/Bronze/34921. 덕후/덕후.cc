#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A, T;
    std::cin >> A >> T;

    std::cout << std::max(0, 10 + 2 * (25 - A + T));

    return 0;
}