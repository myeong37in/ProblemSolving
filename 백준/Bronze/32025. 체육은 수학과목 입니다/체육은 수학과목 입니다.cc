#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W;
    std::cin >> H >> W;

    std::cout << std::min(H, W) * 100 / 2;

    return 0;
}