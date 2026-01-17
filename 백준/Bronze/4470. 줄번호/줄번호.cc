#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::cin.ignore();

    std::string line;
    for (int i = 1; i <= N; i++) {
        std::getline(std::cin, line);
        std::cout << i << ". " << line << "\n";
    }

    return 0;
}