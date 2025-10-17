#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;

    if (str == "0") {
        std::cout << 0;
        return 0;
    }

    int L = str.size();
    std::string res;
    for (int i = L - 1; i >= 0; i -= 3) {
        char cur;
        if (i - 2 < 0) {
            cur = std::stoi(str.substr(0, i + 1), nullptr, 2) + '0';
            if (cur == '0') {
                break;
            }
        }
        else {
            cur = std::stoi(str.substr(i - 2, 3), nullptr, 2) + '0';
        }

        res += cur;
    }

    std::reverse(res.begin(), res.end());

    std::cout << res;

    return 0;
}