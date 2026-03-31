/*
대충 MST 간선 합에다가 1부터 연결 수 - 1까지 합한 것을 t를 곱해서

Kruskal로 해봅시다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int from, to, cost;
};

std::vector<int> parent, rank;

int cnt = 0; // MST를 이루는 간선 수

static int Find(int n) {
    if (parent[n] == n) {
        return n;
    }

    return parent[n] = Find(parent[n]);
}

static void Merge(int a, int b) {
    int ra = Find(a);
    int rb = Find(b);

    if (ra == rb) {
        return;
    }

    if (rank[ra] > rank[rb]) {
        std::swap(ra, rb);
    }
    
    parent[ra] = rb;
    if (rank[ra] == rank[rb]) {
        rank[rb]++;
    }
    cnt++;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M, t;
    std::cin >> N >> M >> t;

    parent.resize(N + 1);
    rank.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    std::vector<Edge> edges(M);
    int u, v, c;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v >> c;
        edges[i] = {u, v, c};
    }

    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.cost < b.cost;
    });

    int total = 0;
    for (int i = 0; i < M; i++) {
        auto& [u, v, c] = edges[i];
        if (Find(u) == Find(v)) {
            continue;
        }

        Merge(u, v);
        total += c;
    }

    std::cout << total + t * (cnt - 1) * cnt / 2;

    return 0;
}