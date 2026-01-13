/*
세그트리 O(N + M logN)
*/

#include <iostream>
#include <vector>

std::vector<int> seq, tree;

static void Build(int node, int s, int e) {
    if (s == e) {
        tree[node] = seq[s];
        return;
    }

    int m = (s + e) / 2;
    
    Build(node * 2, s, m);
    Build(node * 2 + 1, m + 1, e);
    
    tree[node] = std::min(tree[node * 2], tree[node * 2 + 1]);
}

static int Query(int node, int s, int e, int l, int r) {
    if (l > e || r < s) {
        return 2e9;
    }

    if (l <= s && r >= e) {
        return tree[node];
    }

    int m = (s + e) / 2;
    
    return std::min(Query(node * 2, s, m, l, r), Query(node * 2 + 1, m + 1, e, l, r));
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;

    seq.resize(N + 1);
    tree.resize(4 * N);

    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }

    Build(1, 1, N);
    
    int l, r;
    for (int i = 0; i < M; i++) {
        std::cin >> l >> r;
        
        std::cout << Query(1, 1, N, l, r) << "\n";
    }
    
    return 0;
}