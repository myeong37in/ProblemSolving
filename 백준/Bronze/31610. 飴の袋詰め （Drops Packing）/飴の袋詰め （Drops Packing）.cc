#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A, B, C;
    std::cin >> A >> B >> C;

    std::cout << A * B + C;

    return 0;
}