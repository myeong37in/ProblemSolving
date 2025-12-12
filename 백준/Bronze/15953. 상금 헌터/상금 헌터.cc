#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int a, b;
        std::cin >> a >> b;

        int ans = 0;
        if (a == 0) {

        }
        else if (a == 1) {
            ans += 500;
        }
        else if (a <= 3) {
            ans += 300;
        }
        else if (a <= 6) {
            ans += 200;
        }
        else if (a <= 10) {
            ans += 50;
        }
        else if (a <= 15) {
            ans += 30;
        }
        else if (a <= 21) {
            ans += 10;
        }

        if (b == 0) {

        }
        else if (b == 1) {
            ans += 512;
        }
        else if (b <= 3) {
            ans += 256;
        }
        else if (b <= 7) {
            ans += 128;
        }
        else if (b <= 15) {
            ans += 64;
        }
        else if (b <= 31) {
            ans += 32;
        }

        std::cout << ans * 10000 << "\n";
    }

    return 0;
}