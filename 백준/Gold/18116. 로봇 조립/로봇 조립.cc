/*
간단한 DSU 문제
*/

#include <iostream>
#include <vector>

constexpr int MAX = 1e6;

std::vector<int> parent, rank, size;

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
    size[ra] += size[rb];

    if (rank[ra] == rank[rb]) {
        rank[ra]++;
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    parent.resize(MAX + 1);
    rank.resize(MAX + 1);
    size.assign(MAX + 1, 1);

    for (int i = 1; i <= MAX; i++) {
        parent[i] = i;
    }
    
    char op;
    int a, b, c;
    while (N--) {
        std::cin >> op;
        if (op == 'I') {
            std::cin >> a >> b;
            Merge(a, b);
        }
        else {
            std::cin >> c;
            std::cout << size[Find(c)] << "\n";
        }
    }

    return 0;
}