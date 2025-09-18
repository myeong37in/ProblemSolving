/*
그 시점에 먹을 수 있는 커피 중 최댓값을 골라야 하는데

최대 효용 커피에 대해 유통기한이 다 되거나 다 마시는 날까지 계산?

아 반례 발견
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Coffee {
    long long c, t, s;
};

auto cmp = [](const Coffee& a, const Coffee& b) {
    return a.s > b.s;
};

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        long long K;
        std::cin >> N >> K;

        std::vector<Coffee> vec; 
        long long a, b, c;
        for (int i = 0; i < N; i++) {
            std::cin >> a >> b >> c;
            b = std::min(b, K);
            vec.emplace_back(Coffee {a, b, c});
        }

        std::sort(vec.begin(), vec.end(), [](const Coffee& a, const Coffee& b) {
            return a.t < b.t;
        });

        // 만족도가 작은 걸 제거
        std::priority_queue<Coffee, std::vector<Coffee>, decltype(cmp)> pq(cmp);

        long long ans = 0;
        long long eat = 0;

        for (const auto& cof : vec) {
            pq.push(cof);

            eat += cof.c;
            ans += cof.c * cof.s;

            long long exceed = eat - cof.t;
            while (exceed > 0 && !pq.empty()) {
                auto [c, t, s] = pq.top();
                pq.pop();

                long long take = std::min(c, exceed);
                c -= take;
                eat -= take;
                exceed -= take;
                ans -= take * s;

                if (c) {
                    pq.push({c, t, s});
                }
            }
        }

        std::cout << "Case #" << tc << ": " <<  ans << "\n";
    }

    return 0;
}