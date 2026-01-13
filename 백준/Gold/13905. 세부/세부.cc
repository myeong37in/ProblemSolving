/*
큰 가중치를 갖는 간선부터 DSU 합치면서 s와 e가 같은 부모를 가지면 끝

Kruskal
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Bridge {
    int from, to, weight;
};

std::vector<int> parent, rank;

static int Find(int u) {
    if (u == parent[u]) {
        return u;
    }
    return parent[u] = Find(parent[u]);
}

static void Merge(int a, int b) {
    int ra = Find(a);
    int rb = Find(b);

    if (ra == rb) {
        return;
    }

    if (rank[ra] < rank[rb]) {
        std::swap(ra, rb);
    }

    parent[rb] = ra;
    
    if (rank[ra] == rank[rb]) {
        rank[ra]++;
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M, s, e;
    std::cin >> N >> M >> s >> e;
    
    parent.resize(N + 1);
    rank.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    std::vector<Bridge> bridges(M);
    for (int i = 0; i < M; i++) {
        std::cin >> bridges[i].from >> bridges[i].to >> bridges[i].weight;
    }

    std::sort(bridges.begin(), bridges.end(), [](const Bridge& a, const Bridge& b) {
        return a.weight > b.weight;
    });

    for (int i = 0; i < M; i++) {
        auto& [u, v, w] = bridges[i];
        Merge(u, v);
        
        if (Find(s) == Find(e)) {
            std::cout << w;
            return 0;
        }
    }

    std::cout << 0; // 도달 불가?

    return 0;
}