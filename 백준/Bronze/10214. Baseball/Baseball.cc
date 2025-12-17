#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int Y = 0, K = 0;
        int s;
        for (int i = 0; i < 9; i++) {
            std::cin >> s;
            Y += s;
            std::cin >> s;
            K += s;
        }

        if (Y > K) {
            std::cout << "Yonsei\n";
        }
        else if (Y < K) {
            std::cout << "Korea\n";
        }
        else {
            std::cout << "Draw\n";
        }
    }

    return 0;
}