/*
rotating calipers
좌표 평면 상에서 가장 먼 두 점은 볼록 껍질을 이루는 꼭짓점 쌍이다.

rotating calipers로 가장 먼 두 점을 찾는 방법에 대한 정합성 증명
https://stonejjun.tistory.com/140
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
};

long long GetCrossProduct(const Point& o, const Point& e, const Point& pt) {
    long long dx1 = e.x - o.x, dy1 = e.y - o.y;
    long long dx2 = pt.x - o.x, dy2 = pt.y - o.y;

    return dx1 * dy2 - dx2 * dy1;
}

long long GetEdgeCross(const std::vector<Point>& convex_hull, int i, int j) {
    int sz = convex_hull.size();
    Point a = {convex_hull[(i + 1) % sz].x - convex_hull[i].x, convex_hull[(i + 1) % sz].y - convex_hull[i].y};
    Point b = {convex_hull[(j + 1) % sz].x - convex_hull[j].x, convex_hull[(j + 1) % sz].y - convex_hull[j].y};

    return 1LL * a.x * b.y - 1LL * b.x * a.y;
}

long long GetDistSquare(const Point& a, const Point& b) {
    long long dx = b.x - a.x;
    long long dy = b.y - a.y;

    return dx * dx + dy * dy;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int n;
        std::cin >> n;

        std::vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            std::cin >> points[i].x >> points[i].y;
        }

        std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
            if (a.x == b.x) {
                return a.y < b.y;
            }
            return a.x < b.x;
        });

        std::vector<Point> lower_hull, upper_hull;
        for (int i = 0; i < n; i++) {
            const auto& pt = points[i];
            // 반례
            // 입력 (0, 0), (1, 1), (2, 2)
            // 정답: 0 0 2 2
            // 출력: 0 0 1 1
            // <= 0 조건으로 꼭짓점만 남기면 되려나
            while (lower_hull.size() >= 2 && GetCrossProduct(lower_hull[lower_hull.size() - 2], lower_hull.back(), pt) <= 0) {
                lower_hull.pop_back();
            }
            lower_hull.emplace_back(pt);
        }

        for (int i = n - 1; i >= 0; i--) {
            const auto& pt = points[i];
            while (upper_hull.size() >= 2 && GetCrossProduct(upper_hull[upper_hull.size() - 2], upper_hull.back(), pt) <= 0) {
                upper_hull.pop_back();
            }
            upper_hull.emplace_back(pt);
        }

        // 중복 제거
        lower_hull.pop_back();
        upper_hull.pop_back();

        std::vector<Point> convex_hull(lower_hull.begin(), lower_hull.end());
        convex_hull.insert(convex_hull.end(), upper_hull.begin(), upper_hull.end());

        // rotating calipers
        int sz = convex_hull.size();
        long long best = GetDistSquare(convex_hull[0], convex_hull[1]);
        int best_i = 0, best_j = 1;
        int j = 1;
        for (int i = 0; i < sz; i++) {
            long long dist;
            // CCW가 양수면 반시계 -> j를 전진. 음수면 i를 전진
            while ((j + 1) != i && GetEdgeCross(convex_hull, i, j) > 0) {
                dist = GetDistSquare(convex_hull[i], convex_hull[j]);
                if (best < dist) {
                    best_i = i;
                    best_j = j;
                    best = dist;
                }
                j = (j + 1) % sz;
            }

            dist = GetDistSquare(convex_hull[i], convex_hull[j]);
            if (best < dist) {
                best_i = i;
                best_j = j;
                best = dist;
            }
        }

        std::cout << convex_hull[best_i].x << " " << convex_hull[best_i].y << " " << convex_hull[best_j].x << " " << convex_hull[best_j].y << "\n";
    }

    return 0;
}