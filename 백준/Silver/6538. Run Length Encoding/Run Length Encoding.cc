#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    while (std::getline(std::cin, str)) {
        if (str.empty()) {
            std::cout << "\n";
            continue;
        }

        int L = str.size();
        int idx = 0;
        std::string res;
        while (idx < L) {
            int nxt = idx + 1;
            while (nxt < L && str[idx] == str[nxt]) {
                nxt++;
            }

            if (nxt == idx + 1) { // 연속 x
                int end = idx;
                while (end < L && (end + 1 == L || str[end] != str[end + 1])) { // 연속 반복이 없는 구간 끝까지 확장
                    end++;
                }
                
                res += '1';
                for (int i = idx; i < end; i++) {
                    if (str[i] == '1') {
                        res += "11";
                    }
                    else {
                        res += str[i];
                    }
                }
                res += '1';
                idx = end;
            }
            else { // 연속 o
                int end = idx;
                int cnt = nxt - idx;
                while (cnt >= 2) {
                    int chunk = std::min(9, cnt); // 한 번에 인코딩할 개수(최대 9)

                    res += static_cast<char>(chunk + '0');
                    res += str[end];

                    end += chunk;
                    cnt -= chunk;
                }

                idx = end;
            }
        }

        std::cout << res << "\n";
    }

    return 0;
}