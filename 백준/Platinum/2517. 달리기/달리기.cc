/*
N개의 수를 압축해서 1번에서 N번까지 부여

누적 합 세그먼트 트리 구성

원래 순서대로 매핑된 숫자 i를 세그트리의 노드에 넣으면서(0->1)

자신보다 큰 수가 몇 개 있는지 쿼리 확인 Query(1, i - 1)

O(N logN)

unordered_map의 상수가 크긴 하군. 이분 탐색으로 ㄱㄱ
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> tree, seq, tmp;

static int Query(int node, int l, int r, int s, int e) {
    if (l > e || r < s) {
        return 0;
    }

    if (l <= s && e <= r) {
        return tree[node];
    }

    int m = s + (e - s) / 2;
    return Query(node * 2, l, r, s, m) + Query(node * 2 + 1, l, r, m + 1, e);
}

static void Update(int node, int idx, int s, int e) {
    if (idx < s || idx > e) {
        return;
    }

    if (s == e) {
        tree[node]++;
        return;
    }

    int m = s + (e - s) / 2;
    Update(node * 2, idx, s, m);
    Update(node * 2 + 1, idx, m + 1, e);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    int sz = 4 * N;

    tree.resize(sz);
    seq.resize(N + 1);
    tmp.resize(N);

    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
        tmp[i - 1] = seq[i];
    }

    std::sort(tmp.begin(), tmp.end(), std::greater<int>());

    for (int i = 1; i <= N; i++) {
        int order = std::lower_bound(tmp.begin(), tmp.end(), seq[i], std::greater<int>()) - tmp.begin() + 1;

        std::cout << Query(1, 1, order - 1, 1, N) + 1 << "\n"; // 등수 = 앞의 사람 수 + 1
        Update(1, order, 1, N);
    }
    
    return 0;
}