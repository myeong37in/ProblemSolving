#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> pears, apples;
    int kind;
    for (int i = 0; i < n; i++) {
        std::cin >> kind;
        if (kind == 0) {
            pears.emplace_back(i);
        }
        else {
            apples.emplace_back(i);
        }
    }

    int N = pears.size(), M = apples.size();
    int ans = 0;
    for (int i = 0; i < N; i++) {
        // 각 배마다 가장 좌측의 사과와의 거리, 우측의 사과와의 거리 비교
        ans = std::max(ans, std::max(std::abs(pears[i] - apples[0]), std::abs(pears[i] - apples[M - 1])));
    }

    std::cout << ans;
    
    return 0;
}