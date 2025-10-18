/*
하지만 세그먼트 트리가 출동한다면 어떨까

deque: O(N^2)
세그트리: O(N logN)
*/

#include <iostream>
#include <vector>

std::vector<int> tree;

void Build(int node, int start, int end) {
    if (start == end) {
        tree[node] = 1;
        return;
    }

    int mid = (start + end) / 2;
    Build(node * 2, start, mid);
    Build(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void Update(int node, int start, int end, int idx) {
    if (idx < start || idx > end) {
        return;
    }

    if (start == end) {
        tree[node] = 0;
        return;
    }

    int mid = (start + end) / 2;
    Update(node * 2, start, mid, idx);
    Update(node * 2 + 1, mid + 1, end, idx);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int Query(int node, int start, int end, int target) {
    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    if (tree[node * 2] >= target) {
        return Query(node * 2, start, mid, target);
    }
    else {
        return Query(node * 2 + 1, mid + 1, end, target - tree[node * 2]);
    }
}

int SumPrefix(int node, int start, int end, int idx) {
    if (idx < start) {
        return 0;
    }

    if (end <= idx) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return SumPrefix(node * 2, start, mid, idx) + SumPrefix(node * 2 + 1, mid + 1, end, idx);
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    if (N == 1) {
        std::cout << 1;
        return 0;
    }

    tree.resize(4 * N);

    Build(1, 1, N);

    long long turn = 1;
    int start_pos = 1;
    int rem = N;
    while (rem >= 2) {
        int moves = (turn * turn * turn) % rem;
        if (moves == 0) {
            moves = rem;
        }

        int target_pos = ((start_pos - 1) + (moves - 1)) % rem + 1;
        int cur_remove = Query(1, 1, N, target_pos);
        int pos = SumPrefix(1, 1, N, cur_remove);
        Update(1, 1, N, cur_remove);
        
        rem--;
        turn++;
        start_pos = pos;
    }

    std::cout << Query(1, 1, N, 1);

    return 0;
}