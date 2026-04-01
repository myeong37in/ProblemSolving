#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string str;
    std::cin >> str;

    std::string fwd, bwd;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            fwd += str[i];
        }
    }

    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            bwd += str[i];
        }
    }

    std::cout << (fwd == bwd ? "S" : "N");
    
    return 0;
}