/*
N^2으로 간선 만들고 연결 요소 개수 구하기
*/

#include <iostream>
#include <vector>
#include <queue>

struct Tower {
    int x, y, r;
};

std::vector<std::vector<int>> adj_mat;

std::vector<bool> visited;

static inline double GetDistSquare(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

static void bfs(int start) {
    int N = adj_mat.size();
    std::queue<int> q;
    q.push({start});
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < N; i++) {
            if (!visited[i] && adj_mat[cur][i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        std::vector<Tower> towers(N);
        for (int i = 0; i < N; i++) {
            std::cin >> towers[i].x >> towers[i].y >> towers[i].r;
        }

        adj_mat.assign(N, std::vector<int> (N, 0));
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                auto [x1, y1, r1] = towers[i];
                auto [x2, y2, r2] = towers[j];

                int dist_square = GetDistSquare(x1, y1, x2, y2);
                if (dist_square <= (r1 + r2) * (r1 + r2)) {
                    adj_mat[i][j] = adj_mat[j][i] = 1;
                }
            }
        }

        visited.assign(N, false);
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                bfs(i);
                cnt++;
            }
        }

        std::cout << cnt << "\n";
    }

    return 0;
}