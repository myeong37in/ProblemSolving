#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::string stars(i, '*');
        std::cout << stars << "\n";
    }
    for (int i = N - 1; i >= 0; i--) {
        std::string stars(i, '*');
        std::cout << stars << "\n";
    }

    return 0;
}