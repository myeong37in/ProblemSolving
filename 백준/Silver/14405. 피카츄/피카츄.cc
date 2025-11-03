/*
문 자 열
*/

#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    std::cin >> S;
    int idx = 0;
    while (idx < S.size()) {
        if (idx + 1 <= S.size() && S.substr(idx, 2) == "pi" || S.substr(idx, 2) == "ka") {
            idx += 2;
        }
        else if (idx + 2 <= S.size() && S.substr(idx, 3) == "chu") {
            idx += 3;
        }
        else {
            std::cout << "NO";
            return 0;
        }
    }
    
    std::cout << "YES";

    return 0;
}