#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    std::cin.ignore();

    std::string line;
    while (T--) {
        std::getline(std::cin, line);
        
        double num;

        int cur = line.find(' ', 0);
        num = std::stod(line.substr(0, cur));
        
        for (; cur < line.size(); cur++) {
            char op = line[cur];
            if (op == ' ') {
                continue;
            }
            else if (op == '@') {
                num *= 3;
            }
            else if (op == '%') {
                num += 5;
            }
            else if (op == '#') {
                num -= 7;
            }
        }

        std::cout << std::fixed << std::setprecision(2) << num << "\n";
    }

    return 0;
}