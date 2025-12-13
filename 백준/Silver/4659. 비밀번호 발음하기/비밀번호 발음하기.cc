#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    while (std::cin >> str) {
        if (str == "end") {
            break;
        }

        bool has_vowel = false, three_of_a_kind = false, is_consecutive = false;
        int len = str.size();
        std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        for (int i = 0; i < len; i++) {
            for (char vowel : vowels) {
                if (str[i] == vowel) {
                    has_vowel = true;
                    break;
                }
            }

            if (has_vowel) {
                break;
            }
        }

        if (!has_vowel) {
            std::cout << "<" << str << "> is not acceptable.\n";
            continue;
        }

        if (len >= 3) {
            for (int s = 0; s < len - 2; s++) {
                std::string temp = str.substr(s, 3);
                int vowel_cnt = 0;
                for (char ch : temp) {
                    for (char vowel : vowels) {
                        if (ch == vowel) {
                            vowel_cnt++;
                        }
                    }
                }

                if (vowel_cnt == 3 || vowel_cnt == 0) {
                    three_of_a_kind = true;
                    break;
                }
            }
        }
        
        if (three_of_a_kind) {
            std::cout << "<" << str << "> is not acceptable.\n";
            continue;
        }

        if (len >= 2) {
            for (int s = 0; s < len - 1; s++) {
                std::string temp = str.substr(s, 2);
                if (temp[0] == temp[1] && temp[0] != 'e' && temp[0] != 'o') {
                    is_consecutive = true;
                    break;
                }
            }
        }

        if (is_consecutive) {
            std::cout << "<" << str << "> is not acceptable.\n";
            continue;
        }
        
        std::cout << "<" << str << "> is acceptable.\n";
    }

    return 0;
}