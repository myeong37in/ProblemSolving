/*
세그 트리 기초인 듯
*/

#include <iostream>
#include <vector>

std::vector<int> tree, seq;

constexpr int INF = 2e9;

void Build(int node, int start, int end) {
    if (start == end) {
        tree[node] = seq[start];
        return;
    }

    int mid = (start + end) / 2;
    Build(node * 2, start, mid);
    Build(node * 2 + 1, mid + 1, end);
    tree[node] = std::min(tree[node * 2], tree[node * 2 + 1]);
}

void Update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end) {
        return;
    }

    if (start == end) {
        tree[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    Update(node * 2, start, mid, idx ,val);
    Update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = std::min(tree[node * 2], tree[node * 2 + 1]);
}

int Query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return INF;
    }

    if (left <= start && right >= end) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return std::min(Query(node * 2, start, mid, left, right), Query(node * 2 + 1, mid + 1, end, left, right));
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    tree.resize(4 * N);
    seq.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }

    Build(1, 1, N);

    int M;
    std::cin >> M;

    int op, u, v;
    for (int i = 0; i < M; i++) {
        std::cin >> op >> u >> v;
        if (op == 1) {
            Update(1, 1, N, u, v);
        }
        else {
            std::cout << Query(1, 1, N, u, v) << "\n";
        }
    }

    return 0;
}