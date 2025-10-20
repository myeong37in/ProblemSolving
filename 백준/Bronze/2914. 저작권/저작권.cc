#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A, I;
    std::cin >> A >> I;

    std::cout << A * (I - 1) + 1;

    return 0;
}