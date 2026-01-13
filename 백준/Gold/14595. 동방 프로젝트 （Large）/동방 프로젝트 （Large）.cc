/*
스위핑을 먼저 해서 중복된 구간 합치고

작은 수 <- 큰 수로 DSU 합친 다음 뒤에서부터 앞으로 오면서 부모 찾기, 부모가 다르면 부모로 점프

O(N + M)
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> parent;

static void Merge(int a, int b) {
    int ra = parent[a];
    int rb = parent[b];

    if (ra == rb) {
        return;
    }

    parent[rb] = ra;
    return;
}

static int Find(int u) {
    if (u == parent[u]) {
        return u;
    }
    return Find(parent[u]);
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int M;
    std::cin >> M;

    if (M == 0) {
        std::cout << N;
        return 0;
    }

    std::vector<std::pair<int, int>> tmp(M);
    for (int i = 0; i < M; i++) {
        std::cin >> tmp[i].first >> tmp[i].second;
    }

    std::sort(tmp.begin(), tmp.end(), [](const auto& a, const auto& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    // 스위핑으로 행동 정리
    std::vector<std::pair<int, int>> ops;
    int s = tmp[0].first, e = tmp[0].second;
    for (int i = 1; i < M; i++) {
        auto& [u, v] = tmp[i];

        if (u <= e) {
            e = std::max(e, v);
        }
        else {
            ops.emplace_back(s, e);
            s = u;
            e = v;
        }
    }
    ops.emplace_back(s, e);

    for (auto& [u, v] : ops) {
        Merge(u, v);
    }

    int ans = 0;
    for (int i = N; i >= 1; i--) {
        if (Find(i) != i) {
            i = Find(i);
        }
        ans++;
    }

    std::cout << ans;
    
    return 0;
}