#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int sum;
    std::cin >> sum;

    int n;
    for (int i = 0; i < 9; i++) {
        std::cin >> n;
        sum -= n;
    }

    std::cout << sum;

    return 0;
}