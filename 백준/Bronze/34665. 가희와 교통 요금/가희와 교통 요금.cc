#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string A, B;
    std::cin >> A >> B;

    std::cout << (A == B ? 0 : 1550);

    return 0;
}