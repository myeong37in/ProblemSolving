#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int cnt = 0;
    while (n % 5 != 0 && n >= 0) {
        n -= 2;
        cnt++;
    }

    if (n < 0) {
        std::cout << -1;
    }
    else {
        std::cout << cnt + n / 5;
    }

    return 0;
}