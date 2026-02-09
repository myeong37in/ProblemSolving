/*
동전은 2베, 주사위는 6배, 카드는 52배

long long으로 가능
*/

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    long long mult = 1;
    std::string str;
    for (int i = 0; i < N; i++) {
        std::cin >> str;
        if (str == "COIN") {
            mult *= 2;
        }
        else if (str == "DIE") {
            mult *= 6;
        }
        else if (str == "CARDS") {
            mult *= 52;
        }
    }

    long long L;
    std::cin >> L;

    std::cout << L * (mult - 1); // 이길 확률: 1/mult, 질 확률: (mult-1)/mult
    
    return 0;
}