#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int d1, d2;
    std::cin >> d1 >> d2;

    std::cout << std::fixed << std::setprecision(6) << 2.0 * 3.141592 * d2 + 2 * d1;

    return 0;
}