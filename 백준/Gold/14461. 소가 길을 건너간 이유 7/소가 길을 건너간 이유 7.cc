/*
상태 3개로 하면 될 듯
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct State {
    int r, c, dist, cnt; // cnt: 길을 건넌 횟수의 3에 대한 나머지 0, 1, 2
};

std::vector<std::vector<int>> board;
std::vector<std::vector<std::vector<int>>> dists; // dists[r][c][t]: (r, c)에서 길을 건넌 횟수가 0, 1, 2일 때 최소 거리

std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};

constexpr int INF = 2e9;

auto cmp = [](const State& a, const State& b) {
    return a.dist > b.dist;
};

static void Dijkstra(int sr, int sc, int er, int ec, int N, int T) {
    std::priority_queue<State, std::vector<State>, decltype(cmp)> pq(cmp);
    pq.push({sr, sc, 0, 0});

    dists[sr][sc][0] = 0;

    while (!pq.empty()) {
        auto [cr, cc, dist, cnt] = pq.top();
        pq.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = cr + dr[dir];
            int nc = cc + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                continue;
            }

            int ncnt = (cnt + 1) % 3;
            int ndist = dists[cr][cc][cnt] + T;
            if (ncnt == 0) { // 먹어야 함
                ndist += board[nr][nc];
                if (dists[nr][nc][ncnt] > ndist) {
                    dists[nr][nc][ncnt] = ndist;
                    pq.push({nr, nc, ndist, ncnt});
                }
            }
            else {
                if (dists[nr][nc][ncnt] > ndist) {
                    dists[nr][nc][ncnt] = ndist;
                    pq.push({nr, nc, ndist, ncnt});
                }
            }
        }
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, T;
    std::cin >> N >> T;

    board.assign(N, std::vector<int> (N));
    dists.assign(N, std::vector<std::vector<int>> (N, std::vector<int> (3, INF)));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            std::cin >> board[r][c];
        }
    }

    Dijkstra(0, 0, N - 1, N - 1, N, T);

    std::cout << std::min({dists[N - 1][N - 1][0], dists[N - 1][N - 1][1], dists[N - 1][N - 1][2]});

    return 0;
}