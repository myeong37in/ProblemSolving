/*
최대 8개 글자, 8! 미만(중복 있으므로)의 경우의 수
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string str;
    std::cin >> str;

    std::unordered_map<std::string, int> ones_um = {
                                                {"I", 1}, {"II", 2}, {"III", 3}, {"IV", 4}, {"V", 5}, 
                                                {"VI", 6}, {"VII", 7}, {"VIII", 8}, {"IX", 9}
                                              };

    std::unordered_map<std::string, int> tens_um = {
                                                {"X", 10}, {"XX", 20}, {"XXX", 30}, {"XL", 40}, {"L", 50}, 
                                                {"LX", 60}, {"LXX", 70}, {"LXXX", 80}, {"XC", 90}
                                              };                                    

    int sz = str.size();
    std::string ans_str = str;
    int ans_num = 2e9;
    std::sort(str.begin(), str.end());
    do {
        // 자체로 1~9
        if (ones_um.find(str) != ones_um.end()) {
            if (ans_num > ones_um[str]) {
                ans_num = ones_um[str];
                ans_str = str;
            }
        }

        // 자체로 10~90
        if (tens_um.find(str) != tens_um.end()) {
            if (ans_num > tens_um[str]) {
                ans_num = tens_um[str];
                ans_str = str;
            }
        }

        // 십의 자리 수 + 일의 자리 수
        for (int i = 1; i < sz; i++) {
            // Aㅏ...
            std::string head = str.substr(0, i);
            std::string rear = str.substr(i, sz - i);

            int cur = 0;

            // 둘 다 있는 수여야 함
            if (tens_um.find(head) != tens_um.end()) {
                cur += tens_um[head];
            }
            else {
                continue;
            }

            if (ones_um.find(rear) != ones_um.end()) {
                cur += ones_um[rear];
            }
            else {
                continue;
            }

            if (ans_num > cur) {
                ans_num = cur;
                ans_str = str;
            }
        }
    } while (std::next_permutation(str.begin(), str.end()));

    std::cout << ans_str;

    return 0;
}