#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    std::cin >> line;

    int idx = 0;
    std::string ans = "";
    while (idx < line.size()) {
        if (line[idx] == '.') {
            ans += '.';
            idx++;
            continue;
        }

        int nxt = idx + 1;
        while (line[nxt] == 'X') {
            nxt++;
        }

        if ((nxt - idx) & 1) {
            std::cout << -1;
            return 0;
        }

        int X_cnt = (nxt - idx);
        int A_cnt = X_cnt / 4;
        for (int i = 0; i < A_cnt; i++) {
            ans += "AAAA";
        }

        int B_cnt = (X_cnt - 4 * A_cnt) / 2;
        for (int i = 0; i < B_cnt; i++) {
            ans += "BB";
        }

        idx = nxt;
    }

    std::cout << ans;

    return 0;
}