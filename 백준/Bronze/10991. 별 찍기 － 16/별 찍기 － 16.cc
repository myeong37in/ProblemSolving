#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::string line(N + i, ' ');
        for (int j = 0; j <= i; j++) {
            line[N + i - 1 - j * 2] = '*';
        }
        std::cout << line << "\n";
    }

    return 0;
}