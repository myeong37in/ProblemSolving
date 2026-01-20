#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N;
    std::cin >> N;

    if (N * N > 1e8) {
        std::cout << "Time limit exceeded";
    }
    else {
        std::cout << "Accepted";
    }

    return 0;
}