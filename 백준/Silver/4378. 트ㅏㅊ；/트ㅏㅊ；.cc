#include <iostream>
#include <unordered_map>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_map<char, char> um;
    um.insert({' ', ' '});
    
    um.insert({'1', '`'}); um.insert({'2', '1'}); um.insert({'3', '2'}); um.insert({'4', '3'});
    um.insert({'5', '4'}); um.insert({'6', '5'}); um.insert({'7', '6'}); um.insert({'8', '7'}); um.insert({'9', '8'});
    um.insert({'0', '9'}); um.insert({'-', '0'}); um.insert({'=', '-'});

    um.insert({'W', 'Q'}); um.insert({'E', 'W'}); um.insert({'R', 'E'}); um.insert({'T', 'R'}); um.insert({'Y', 'T'});
    um.insert({'U', 'Y'}); um.insert({'I', 'U'}); um.insert({'O', 'I'}); um.insert({'P', 'O'}); um.insert({'[', 'P'});
    um.insert({']', '['}); um.insert({'\\', ']'});

    um.insert({'S', 'A'}); um.insert({'D', 'S'}); um.insert({'F', 'D'}); um.insert({'G', 'F'}); um.insert({'H', 'G'});
    um.insert({'J', 'H'}); um.insert({'K', 'J'}); um.insert({'L', 'K'}); um.insert({';', 'L'}); um.insert({'\'', ';'});
    
    um.insert({'X', 'Z'}); um.insert({'C', 'X'}); um.insert({'V', 'C'}); um.insert({'B', 'V'}); um.insert({'N', 'B'});
    um.insert({'M', 'N'}); um.insert({',', 'M'}); um.insert({'.', ','}); um.insert({'/', '.'});

    std::string line;

    while (std::getline(std::cin, line)) {
        for (const char& ch : line) {
            std::cout << um[ch];
        }
        std::cout << "\n";
    }

    return 0;
}