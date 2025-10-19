/*
DSU
*/

#include <iostream>
#include <vector>

std::vector<int> parent, rank;

int Find(int n) {
    if (n == parent[n]) {
        return n;
    }
    return parent[n] = Find(parent[n]);
}

void Merge(int a, int b) {
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

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    parent.resize(N + 1);
    rank.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    
    int u, v;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v;
        Merge(u, v);
    }

    int prev = 0;
    int cur;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> cur;
        if (Find(prev) != Find(cur)) {
            ans++;
        }

        prev = cur;
    }

    std::cout << ans - 1; // 최초 +1 제외

    return 0;
}