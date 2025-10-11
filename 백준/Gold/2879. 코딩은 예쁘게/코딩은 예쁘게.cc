/*
5837과 거의 비슷

+ 구간과 - 구간을 분리
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }

    std::vector<int> c(N);
    for (int i = 0; i < N; i++) {
        c[i] = b[i] - a[i];
    }

    int ans = 0;
    int prev_pos = 0;
    int prev_neg = 0;
    for (int i = 0; i < N; i++) {
        int pos = std::max(c[i], 0); // 필요한 +의 수
        int neg = std::max(-c[i], 0); // 필요한 -의 수
        
        ans += std::max(0, pos - prev_pos) + std::max(0, neg - prev_neg);

        prev_pos = pos;
        prev_neg = neg;
    }

    std::cout << ans;

    return 0;
}
