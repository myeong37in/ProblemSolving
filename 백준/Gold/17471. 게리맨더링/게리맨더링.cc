/*
나눠 보고 DFS로 연결 확인
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> pop;
std::vector<std::vector<int>> graph;

int best = 2e9;

void dfs(int cur, std::vector<int>& selected, std::vector<bool>& visited) {
    visited[cur] = true;

    for (const int& next : graph[cur]) {
        if (visited[next]) {
            continue;
        }

        // 선택하지 않은 구역이면 안 들어감
        if (std::find(selected.begin(), selected.end(), next) == selected.end()) {
            continue;
        }

        dfs(next, selected, visited);
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    pop.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> pop[i];
    }

    int cnt, v;
    graph.resize(N + 1);
    for (int u = 1; u <= N; u++) {
        std::cin >> cnt;
        for (int i = 0; i < cnt; i++) {
            std::cin >> v;
            graph[u].emplace_back(v);
        }
    }

    for (int A_cnt = 1; A_cnt <= N - 1; A_cnt++) { // A 선거구의 인원
        std::vector<int> selected(N);
        for (int i = N - 1; i >= N - A_cnt; i--) {
            selected[i] = 1;
        }

        do {
            std::vector<int> A_selected, B_selected;
            for (int i = 0; i < N; i++) {
                if (selected[i]) {
                    A_selected.emplace_back(i + 1);
                }
                else {
                    B_selected.emplace_back(i + 1);
                }
            }

            bool okay = true;
            std::vector<bool> visited(N + 1);
            dfs(A_selected[0], A_selected, visited);
            for (const int& n : A_selected) {
                if (!visited[n]) { // 방문하지 않은 구역이 있으면 모두 연결되지 않은 것
                    okay = false;
                    break;
                }
            }

            if (!okay) {
                continue;
            }

            std::fill(visited.begin(), visited.end(), false);
            dfs(B_selected[0], B_selected, visited);
            for (const int& n : B_selected) {
                if (!visited[n]) {
                    okay = false;
                    break;
                }
            }

            if (!okay) {
                continue;
            }

            int A_pop_sum = 0, B_pop_sum = 0;
            for (const int& n : A_selected) {
                A_pop_sum += pop[n];
            }
            for (const int& n : B_selected) {
                B_pop_sum += pop[n];
            }

            best = std::min(best, std::abs(A_pop_sum - B_pop_sum));
        } while (std::next_permutation(selected.begin(), selected.end()));
    }

    std::cout << (best == 2e9 ? -1 : best);

    return 0;
}