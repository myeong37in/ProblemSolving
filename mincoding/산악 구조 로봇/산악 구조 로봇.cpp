#include <iostream>
#include <vector>
#include <queue>

struct Cell {
    int dist;
    int row;
    int col;
};

auto cmp = [](const auto& a, const auto& b) {
    return a.dist > b.dist;
};

constexpr int INF = 2e9;

std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};

std::vector<std::vector<int>> board;

int Dijkstra(int start_row, int start_col) {
    int N = board.size();
    std::vector<std::vector<int>> dists(N, std::vector<int> (N, INF));

    std::priority_queue<Cell, std::vector<Cell>, decltype(cmp)> pq(cmp);

    dists[0][0] = 0;
    pq.push({0, start_row, start_col});
    while (!pq.empty()) {
        auto [dist, row, col] = pq.top();
        pq.pop();

        if (row == N - 1 && col == N - 1) {
            return dist;
        }

        if (dists[row][col] < dist) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                continue;
            }
            
            int next_dist;
            if (board[nr][nc] < board[row][col]) {
                next_dist = 0;
            }
            else if (board[nr][nc] > board[row][col]) {
                next_dist = (board[nr][nc] - board[row][col]) * 2;
            }
            else {
                next_dist = 1;
            }

            if (dists[nr][nc] <= dist + next_dist) {
                continue;
            }

            dists[nr][nc] = dist + next_dist;
            pq.push({dist + next_dist, nr, nc});
        }
    }

    return -1;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        std::cin >> N;

        board.assign(N, std::vector<int> (N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> board[i][j];
            }
        }

        int ans = Dijkstra(0, 0);
        std::cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}