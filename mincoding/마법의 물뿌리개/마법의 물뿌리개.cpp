#include <iostream>
#include <vector>
int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        std::cin >> N;

        std::vector<int> heights(N);
        int hmax = 0;
        for (int i = 0; i < N; i++) {
            std::cin >> heights[i];
            hmax = std::max(hmax, heights[i]);
        }

        std::vector<int> growth(N);
        int total_growth = 0;
        int odd_cnt = 0;
        for (int i = 0; i < N; i++) {
            growth[i] = hmax - heights[i];
            total_growth += growth[i];
            if (growth[i] == 0) {
                continue;
            }

            if (growth[i] & 1) {
                odd_cnt++;
            }
        }

        if (total_growth == 0) {
            std::cout << "#" << t << " 0" << "\n";
            continue;
        }

        int quotient = (total_growth - 1) / 3;
        int rem = (total_growth - 1) % 3;

        int ans;
        if (rem == 0) {
            ans = 2 * quotient + 1;
        }
        else {
            ans = 2 * quotient + 2;
        }

        ans = std::max(ans, odd_cnt * 2 - 1);

        std::cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}