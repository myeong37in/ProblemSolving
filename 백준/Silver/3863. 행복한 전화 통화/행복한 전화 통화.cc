#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    while (std::cin >> N >> M) {
        if (N == 0) {
            break;
        }

        std::vector<std::pair<int, int>> calls(N);
        int dummy1, dummy2;
        for (int i = 0; i < N; i++) {
            std::cin >> dummy1 >> dummy2 >> calls[i].first >> calls[i].second;
        }

        int start, duration;
        for (int i = 0; i < M; i++) {
            std::cin >> start >> duration;

            int cnt = 0;
            for (const auto& [call_start, call_duration] : calls) {
                if (start + duration > call_start && call_start + call_duration > start) {
                    cnt++;
                }
            }

            std::cout << cnt << "\n";
        }
    }

    return 0;
}