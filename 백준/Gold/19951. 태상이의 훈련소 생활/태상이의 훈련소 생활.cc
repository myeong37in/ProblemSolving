/*
이거 lazy 아니에요?
*/

#include <iostream>
#include <vector>

std::vector<int> tree, lazy, seq;

void Build(int node, int start, int end) {
    if (start == end) {
        tree[node] = seq[start];
        return;
    }

    int mid = (start + end) / 2;
    Build(node * 2, start, mid);
    Build(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void PushDown(int node, int start, int end) {
    if (lazy[node]) {
        tree[node] += (end - start + 1) * lazy[node];

        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }
}

void Update(int node, int start, int end, int left, int right, int val) {
    PushDown(node, start, end);

    if (left > end || right < start) {
        return;
    }

    if (left <= start && right >= end) {
        tree[node] += (end - start + 1) * val;
        
        if (start != end) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }

        return;
    }

    int mid = (start + end) / 2;
    Update(node * 2, start, mid, left, right, val);
    Update(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int Query(int node, int start, int end, int left, int right) {
    PushDown(node, start, end);

    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && right >= end) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return Query(node * 2, start, mid, left, right) + Query(node * 2 + 1, mid + 1, end, left, right);
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    tree.resize(4 * N);
    lazy.resize(4 * N);
    seq.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }

    Build(1, 1, N);

    int a, b, k;
    for (int i = 0; i < M; i++) {
        std::cin >> a >> b >> k;
        Update(1, 1, N, a, b, k);
    }

    for (int i = 1; i <= N; i++) {
        std::cout << Query(1, 1, N, i, i) << " ";
    }

    return 0;
}