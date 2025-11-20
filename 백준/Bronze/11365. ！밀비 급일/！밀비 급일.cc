#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "END") {
            break;
        }

        std::reverse(line.begin(), line.end());
        std::cout << line << "\n";
    }

    return 0;
}