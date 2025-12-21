#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;

    char prev = '1';
    int ans = 0;
    for (char ch : str) {
        if (ch == prev) {
            ans += 5;
        }
        else {
            ans += 10;
        }

        prev = ch;
    }

    std::cout << ans;

    return 0;
}