#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int L, A, B, C, D;
    std::cin >> L >> A >> B >> C >> D;

    std::cout << L - std::max((A + C - 1) / C, (B + D - 1) / D);

    return 0;
}