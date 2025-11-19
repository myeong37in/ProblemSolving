/*
중심점을 기준으로 보면 되겠군

상태는 위치, 방향으로 3가지
*/

#include <iostream>
#include <vector>
#include <queue>

struct State {
    int r, c, dir, dist;
};

std::vector<std::vector<char>> board;
std::vector<std::vector<std::vector<bool>>> visited;

int N;

int bfs(int sr, int sc, int sdir, int er, int ec, int edir) {
    std::queue<State> q;
    q.push({sr, sc, sdir, 0});
    visited[sr][sc][sdir] = true;

    while (!q.empty()) {
        auto [cr, cc, cdir, dist] = q.front();
        q.pop();

        // std::cout << cr << " " << cc << " " << cdir << " " << dist << "\n";

        if (cr == er && cc == ec && cdir == edir) {
            return dist;
        }

        // 'U'
        int nr = cr - 1;
        int nc = cc;
        int ndir = cdir;
        if (cdir == 0) {
            if (nr >= 0 && !visited[nr][nc][ndir] && 
                nr - 1 >= 0 && board[nr - 1][nc] != '1' &&
                board[nr][nc] != '1' &&
                nr + 1 < N && board[nr + 1][nc] != '1'
            ) {
                q.push({nr, nc, ndir, dist + 1});
                visited[nr][nc][ndir] = true;
            }
        }
        else {
            if (nr >= 0 && !visited[nr][nc][ndir] && 
                nc - 1 >= 0 && board[nr][nc - 1] != '1' &&
                board[nr][nc] != '1' &&
                nc + 1 < N && board[nr][nc + 1] != '1'
            ) {
                q.push({nr, nc, ndir, dist + 1});
                visited[nr][nc][ndir] = true;
            }
        }

        // 'D'
        nr = cr + 1;
        nc = cc;
        ndir = cdir;
        if (cdir == 0) {
            if (nr < N && !visited[nr][nc][ndir] && 
                nr - 1 >= 0 && board[nr - 1][nc] != '1' &&
                board[nr][nc] != '1' &&
                nr + 1 < N && board[nr + 1][nc] != '1'
            ) {
                q.push({nr, nc, ndir, dist + 1});
                visited[nr][nc][ndir] = true;
            }
        }
        else {
            if (nr < N && !visited[nr][nc][ndir] && 
                nc - 1 >= 0 && board[nr][nc - 1] != '1' &&
                board[nr][nc] != '1' &&
                nc + 1 < N && board[nr][nc + 1] != '1'
            ) {
                q.push({nr, nc, ndir, dist + 1});
                visited[nr][nc][ndir] = true;
            }
        }

        // 'L'
        nr = cr;
        nc = cc - 1;
        ndir = cdir;
        if (cdir == 0) {
            if (nc >= 0 && !visited[nr][nc][ndir] && 
                nr - 1 >= 0 && board[nr - 1][nc] != '1' &&
                board[nr][nc] != '1' &&
                nr + 1 < N && board[nr + 1][nc] != '1'
            ) {
                q.push({nr, nc, ndir, dist + 1});
                visited[nr][nc][ndir] = true;
            }
        }
        else {
            if (nc >= 0 && !visited[nr][nc][ndir] && 
                nc - 1 >= 0 && board[nr][nc - 1] != '1' &&
                board[nr][nc] != '1' &&
                nc + 1 < N && board[nr][nc + 1] != '1'
            ) {
                q.push({nr, nc, ndir, dist + 1});
                visited[nr][nc][ndir] = true;
            }
        }

        // 'R'
        nr = cr;
        nc = cc + 1;
        ndir = cdir;
        if (cdir == 0) {
            if (nc < N && !visited[nr][nc][ndir] && 
                nr - 1 >= 0 && board[nr - 1][nc] != '1' &&
                board[nr][nc] != '1' &&
                nr + 1 < N && board[nr + 1][nc] != '1'
            ) {
                q.push({nr, nc, ndir, dist + 1});
                visited[nr][nc][ndir] = true;
            }
        }
        else {
            if (nc < N && !visited[nr][nc][ndir] && 
                nc - 1 >= 0 && board[nr][nc - 1] != '1' &&
                board[nr][nc] != '1' &&
                nc + 1 < N && board[nr][nc + 1] != '1'
            ) {
                q.push({nr, nc, ndir, dist + 1});
                visited[nr][nc][ndir] = true;
            }
        }

        // 'T'
        ndir = !cdir;
        bool blocked = false;
        for (nr = cr - 1; nr <= cr + 1; nr++) {
            for (nc = cc - 1; nc <= cc + 1; nc++) {
                if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == '1') {
                    blocked = true;
                    break;
                }
            }

            if (blocked) {
                break;
            }
        }

        if (!blocked && !visited[cr][cc][ndir]) {
            q.push({cr, cc, ndir, dist + 1});
            visited[cr][cc][ndir] = true;
        }
    }

    return -1;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;

    board.assign(N, std::vector<char> (N));
    visited.assign(N, std::vector<std::vector<bool>> (N, std::vector<bool> (2)));

    std::string line;
    for (int r = 0; r < N; r++) {
        std::cin >> line;
        for (int c = 0; c < N; c++) {
            board[r][c] = line[c];
        }
    }

    bool start_found = false, end_found = false;
    int sr, sc, sdir, er, ec, edir;
    // 위치 찾기
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (start_found && end_found) {
                break;
            }

            if (!start_found && board[r][c] == 'B') {
                if (r + 1 < N && board[r + 1][c] == 'B') { // 수직
                    sr = r + 1;
                    sc = c;
                    sdir = 0;
                }
                else { // 수평
                    sr = r;
                    sc = c + 1;
                    sdir = 1;
                }

                start_found = true;
            }

            if (!end_found && board[r][c] == 'E') {
                if (r + 1 < N && board[r + 1][c] == 'E') { // 수직
                    er = r + 1;
                    ec = c;
                    edir = 0;
                }
                else { // 수평
                    er = r;
                    ec = c + 1;
                    edir = 1;
                }

                end_found = true;
            }
        }

        if (start_found && end_found) {
            break;
        }
    }

    int ans = bfs(sr, sc, sdir, er, ec, edir);
    std::cout << (ans == -1 ? 0 : ans);

    return 0;
}