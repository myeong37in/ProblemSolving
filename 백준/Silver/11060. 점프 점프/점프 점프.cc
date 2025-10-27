/*
BFS
*/

#include <iostream>
#include <vector>
#include <queue>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> seq(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }

    std::vector<bool> visited(N + 1);
    std::queue<std::pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();

        if (cur == N) {
            std::cout << dist;
            return 0;
        }

        for (int i = 1; i <= seq[cur]; i++) {
            if (cur + i <= N && !visited[cur + i]) {
                visited[cur + i] = true;
                q.push({cur + i, dist + 1});
            }
        }
    }

    std::cout << -1;

    return 0;
}