#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double A, B, C;
    std::cin >> A >> B >> C;

    std::cout << static_cast<int>(std::max(A * B / C, A / B * C));

    return 0;
}