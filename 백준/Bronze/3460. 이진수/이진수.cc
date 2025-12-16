#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int n;
        std::cin >> n;

        int pos = 0;
        while (n) {
            if (n & 1) {
                std::cout << pos << " ";
            }
            n >>= 1;
            pos++;
        }
        std::cout << "\n";
    }

    return 0;
}