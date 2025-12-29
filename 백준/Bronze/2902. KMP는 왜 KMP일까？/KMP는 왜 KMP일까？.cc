#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    std::cin >> line;

    std::cout << line[0];
    int pos = 0;

    while ((pos = line.find('-', pos + 1)) != std::string::npos) {
        std::cout << line[pos + 1];
    }

    return 0;
}