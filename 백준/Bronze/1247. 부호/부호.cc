#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int tc = 1; tc <= 3; tc++) {
        long long N, num;
        std::cin >> N;

        __int128_t ans = 0;
        for (int i = 0; i < N; i++) {
            std::cin >> num;
            ans += num;
        }

        if (ans < 0) {
            std::cout << "-\n";
        }
        else if (ans > 0) {
            std::cout << "+\n";
        }
        else {
            std::cout << "0\n";
        }
    }

    return 0;
}