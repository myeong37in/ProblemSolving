#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "#") {
            break;
        }

        int cnt = 0;
        for (char& ch : line) {
            ch = std::tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                cnt++;
            }
        }

        std::cout << cnt << "\n";
    }

    return 0;
}