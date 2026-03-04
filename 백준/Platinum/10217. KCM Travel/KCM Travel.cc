/*
그냥 약간 응용 Dijkstra 같은데 정답률이 왜 이렇지 (아니었다 이 바보야)
최단 시간에 비용 차원을 추가

TLE 발생. N에 도달하면 멈추기?

다시 TLE. 다른 방법은?

와 미친
https://www.acmicpc.net/board/view/145922

        for (const auto& e : graph[cur_node]) {
            int next_dist = e.first + cur_dist;
            int next_node = e.second.first;
            int next_cost = e.second.second + cur_cost;

            if (next_cost > max_cost) {
                continue;
            }

여기서, 모든 현재 공항(cur_node)에 연결된 공항으로의 비용을 검사하는데, 처음에 그래프의 간선을 받을 때 하나의 출발지-도착지 쌍을 이루는 모든 간선을 비용 순으로 정렬한다면..?

비용을 priority_queue에 넣지 않고 하나의 노드에 대해 비용을 일괄 관리하면 더 빠르다는 코드 발견
*/

#define INF 1e9

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::vector<std::pair<int, std::pair<int, int>>>> graph;
std::vector<std::vector<int>> dists; // dists[i][j] = k: 비용 j로 i번 공항에 도착했을 때 k 시간 소요

void Dijkstra(const int& start, const int& max_cost, const int& destination) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, start}); // {시간, 도착지}
    std::fill(dists[start].begin(), dists[start].end(), 0);

    while (!pq.empty()) {
        auto p = pq.top();
        int cur_dist = p.first;
        int cur_node = p.second;
        pq.pop();

        if (cur_dist > dists[cur_node][max_cost]) {
            continue;
        }

        if (cur_node == destination) {
            return;
        }

        for (const auto& e : graph[cur_node]) {
            int edge_dist = e.first;
            int next_node = e.second.first;
            int edge_cost = e.second.second;

            if (edge_cost > max_cost) { // 정렬했으므로 간선의 비용이 최대 비용을 넘어서는 순간 컷
                break;
            }

            int prev_best = dists[next_node][max_cost];
            for (int i = 0; i + edge_cost <= max_cost; i++) {
                if (dists[cur_node][i] == INF) {
                    continue;
                }
                
                int next_dist = dists[cur_node][i] + edge_dist;
                if (next_dist < dists[next_node][i + edge_cost]) {
                    dists[next_node][i + edge_cost] = next_dist;
                }
            }

            if (dists[next_node][max_cost] < prev_best) {
                pq.push({dists[next_node][max_cost], next_node});
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    int N, M, K;
    std::cin >> N >> M >> K;
    graph.resize(N + 1);
    dists.assign(N + 1, std::vector<int> (M + 1, INF));

    int u, v, c, d;
    while (K--) {
        std::cin >> u >> v >> c >> d;
        graph[u].push_back({d, {v, c}}); // {시간, {도착지, 비용}}
    }

    for (int i = 1; i <= N; i++) {
        std::sort(graph[i].begin(), graph[i].end(), [](const auto& a, const auto& b) {
            return a.second.second < b.second.second; // 비용 기준 오름차순으로 정렬
        });
    }

    Dijkstra(1, M, N);

    int answer = dists[N][M];

    if (answer == INF) {
        std::cout << "Poor KCM";
    }
    else {
        std::cout << answer;
    }

    return 0;
}