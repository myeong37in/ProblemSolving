#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int L, P;
    std::cin >> L >> P;

    int n;
    for (int i = 0; i < 5; i++) {
        std::cin >> n;
        std::cout << n - L * P << " ";
    }

    return 0;
}