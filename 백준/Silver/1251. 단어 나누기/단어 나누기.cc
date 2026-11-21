/*
최대 쪼개는 경우의 수: C(49, 2) = 1,176
단어 뒤집기, 합치기: O(전체 문자열 길이)
*/

#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string word;
    std::cin >> word;

    std::string ans = "{"; // "z"보다 뒤에 있음

    int len = word.size();
    for (int i = 1; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            std::string p1 = word.substr(0, i);
            std::string p2 = word.substr(i, j - i);
            std::string p3 = word.substr(j, std::string::npos);

            std::reverse(p1.begin(), p1.end());
            std::reverse(p2.begin(), p2.end());
            std::reverse(p3.begin(), p3.end());

            ans = std::min(ans, p1 + p2 + p3);
        }
    }

    std::cout << ans;

    return 0;
}