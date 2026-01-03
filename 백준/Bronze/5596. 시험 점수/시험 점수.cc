#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int S = 0, T = 0, n;
    for (int i = 0; i < 4; i++) {
        std::cin >> n;
        S += n;
    }

    for (int i = 0; i < 4; i++) {
        std::cin >> n;
        T += n;
    }

    std::cout << (S >= T ? S : T);

    return 0;
}