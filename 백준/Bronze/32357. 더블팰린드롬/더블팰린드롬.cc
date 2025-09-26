#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::string str;
    int palindrome_cnt = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> str;
        std::string half = str.substr(0, str.size() / 2);
        std::reverse(half.begin(), half.end());
        if (half == str.substr(str.size() / 2, std::string::npos)) {
            palindrome_cnt++;
        }
    }

    std::cout << palindrome_cnt * (palindrome_cnt - 1);

    return 0;
}