/*
최대 2 * 10^18을 표현하려면 최소 26진법

a는 0, 나머지 1~25
*/

#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    if (T == 1) {
        long long A, B;
        std::cin >> A >> B;
        long long sum = A + B;
        
        std::string ans;
        while (sum) {
            int rem = sum % 26;
            ans += static_cast<char>(rem + 'a');
            sum /= 26;
        }
    
        while (ans.size() < 13) {
            ans += 'a';
        }

        std::reverse(ans.begin(), ans.end());

        std::cout << ans;
    }
    else {
        std::string str;
        std::cin >> str;

        long long ans = 0;
        long long mult = 1;
        for (int i = 12; i >= 0; i--) {
            char digit = str[i];
            if (digit == 'a') {
                mult *= 26;
                continue;
            }

            ans += mult * static_cast<int>(str[i] - 'a');
            mult *= 26;
        }
        std::cout << ans;
    }

    return 0;
}