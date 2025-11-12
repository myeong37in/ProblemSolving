/*
parity 안 바뀜

각 문자에 대해
홀수 길이: 짝수와 홀수 위치에 있는 개수가 같아야 함
짝수 길이: 짝수와 홀수 위치에 있는 개수가 모두 짝수여야 함. 가운데 오는 문자 하나 제외
*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::string str;
        std::cin >> n >> str;

        std::vector<int> odd_cnt(26), even_cnt(26);
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                odd_cnt[str[i] - 'a']++;
            }
            else {
                even_cnt[str[i] - 'a']++;
            }
        }

        bool okay = true;
        if (n & 1) {
            bool one_coin = true; // 가운데 오는 문자 하나는 달라도 됨
            for (int i = 0; i < 26; i++) {
                int odd_parity = odd_cnt[i] & 1;
                int even_parity = even_cnt[i] & 1;

                if (odd_parity == 0 && even_parity == 0) {
                    continue;
                }
                else if (one_coin) {
                    one_coin = false;
                }
                else {
                    okay = false;
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < 26; i++) {
                if (odd_cnt[i] != even_cnt[i]) {
                    okay = false;
                    break;
                }
            }
        }

        std::cout << (okay ? "YES\n" : "NO\n");
    }

    return 0;
}