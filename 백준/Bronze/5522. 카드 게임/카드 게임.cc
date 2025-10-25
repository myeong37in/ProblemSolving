#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        std::cin >> n;
        sum += n;
    }

    std::cout << sum;

    return 0;
}