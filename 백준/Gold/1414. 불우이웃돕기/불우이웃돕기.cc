/*
Kruskal
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Edge {
    int from, to, weight;
};

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

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    parent.resize(N);
    rank.resize(N);
    size.assign(N, 1);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    std::vector<Edge> graph;
    std::string line;
    int all = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> line;
        for (int j = 0; j < N; j++) {
            char ch = line[j];
            int weight = 0;
            if (ch == '0') {
                continue;
            }
            else if (ch <= 'Z') {
                weight = ch - 'A' + 1 + 26;
            }
            else {
                weight = ch - 'a' + 1;
            }

            all += weight;
            graph.emplace_back(Edge {i, j, weight});
        }
    }

    std::sort(graph.begin(), graph.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    int total_edge = 0;
    int sz = graph.size();
    for (int i = 0; i < sz; i++) {
        auto [u, v, w] = graph[i];
        if (Find(u) != Find(v)) {
            Merge(u, v);
            total_edge += w;
        }
    }    

    if (size[Find(0)] != N) { // 모두 연결 X
        std::cout << -1;
        return 0;
    }

    std::cout << all - total_edge;

    return 0;
}