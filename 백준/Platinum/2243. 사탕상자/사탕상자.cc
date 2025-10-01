/*
세그트리로 다시 풀어 봅시다.

개수 누적합 저장, 단일 update, 단일 쿼리

O(n log MAX)
*/

#include <iostream>
#include <vector>

constexpr int MAX = 1e6;

std::vector<int> tree;

void Update(int node, int start, int end, int idx, int val) {
    if (start > idx || end < idx) {
        return;
    }

    if (start == end) {
        tree[node] += val;
        return;
    }
    
    int mid = (start + end) / 2;
    Update(node * 2, start, mid, idx, val);
    Update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int Query(int node, int start, int end, int cnt) {
    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    if (tree[node * 2] >= cnt) {
        return Query(node * 2, start, mid, cnt);
    }
    else {
        return Query(node * 2 + 1, mid + 1, end, cnt - tree[node * 2]);
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    tree.resize(4 * MAX);

    int A, B, C;
    for (int i = 0; i < n; i++) {
        std::cin >> A >> B;
        if (A == 2) {
            std::cin >> C;
            Update(1, 1, MAX, B, C);
        }
        else {
            int res = Query(1, 1, MAX, B);
            Update(1, 1, MAX, res, -1);
            std::cout << res << "\n";
        }
    }

    return 0;
}