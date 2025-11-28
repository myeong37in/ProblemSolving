/*
위상 정렬인데 낮은 번호부터 -> pq 이용
*/

#include <iostream>
#include <vector>
#include <queue>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> graph(N + 1);
    std::vector<int> indegree(N + 1);

    int a, b;
    for (int i = 0; i < M; i++) {
        std::cin >> a >> b;
        graph[a].emplace_back(b);
        indegree[b]++;
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        std::cout << cur << " ";
    
        for (int next : graph[cur]) {
            indegree[next]--;

            if (indegree[next] == 0) {
                pq.push(next);
            }
        }
    }

    return 0;
}