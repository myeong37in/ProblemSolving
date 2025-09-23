/*
별이 떨어지는 구간에서는 항상 이전 지점보다 1개 많은 별이 떨어짐

바로 이전 값보다 몇을 더했는지 세그 트리에 저장하면 update는 1을 일괄 적용으로 볼 수 있다.
그런데 그러면 구간 맨 뒤의 한 칸 뒤인 R + 1에는 구간 길이를 빼줘야 맞지.

query는 1부터 X까지의 구간합 + X번에 원래 있던 별의 수
*/

#include <iostream>
#include <vector>

std::vector<long long> tree, lazy, seq;

void PushDown(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];

        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }
}

void Update(int node, int start, int end, int left, int right, long long val) {
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

long long Query(int node, int start, int end, int left, int right) {
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

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    tree.resize(N * 4);
    lazy.resize(N * 4);
    seq.resize(N + 1);
    
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }

    int Q;
    std::cin >> Q;
    
    int op;
    while (Q--) {
        std::cin >> op;
        if (op == 1) {
            int L, R;
            std::cin >> L >> R;
            Update(1, 1, N, L, R, 1);
            Update(1, 1, N, R + 1, R + 1, -(R - L + 1));
        }
        else {
            int X;
            std::cin >> X;
            std::cout << seq[X] + Query(1, 1, N, 1, X) << "\n";
        }
    }

    return 0;
}