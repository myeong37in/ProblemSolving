#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    int a;
    int max_val = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> a;
        max_val = std::max(max_val, a);
    }

    std::cout << max_val;

    return 0;
}