/*
구간을 빼기 시작하는 시작 지점의 개수

선형 스캔으로 이전 값보다 커지는 값만큼 횟수에 더하면 됨
*/

#include <iostream>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    long long ans = 0;
    int prev = 0;
    int x;
    for (int i = 0; i < N; i++) {
        std::cin >> x;
        ans += std::max(0, x - prev);
        prev = x;
    }

    std::cout << ans;

    return 0;
}