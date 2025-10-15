/*
간단한 세그트리
*/

#include <iostream>
#include <vector>

std::vector<long long> tree;

void Modify(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end) {
        return;
    }

    if (start == end) {
        tree[node] = val;
        return;
    }
    
    int mid = (start + end) / 2;
    Modify(node * 2, start, mid, idx, val);
    Modify(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long Sum(int node, int start, int end, int left, int right) {
    if (start > right || end < left) {
        return 0;
    }

    if (start >= left && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return Sum(node * 2, start, mid, left, right) + Sum(node * 2 + 1, mid + 1, end, left, right);
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N, M;
    std::cin >> N >> M;

    tree.resize(N * 4);
    int op, i, j;
    for (int t = 0; t < M; t++) {
        std::cin >> op >> i >> j;
        
        if (op == 0) {
            if (i > j) {
                std::swap(i, j);
            }
            std::cout << Sum(1, 1, N, i, j) << "\n";
        }
        else {
            Modify(1, 1, N, i, j);
        }
    }

    return 0;
}