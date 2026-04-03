/*
조건 별로 하나씩
*/

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;

    std::string str;
    while (T--) {
        std::cin >> str;
        
        if (str[0] != 'A' && str[0] != 'B' && str[0] != 'C' && str[0] != 'D' && str[0] != 'E' && str[0] != 'F') {
            std::cout << "Good\n";
            continue;
        }

        if (str[0] != 'A' && str[1] != 'A') {
            std::cout << "Good\n";
            continue;   
        }

        int pos = (str[0] == 'A' ? 0 : 1);

        while (pos < str.size() && str[pos] == 'A') {
            pos++;
        }
        if (pos >= str.size() || str[pos] != 'F') {
            std::cout << "Good\n";
            continue;
        }

        while (pos < str.size() && str[pos] == 'F') {
            pos++;
        }
        if (pos >= str.size() || str[pos] != 'C') {
            std::cout << "Good\n";
            continue;
        }

        while (pos < str.size() && str[pos] == 'C') {
            pos++;
        }
    
        // 뒤에 문자가 최대 하나만 있어야 함
        if (pos + 1 < str.size()) {
            std::cout << "Good\n";
            continue;
        }

        if (pos >= str.size()) {
            std::cout << "Infected!\n";
            continue;
        }

        if (str[pos] != 'A' && str[pos] != 'B' && str[pos] != 'C' && str[pos] != 'D' && str[pos] != 'E' && str[pos] != 'F') {
            std::cout << "Good\n";
        }
        else {
            std::cout << "Infected!\n";
        }
    } 
    
    return 0;
}