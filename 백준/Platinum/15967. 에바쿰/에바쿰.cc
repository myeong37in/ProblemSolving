/*
lazy 합
*/

#include <iostream>
#include <vector>

std::vector<int> seq;
std::vector<long long> tree, lazy;

static void PushDown(int node, int s, int e) {
    if (lazy[node] == 0) {
        return;
    }

    tree[node] += (e - s + 1) * lazy[node];
    if (s != e) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
}

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

static void Update(int node, int l, int r, int s, int e, int val) {
    PushDown(node, s, e);

    if (l > e || r < s) {
        return;
    }

    if (l <= s && e <= r) {
        tree[node] += (e - s + 1) * val;

        if (s != e) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }

        return;
    }

    int m = s + (e - s) / 2;
    Update(node * 2, l, r, s, m, val);
    Update(node * 2 + 1, l, r, m + 1, e, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

static long long Query(int node, int l, int r, int s, int e) {
    PushDown(node, s, e);

    if (l > e || r < s) {
        return 0;
    }

    if (l <= s && e <= r) {
        return tree[node];
    }

    int m = s + (e - s) / 2;
    return Query(node * 2, l, r, s, m) + Query(node * 2 + 1, l, r, m + 1, e);
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, Q1, Q2;
    std::cin >> N >> Q1 >> Q2;

    seq.resize(N + 1);
    tree.resize(4 * N);
    lazy.resize(4 * N);

    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }

    Build(1, 1, N);

    int q, s, e, l;
    for (int i = 0; i < Q1 + Q2; i++) {
        std::cin >> q >> s >> e;
        if (q == 1) {
            std::cout << Query(1, s, e, 1, N) << "\n";
        }
        else {
            std::cin >> l;
            Update(1, s, e, 1, N, l);
        }
    }
    
    return 0;
}