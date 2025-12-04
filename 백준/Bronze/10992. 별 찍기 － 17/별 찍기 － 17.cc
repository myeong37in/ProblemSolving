#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    // 별 뒤에 공백이 있으면 안 되는구나
    for (int i = 0; i < N - 1; i++) {
        std::string line(N + i, ' ');
        line[N - 1 - i] = line[N - 1 + i] = '*';
        std::cout << line << "\n";
    }

    std::string line(2 * N - 1, '*');
    std::cout << line;

    return 0;
}