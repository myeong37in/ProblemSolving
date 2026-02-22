#include <iostream>
#include <cmath>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double D, H, W;
    std::cin >> D >> H >> W;

    double width = std::sqrt((D * D) * (W * W) / (H * H + W * W));
    double height = std::sqrt((D * D) * (H * H) / (H * H + W * W));

    std::cout << static_cast<int>(height) << " " << static_cast<int>(width);

    return 0;
}