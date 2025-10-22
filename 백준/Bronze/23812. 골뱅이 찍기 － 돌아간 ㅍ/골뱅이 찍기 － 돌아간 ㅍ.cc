/*
what..?
*/

#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << "@";
        }
        for (int j = 0; j < 3 * N; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < N; j++) {
            std::cout << "@";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5 * N; j++) {
            std::cout << "@";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << "@";
        }
        for (int j = 0; j < 3 * N; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < N; j++) {
            std::cout << "@";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5 * N; j++) {
            std::cout << "@";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << "@";
        }
        for (int j = 0; j < 3 * N; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < N; j++) {
            std::cout << "@";
        }
        std::cout << "\n";
    }

    return 0;
}