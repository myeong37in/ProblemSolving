/*
메모이제이션이 필요하긴 한데

어떤 정점에 도달했을 때 나올 수 있는 답은 두 가지임.
도착 정점과 연결된 정점들 중
1) 마력이 가장 큰 정점에서 왔을 경우
2) 그 외의 정점에서 왔을 경우

1번의 경우 두 번째로 마력이 큰 정점으로 갈 것이고
2번의 경우 마력이 가장 큰 정점으로 갈 것임

정점마다 마력이 모두 다르다는 조건도 있음

각 정점마다 두 개의 정점, 답 배열마다 두 개의 값
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;

std::vector<int> mp;

// first: 인접한 정점 중 마력이 가장 큰 정점, second: 두 번째
std::vector<std::pair<int, int>> top2_adj;

// first: 목적지가 이 정점일 때 타고 온 정점이 연결된 가장 마력이 큰 정점인 경우, second: 아닌 경우 
std::vector<std::pair<int, int>> ans;

static int dfs(int cur, int parent) {  
    // 리프 노드 도달
    if (graph[cur].size() == 1 && parent != 0) {
        return ans[cur].first;
    }

    if (top2_adj[cur].first == parent) {
        // 마력이 가장 큰 정점에서 온 경우
        if (ans[cur].first) {
            return ans[cur].first;
        }

        return ans[cur].first = dfs(top2_adj[cur].second, cur);
    }
    else {
        // 다른 정점에서 온 경우
        if (ans[cur].second) {
            return ans[cur].second;
        }

        // 가장 큰 정점으로
        return ans[cur].second = dfs(top2_adj[cur].first, cur);
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    mp.resize(N + 1);
    graph.resize(N + 1);
    top2_adj.resize(N + 1);
    ans.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        std::cin >> mp[i];
    }

    int u, v;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);

        // top2 갱신
        if (mp[v] > mp[top2_adj[u].first]) {
            top2_adj[u].second = top2_adj[u].first;
            top2_adj[u].first = v;
        }
        else if (mp[v] > mp[top2_adj[u].second]) {
            top2_adj[u].second = v;
        }

        if (mp[u] > mp[top2_adj[v].first]) {
            top2_adj[v].second = top2_adj[v].first;
            top2_adj[v].first = u;
        }
        else if (mp[u] > mp[top2_adj[v].second]) {
            top2_adj[v].second = u;
        }
    }

    for (int v = 1; v <= N; v++) {
        if (graph[v].size() == 1) {
            // 리프 노드인 경우 이 경로로 왔을 때 답은 이 노드
            ans[v].first = v;
        }
    }

    for (int i = 1; i <= N; i++) {
        std::cout << dfs(i, 0) << "\n";
    }
    
    return 0;
}