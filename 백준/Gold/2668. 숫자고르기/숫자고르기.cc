/*
사이클을 찾아

근데 이렇게 N <= 100인 걸 보니 정해가 이게 아닌 거 같은데? 
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> graph;
std::vector<bool> visited; // 중복 방문 방지 
std::vector<bool> finished; // 사이클 판정이 끝난 노드들
std::vector<int> in_cycle; // 방문했지만 끝나지 않은 노드들
std::vector<int> ans;

static void dfs(int cur) {
    visited[cur] = true;
    in_cycle.emplace_back(cur);

    int nxt = graph[cur];
    if (!visited[nxt]) {
        dfs(nxt);
    }
    else if (!finished[nxt]) { // 방문했지만 판정이 안 끝난 노드에 도달하면 해당 노드 nxt부터 cur까지 사이클 완성 
        for (int i = 0; i < in_cycle.size(); i++) {
            if (in_cycle[i] == nxt) {
                for (int j = i; j < in_cycle.size(); j++) {
                    ans.emplace_back(in_cycle[j]);
                }
                break;
            }
        }
    }

    finished[cur] = true;
    in_cycle.pop_back();

    return;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    graph.resize(N + 1);
    visited.resize(N + 1);
    finished.resize(N + 1);
    int n;
    for (int i = 1; i <= N; i++) {
        std::cin >> n;
        graph[i] = n;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    std::sort(ans.begin(), ans.end());

    std::cout << ans.size() << "\n";
    for (int n : ans) {
        std::cout << n << "\n";
    }

    return 0;
}