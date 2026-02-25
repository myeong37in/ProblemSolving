/*
긴것부터 연결 그리디
knot 개수는 사용한 줄의 개수와 동일
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    int S;
    for (int tc = 1; tc <= N; tc++) {
        std::cin >> S;

        std::vector<int> reds, blues;
        std::string rope;
        for (int i = 0; i < S; i++) {
            std::cin >> rope;
            int len = std::stoi(rope.substr(0, rope.size() - 1));
            if (rope.back() == 'R') {
                reds.emplace_back(len);
            }
            else {
                blues.emplace_back(len);
            }
        }

        std::sort(reds.begin(), reds.end(), std::greater<int>());
        std::sort(blues.begin(), blues.end(), std::greater<int>());

        int sz = std::min(reds.size(), blues.size());
        int ans = 0;
        if (sz > 0) {
            for (int i = 0; i < sz; i++) {
                ans += reds[i] + blues[i];
            }
            ans -= 2 * sz;
        }

        std::cout << "Case #" << tc << ": " << ans << "\n";
    }
    
    return 0;
}