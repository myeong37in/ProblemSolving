#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string target = "SciComLove";
    std::string S;
    std::cin >> S;

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += target[i] != S[i];
    }

    std::cout << ans;
    
    return 0;
}