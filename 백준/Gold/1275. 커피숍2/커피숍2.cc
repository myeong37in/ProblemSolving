/*
ㅇㅇ
*/

#include <iostream>
#include <vector>

std::vector<int> seq;
std::vector<long long> tree;

static void Build(int node, int s, int e) {
    if (s == e) {
        tree[node] = seq[s];
        return;
    }

    int m = s + (e - s) / 2;
    Build(node * 2, s, m);
    Build(node * 2 + 1, m + 1, e);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

static void Update(int node, int idx, int s, int e, int val) {
    if (idx < s || idx > e) {
        return;
    }

    if (s == e) {
        tree[node] = val;
        return;
    }

    int m = s + (e - s) / 2;
    Update(node * 2, idx, s, m, val);
    Update(node * 2 + 1, idx, m + 1, e, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

static long long Query(int node, int l, int r, int s, int e) {
    if (l > e || r < s) {
        return 0;
    }

    if (l <= s && r >= e) {
        return tree[node];
    }

    int m = s + (e - s) / 2;
    return Query(node * 2, l, r, s, m) + Query(node * 2 + 1, l, r, m + 1, e);
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, Q;
    std::cin >> N >> Q;

    seq.resize(N + 1);

    int sz = 4 * N;
    tree.resize(sz);

    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }

    Build(1, 1, N);

    int x, y, a, b;
    for (int i = 0; i < Q; i++) {
        std::cin >> x >> y >> a >> b;
        if (x > y) {
            std::swap(x, y);
        }

        std::cout << Query(1, x, y, 1, N) << "\n";
        Update(1, a, 1, N, b);
    }
    
    return 0;
}