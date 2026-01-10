#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    if (N == 1) {
        std::cout << "*";
        return 0;
    }

    std::string line1, line2;
    for (int i = 0; i < N; i++) {
        if ((i & 1) == 0) {
            line1 += '*';
            line2 += ' ';
        }
        else {
            line1 += ' ';
            line2 += '*';
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << line1 << "\n" << line2 << "\n";
    }

    return 0;
}