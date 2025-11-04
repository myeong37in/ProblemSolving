/*
16959 + 교체 횟수 최소화

교체 횟수 배열을 별도로 들고 기준에 맞게 완화하면 됨
*/

#include <iostream>
#include <vector>
#include <queue>

struct State {
    int r, c, piece, next, time, change;
};

std::vector<int> rook_dr = {-1, 1, 0, 0};
std::vector<int> rook_dc = {0, 0, -1, 1};
std::vector<int> bishop_dr = {-1, -1, 1, 1};
std::vector<int> bishop_dc = {-1, 1, -1, 1};
std::vector<int> knight_dr = {-2, -2, 2, 2, -1, 1, -1, 1};
std::vector<int> knight_dc = {-1, 1, -1, 1, -2, -2, 2, 2};

std::vector<std::vector<int>> board;
std::vector<std::vector<std::vector<std::vector<int>>>> dists, changes; // 시간, 교체 횟수

void bfs(int sr, int sc, int N) {
    std::queue<State> q;
    // 세 명 모두에서 시작
    q.push({sr, sc, 0, 2, 0});
    q.push({sr, sc, 1, 2, 0});
    q.push({sr, sc, 2, 2, 0});
    dists[sr][sc][0][2] = dists[sr][sc][1][2] = dists[sr][sc][2][2] = changes[sr][sc][0][2] = changes[sr][sc][1][2] = changes[sr][sc][2][2] = 0;

    while (!q.empty()) {
        auto [r, c, piece, next, time, change] = q.front();
        q.pop();

        if (next > N * N) {
            continue;
        }

        if (piece == 0) { // rook
            // 이동
            // 소요 시간이 줄거나 시간 같고 교체 횟수가 줄면 넣기
            for (int dist = 1; dist <= N; dist++) {
                for (int dir = 0; dir < 4; dir++) {
                    int nr = r + rook_dr[dir] * dist;
                    int nc = c + rook_dc[dir] * dist;

                    if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                        continue;
                    }
                    
                    int nxt = next;
                    if (board[nr][nc] == next) {
                        nxt++;
                    }

                    if (dists[nr][nc][0][nxt] > time + 1 || (dists[nr][nc][0][nxt] == time + 1 && changes[nr][nc][0][nxt] > change)) {
                        dists[nr][nc][0][nxt] = time + 1;
                        changes[nr][nc][0][nxt] = change;

                        q.push({nr, nc, 0, nxt, time + 1, change});
                    }
                }
            }

            // 교체
            if (dists[r][c][1][next] > time + 1 || (dists[r][c][1][next] == time + 1 && changes[r][c][1][next] > change + 1)) {
                dists[r][c][1][next] = time + 1;
                changes[r][c][1][next] = change + 1;

                q.push({r, c, 1, next, time + 1, change + 1});
            }

            if (dists[r][c][2][next] > time + 1 || (dists[r][c][2][next] == time + 1 && changes[r][c][2][next] > change + 1)) {
                dists[r][c][2][next] = time + 1;
                changes[r][c][2][next] = change + 1;

                q.push({r, c, 2, next, time + 1, change + 1});
            }
        }
        else if (piece == 1) { // bishop
            // 이동
            for (int dist = 1; dist <= N; dist++) {
                for (int dir = 0; dir < 4; dir++) {
                    int nr = r + bishop_dr[dir] * dist;
                    int nc = c + bishop_dc[dir] * dist;

                    if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                        continue;
                    }

                    int nxt = next;
                    if (board[nr][nc] == next) {
                        nxt++;
                    }

                    if (dists[nr][nc][1][nxt] > time + 1 || (dists[nr][nc][1][nxt] == time + 1 && changes[nr][nc][1][nxt] > change)) {
                        dists[nr][nc][1][nxt] = time + 1;
                        changes[nr][nc][1][nxt] = change;

                        q.push({nr, nc, 1, nxt, time + 1, change});
                    }
                }
            }

            // 교체
            if (dists[r][c][0][next] > time + 1 || (dists[r][c][0][next] == time + 1 && changes[r][c][0][next] > change + 1)) {
                dists[r][c][0][next] = time + 1;
                changes[r][c][0][next] = change + 1;

                q.push({r, c, 0, next, time + 1, change + 1});
            }

            if (dists[r][c][2][next] > time + 1 || (dists[r][c][2][next] == time + 1 && changes[r][c][2][next] > change + 1)) {
                dists[r][c][2][next] = time + 1;
                changes[r][c][2][next] = change + 1;

                q.push({r, c, 2, next, time + 1, change + 1});
            }
        }
        else { // knight
            // 이동
            for (int dir = 0; dir < 8; dir++) {
                int nr = r + knight_dr[dir];
                int nc = c + knight_dc[dir];

                if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                    continue;
                }

                int nxt = next;
                if (board[nr][nc] == next) {
                    nxt++;
                }

                if (dists[nr][nc][2][nxt] > time + 1 || (dists[nr][nc][2][nxt] == time + 1 && changes[nr][nc][2][nxt] > change)) {
                    dists[nr][nc][2][nxt] = time + 1;
                    changes[nr][nc][2][nxt] = change;

                    q.push({nr, nc, 2, nxt, time + 1, change});
                }
            }

            // 교체
            if (dists[r][c][0][next] > time + 1 || (dists[r][c][0][next] == time + 1 && changes[r][c][0][next] > change + 1)) {
                dists[r][c][0][next] = time + 1;
                changes[r][c][0][next] = change + 1;

                q.push({r, c, 0, next, time + 1, change + 1});
            }

            if (dists[r][c][1][next] > time + 1 || (dists[r][c][1][next] == time + 1 && changes[r][c][1][next] > change + 1)) {
                dists[r][c][1][next] = time + 1;
                changes[r][c][1][next] = change + 1;

                q.push({r, c, 1, next, time + 1, change + 1});
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    board.assign(N, std::vector<int> (N));
    int sr, sc;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            std::cin >> board[r][c];

            if (board[r][c] == 1) {
                sr = r;
                sc = c;
            }
        }
    }

    constexpr int INF = 2e9;
    dists.assign(N, std::vector<std::vector<std::vector<int>>> (N, std::vector<std::vector<int>> (3, std::vector<int> (N * N + 2, INF))));
    changes.assign(N, std::vector<std::vector<std::vector<int>>> (N, std::vector<std::vector<int>> (3, std::vector<int> (N * N + 2, INF))));

    bfs(sr, sc, N);
    
    int best_time = INF, best_change = INF;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            for (int piece = 0; piece < 3; piece++) {
                int time = dists[r][c][piece][N * N + 1];
                int change = changes[r][c][piece][N * N + 1];

                if (best_time > time || (best_time == time && best_change > change)) {
                    best_time = time;
                    best_change = change;
                }
            }
        }
    }

    std::cout << best_time << " " << best_change;

    return 0;
}