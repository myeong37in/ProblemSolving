/*
식물이 들어오면 양끝을 제외한 구간은 꽃이 필 수 있다.

임의 좌표에 대해 꽃이 필 수 있는 식물 수를 세그 트리에 저장

새로운 식물 심을 때 양끝 좌표에서 꽃이 필 수 있으므로 양끝의 식물 수 합을 답으로. 

이 좌표들은 꽃이 피므로 값이 0이 됨

구간 업데이트 -> lazy
*/

#include <iostream>
#include <vector>

constexpr int MAX = 1e5 + 1;

std::vector<int> tree, lazy;

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

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    tree.resize(MAX * 4);
    lazy.reserve(MAX * 4);
    
    int s, e;
    for (int i = 0; i < N; i++) {
        std::cin >> s >> e;

        if (e >= s + 2) { // 길이가 2면 꽃이 필 후보 자리 없음
            Update(1, 1, MAX, s + 1, e - 1, 1);
        }
        
        int st = Query(1, 1, MAX, s, s);
        int ed = Query(1, 1, MAX, e, e);
        std::cout << st + ed << "\n";
        Update(1, 1, MAX, s, s, -st);
        Update(1, 1, MAX, e, e, -ed);
    }

    return 0;
}