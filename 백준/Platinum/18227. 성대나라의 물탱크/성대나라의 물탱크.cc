/*
Euler Tour Technique의 이해를 굳혀 봅시다.

물을 채우는 횟수를 저장

update는 입력 A 1 증가
query는 A의 시작에서 끝점까지의 누적합. 이 사이에 업데이트가 들어오면 A도 같이 갱신됨.
답으로 횟수 * 트리에서의 깊이를 하면 되겠군
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;

std::vector<int> tree, div_start, div_end, depth;

void Update(int node, int start, int end, int idx, int val) {
    if (idx > end || idx < start) {
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

int Query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && right >= end) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return Query(node * 2, start, mid, left, right) + Query(node * 2 + 1, mid + 1, end, left, right);
}

int cnt = 0;

void dfs(int cur, int parent, int d) {
    div_start[cur] = ++cnt;
    depth[cur] = d;
    for (const int& next : graph[cur]) {
        if (next != parent) {
            dfs(next, cur, d + 1);
        }
    }
    div_end[cur] = cnt;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, C;
    std::cin >> N >> C;

    graph.resize(N + 1);
    div_start.resize(N + 1);
    div_end.resize(N + 1);
    depth.resize(N + 1);
    tree.resize(4 * N);
    int x, y;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    dfs(C, -1, 1);

    int Q;
    std::cin >> Q;

    int op, A;
    for (int i = 0; i < Q; i++) {
        std::cin >> op >> A;
        if (op == 1) {
            Update(1, 1, N, div_start[A], 1);
        }
        else {
            // 자료형 이슈
            std::cout << 1LL * depth[A] * Query(1, 1, N, div_start[A], div_end[A]) << "\n";
        }
    }

    return 0;
}