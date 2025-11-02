#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char ch;
    std::cin >> ch;

    if (ch == 'N' || ch == 'n') {
        std::cout << "Naver D2";
    }
    else {
        std::cout << "Naver Whale";
    }

    return 0;
}