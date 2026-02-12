/*
Kruskal인 듯?

모든 정점을 잇는 마지막 간선 길이의 절반이 최적(절반씩 나눠갖기)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

struct Edge {
    int s;
    int e;
    long long dist_square;
};

std::vector<int> parents, ranks;

static int Find(int n) {
    if (parents[n] == n) {
        return n;
    }

    return parents[n] = Find(parents[n]);
}

static void Merge(int a, int b) {
    int ra = Find(a);
    int rb = Find(b);

    if (ra == rb) {
        return;
    }

    if (ranks[ra] < ranks[rb]) {
        std::swap(ra, rb);
    }

    parents[rb] = ra;
    if (ranks[ra] == ranks[rb]) {
        ranks[ra]++;
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].first >> points[i].second;
    }

    parents.resize(n);
    ranks.resize(n);
    for (int i = 0; i < n; i++) {
        parents[i] = i;
    }

    std::vector<Edge> edges;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            long long dx = points[j].first - points[i].first;
            long long dy = points[j].second - points[i].second;
            long long dist_square = dx * dx + dy * dy;
            edges.emplace_back(Edge {i, j, dist_square});
        }
    }

    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.dist_square < b.dist_square;
    });

    long long ans_square = 9e18;
    for (const auto& [s, e, dist_square] : edges) {
        if (Find(s) != Find(e)) {
            Merge(s, e);
            ans_square = dist_square;
        }
    }

    std::cout << std::fixed << std::setprecision(7) << std::sqrt(ans_square) / 2;
    
    return 0;
}