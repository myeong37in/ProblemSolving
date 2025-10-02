/*
0-1 BFS를 써볼까

기회 왔을 때 안 쓰면 언제 쓰겠어
*/

#include <iostream>
#include <deque>
#include <vector>
#include <string>

struct State {
    int r, c, d;
};

std::vector<std::vector<char>> board;
std::vector<std::vector<int>> dists;

std::vector<int> dr = {-1, 0, 1, 1, 1, 0, -1, -1};
std::vector<int> dc = {1, 1, 1, 0, -1, -1, -1, 0};

int bfs(int sr, int sc, int er, int ec) {
    int H = board.size();
    int W = board[0].size();
    std::deque<State> deq;
    deq.push_back({sr, sc, 0});
    dists[sr][sc] = 0;

    while (!deq.empty()) {
        auto [cr, cc, cd] = deq.front();
        deq.pop_front();

        if (cr == er && cc == ec) {
            return cd;
        }

        for (int dir = 0; dir < 8; dir++) { // 가중치 0
            int nr = cr + dr[dir];
            int nc = cc + dc[dir];

            if (nr < 0 || nr >= H || nc < 0 || nc >= W || board[nr][nc] == '#') {
                continue;
            }

            int w = (dir >= 3);
            if (dists[nr][nc] > dists[cr][cc] + w) {
                dists[nr][nc] = dists[cr][cc] + w;
                if (w == 0) {
                    deq.push_front({nr, nc, cd});
                }
                else {
                    deq.push_back({nr, nc, cd + 1});
                }
            }
        }
    }

    return -1;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W;
    std::cin >> H >> W;

    board.assign(H, std::vector<char> (W));
    dists.assign(H, std::vector<int> (W, 2e9));
    std::string line;
    int sr, sc, er, ec;
    for (int i = 0; i < H; i++) {
        std::cin >> line;
        for (int j = 0; j < W; j++) {
            board[i][j] = line[j];

            if (board[i][j] == 'K') {
                sr = i;
                sc = j;
            }
            else if (board[i][j] == '*') {
                er = i;
                ec = j;
            }
        }
    }

    int ans = bfs(sr, sc, er, ec);
    std::cout << ans;

    return 0;
}