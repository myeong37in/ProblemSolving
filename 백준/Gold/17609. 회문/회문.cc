/*
다르면 양옆에서 삭제해 보고 다시 검사 -> 유사 회문 or 일반 문자열
*/

#include <iostream>
#include <string>

static inline bool IsPalindrome(const std::string& str) {
    int L = str.size();
    for (int i = 0; i < L / 2; i++) {
        if (str[i] != str[L - 1 - i]) {
            return false;
        }
    }

    return true;
}

int Check(const std::string& str) {
    int L = str.size();
    for (int i = 0; i < L / 2; i++) {
        if (str[i] != str[L - 1 - i]) { // 다르면 지워보기
            std::string front_removed_str = str.substr(0, i) + str.substr(i + 1, std::string::npos);
            std::string rear_removed_str = str.substr(0, L - 1 - i) + str.substr(L - i, std::string::npos);
            if (IsPalindrome(front_removed_str) || IsPalindrome(rear_removed_str)) {
                return 1;
            }
            else {
                return 2;
            }
        }
    }

    return 0;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    
    std::string str;
    while (T--) {
        std::cin >> str;
        std::cout << Check(str) << "\n";
    }

    return 0;
}