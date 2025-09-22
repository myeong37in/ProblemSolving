/*
Euler Tour Technique을 배워 봅시다.

DFS로 정점을 방문할 때마다 번호를 쌓기. 

진입 번호와 탈출 번호를 기록해서 임의 정점이 커버하는 정점 구간을 얻고 lazy propagation 업데이트
*/

#include <iostream>
#include <vector>

std::vector<int> div_start, div_end;
std::vector<long long> tree, lazy;
std::vector<std::vector<int>> graph;

int cnt = 0;

void PushDown(int node, int start, int end) {
    if (lazy[node] != 0) { 
        tree[node] += 1LL * (end - start + 1) * lazy[node];
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
        tree[node] += 1LL * (end - start + 1) * val;
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

void dfs(int cur, int par) {
    div_start[cur] = ++cnt;
    for (const int& next : graph[cur]) {
        if (next == par) {
            continue;
        }
        dfs(next, cur);
    }
    div_end[cur] = cnt; 
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    graph.resize(N + 1);
    int n;
    std::cin >> n; // -1 버리기
    for (int i = 2; i <= N; i++) {
        std::cin >> n;
        graph[i].emplace_back(n);
        graph[n].emplace_back(i);
    }

    div_start.resize(N + 1);
    div_end.resize(N + 1);
    dfs(1, -1);

    tree.resize(4 * N);
    lazy.resize(4 * N);
    int op, i, w;
    while (M--) {
        std::cin >> op;
        if (op == 1) {
            std::cin >> i >> w;
            Update(1, 1, N, div_start[i], div_end[i], w);
        }
        else {
            std::cin >> i;
            std::cout << Query(1, 1, N, div_start[i], div_start[i]) << "\n";
        }
    }

    return 0;
}