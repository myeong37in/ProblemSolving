/*
식별번호를 DAT로 두 번째 줄에서 숫자가 몇 번째에 있는지 체크

누적 합 세그먼트 트리를 구성

직관으로는 보이는데 글재주가 없어서 풀어쓰기가 어렵네

첫 번째 줄의 첫 번째 숫자부터 시작점 - 끝점(DAT로 얻음) 쌍에 대해

i번 숫자에서 i + 1번부터 N번까지에 대한 쿼리가 이 선을 그었을 때 겹치는 선의 개수임

그리고 세그먼트 트리에서 끝점에 해당하는 노드의 숫자를 1 증가

O(log N) 쿼리 100만 번
*/

#include <iostream>
#include <vector>

std::vector<int> tree, dat;

// 반환값: 최대 50만 - 1
static int Query(int node, int l, int r, int s, int e) {
    if (l > e || r < s) {
        return 0;
    }

    if (l <= s && r >= e) {
        return tree[node];
    }

    int m = s + (e - s) / 2;
    return Query(node * 2, l, r, s, m) + Query(node * 2 + 1, l, r, m + 1, e);
}

// 1 증가
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

    dat.resize(1'000'001);

    int sz = 4 * N;
    tree.resize(4 * N);

    std::vector<int> line1(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> line1[i];
    }

    int id;
    for (int i = 1; i <= N; i++) {
        std::cin >> id;
        dat[id] = i;
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        int s = line1[i];
        int e = dat[s];

        ans += Query(1, e + 1, N, 1, N);
        Update(1, e, 1, N);
    }

    std::cout << ans;
    
    return 0;
}