/*
절편 없고, 기울기가 같은 점들에 대해 x를 저장, 그러나 수직이면 y를 저장해야 고유성 유지

O((N + M) log N)

부동소수점 문제가 있는지 제출해서 확인해 보자 -> 있는 듯?
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <numeric>

constexpr long long VERTICAL = 9e18; // 수직의 기울기는 이 수로 취급
constexpr int INT_INF = 1e9;

// 중복 안 되게 잘. 음수도 양수화
auto pack = [](int x, int y) {
    return ((static_cast<long long>(y + INT_INF) << 32) | static_cast<long long>(x + INT_INF));
};

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_map<long long, std::vector<int>> um;

    int N, M;
    std::cin >> N >> M;

    int x, y;
    for (int i = 0; i < N; i++) {
        std::cin >> x >> y;
        long long slope = VERTICAL; 
        if (x != 0) {
            int dx = x;
            int dy = y;

            int gcd = std::gcd(dx, dy);
            dx /= gcd;
            dy /= gcd;

            // 이거 안 하면 (x, y)와 (-x, -y)가 다른 키로 패킹되는데
            if (dx < 0) {
                dx *= -1;
                dy *= -1;
            }
            slope = pack(dx, dy);
        }
        
        if (slope == VERTICAL) {
            um[slope].emplace_back(y);
        }
        else {
            um[slope].emplace_back(x);
        }
    }

    auto it = um.begin();
    for (; it != um.end(); it++) {
        auto& vec = it->second;
        std::sort(vec.begin(), vec.end());
    }

    int best = 0;
    for (int i = 0; i < M; i++) {
        std::cin >> x >> y;
        long long slope = VERTICAL; 
        if (x != 0) {
            int dx = x;
            int dy = y;

            int gcd = std::gcd(dx, dy);
            dx /= gcd;
            dy /= gcd;

            if (dx < 0) {
                dx *= -1;
                dy *= -1;
            }
            slope = pack(dx, dy);
        }

        int start, end;
        auto& vec = um[slope];
        
        if (slope == VERTICAL) {
            if (y < 0) {
                start = std::lower_bound(vec.begin(), vec.end(), y) - vec.begin();
                end = std::upper_bound(vec.begin(), vec.end(), 0) - vec.begin() - 1;
            }
            else {
                start = std::lower_bound(vec.begin(), vec.end(), 0) - vec.begin();
                end = std::upper_bound(vec.begin(), vec.end(), y) - vec.begin() - 1;
            }
        }
        else {
            if (x < 0) {
                start = std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
                end = std::upper_bound(vec.begin(), vec.end(), 0) - vec.begin() - 1;
            }
            else {
                start = std::lower_bound(vec.begin(), vec.end(), 0) - vec.begin();
                end = std::upper_bound(vec.begin(), vec.end(), x) - vec.begin() - 1;
            }
        }

        best = std::max(best, end - start + 1);
    }

    std::cout << best;

    return 0;
}