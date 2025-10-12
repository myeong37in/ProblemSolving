/*
아무리 봐도 N번 DFS가 문제의 의도로 보이는데
시간 제한 5초, O(N(N+M)) -> 10^9 연산
*/

#include <iostream>
#include <vector>

std::vector<int> visited;

int visit_count = 1; // fill을 쓰지 않고 초기화하는 트릭
int count = 0;
void dfs(const std::vector<std::vector<int>>& graph, const int& cur) {
    visited[cur] = visit_count;
    count++;

    for (const auto& next : graph[cur]) {
        if (visited[next] != visit_count) {
            dfs(graph, next);
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    int from, to;
    std::vector<std::vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        std::cin >> to >> from;
        graph[from].emplace_back(to);
    }
    visited.assign(N + 1, 0);

    std::vector<int> answer;
    int max = 0;
    for (int i = 1; i <= N; i++) {
        count = 0;
        dfs(graph, i);
        
        if (count > max) {
            max = count;
            answer.clear();
            answer.emplace_back(i);
        }
        else if (count == max) {
            answer.emplace_back(i);
        }
        visit_count++;
    }

    for (const int& n : answer) {
        std::cout << n << " ";
    }

    return 0;
}