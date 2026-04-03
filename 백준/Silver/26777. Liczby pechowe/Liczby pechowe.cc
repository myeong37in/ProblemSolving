/*
13자리까지 보면 되긴 함
*/

#include <iostream>
#include <string>

int ans = 0;
long long N;

static void backtrack(std::string str, int sum, int depth) {
    if (depth == 13) {
        if (sum != 13) {
            return;
        }

        if (std::stoll(str) > N) {
            return;
        }

        bool okay = false;
        for (int i = 0; i < 12; i++) {
            if (str[i] == '1' && str[i + 1] == '3') {
                okay = true;
                break;
            }
        }

        ans += okay;
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (sum + i > 13) {
            break;
        }

        backtrack(str + static_cast<char>(i + '0'), sum + i, depth + 1);
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    
    backtrack("", 0, 0);

    std::cout << ans;
    
    return 0;
}