/*
Dijkstra를 돌리면서 방향 전환 횟수를 구하면 될 듯
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct State {
    int r, c, dir, dir_change_cnt;
};

struct StateCmp {
    bool operator()(const State& a, const State& b) const {
        return a.dir_change_cnt > b.dir_change_cnt;
    }
};

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int W, H;
    std::cin >> W >> H;

    std::vector<std::vector<char>> board(H, std::vector<char> (W));
    std::string line;
    int sr = -1, sc = -1, er = -1, ec = -1;
    for (int r = 0; r < H; r++) {
        std::cin >> line;
        for (int c = 0; c < W; c++) {
            board[r][c] = line[c];

            if (board[r][c] == 'C') {
                if (sr == -1) {
                    sr = r;
                    sc = c;
                }
                else {
                    er = r;
                    ec = c;
                }
            }
        }
    }

    std::vector<int> dr = {-1, 0, 1, 0};
    std::vector<int> dc = {0, -1, 0, 1};

    constexpr int INF = 1e9;

    // change_cnts[r][c][dir]: 들어온 방향이 dir이면서 (r, c)에 도달했을 때 목표까지 가는 최소 방향 전환 횟수
    std::vector<std::vector<std::vector<int>>> change_cnts(H, std::vector<std::vector<int>> (W, std::vector<int> (4, INF)));

    std::priority_queue<State, std::vector<State>, StateCmp> pq;
    // 최초 4방향 탐색
    for (int sdir = 0; sdir < 4; sdir++) {
        pq.push({sr, sc, sdir, 0});
        change_cnts[sr][sc][sdir] = 0;
    }
    
    while (!pq.empty()) {
        auto [r, c, dir, dir_change_cnt] = pq.top();
        pq.pop();

        if (r == er && c == ec) {
            std::cout << dir_change_cnt;
            return 0;
        }

        if (change_cnts[r][c][dir] != dir_change_cnt) {
            continue;
        }

        for (int ndir = 0; ndir < 4; ndir++) {
            // 들어온 반대 방향으로는 못 감
            if (ndir == (dir + 2) % 4) {
                continue;
            }

            int nr = r + dr[ndir];
            int nc = c + dc[ndir];

            if (nr < 0 || nr >= H || nc < 0 || nc >= W || board[nr][nc] == '*') {
                continue;
            }

            int nxt_dir_change_cnt = dir_change_cnt + (dir != ndir);
            
            if (change_cnts[nr][nc][ndir] > nxt_dir_change_cnt) {
                change_cnts[nr][nc][ndir] = nxt_dir_change_cnt;
                pq.push({nr, nc, ndir, nxt_dir_change_cnt});
            }
        }
    }

    return 0;
}