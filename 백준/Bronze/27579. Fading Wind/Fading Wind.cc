/*
그대로
*/

#include <iostream>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int h, k, v, s;
    std::cin >> h >> k >> v >> s;

    int ans = 0;
    while (h) {
        v += s;
        v -= std::max(1, v / 10);

        if (v >= k) {
            h++;
        }
        else {
            if (--h == 0) {
                v = 0;
            }
        }

        if (v <= 0) {
            h = 0;
            v = 0;
        }

        ans += v;
        if (s > 0) {
            s--;
        }
    }

    std::cout << ans;
    
    return 0;
}