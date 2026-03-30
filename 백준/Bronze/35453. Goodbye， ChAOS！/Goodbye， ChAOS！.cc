/*
Goodbye, chAOS!
*/

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;

    int N;
    std::string str;
    while (T--) {
        std::cin >> N;
        int hash = 1;
        
        for (int i = 0; i < N; i++) {
            std::cin >> str;
            hash *= str.size();
        }

        int ans = 0;
        if (hash == 232) {
            ans = 2017;
        }
        else if (hash == 88) {
            ans = 2018;
        }
        else if (hash == 754) {
            ans = 2019;
        }
        else if (hash == 29) {
            ans = 2020;
        }
        else if (hash == 28) {
            ans = 2021;
        }
        else if (hash == 1015) {
            ans = 2022;
        }
        else if (hash == 1295) {
            ans = 2023;
        }
        else if (hash == 1073) {
            ans = 2024;
        }
        else if (hash == 348) {
            ans = 2025;
        }
        else {
            ans = -1;
        }

        if (ans == -1) {
            std::cout << "Goodbye, ChAOS!\n";
        }
        else {
            std::cout << ans << "\n";
        }
    }
    
    return 0;
}