/*
최솟값은 계속 갱신

최솟값보다 큰 수가 나오면 계산 비교
*/

#include <iostream>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    int min_val = 2e9;
    int ans = 0;
    int n;
    for (int i = 0; i < N; i++) {
        std::cin >> n;
        if (n < min_val) {
            min_val = n;
        }
        else {
            ans = std::max(ans, n - min_val);
        }
    }

    std::cout << ans;

    return 0;
}