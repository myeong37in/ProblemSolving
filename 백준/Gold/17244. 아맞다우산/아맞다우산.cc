/*
조합 5! = 32, 각 조합마다 4NM으로 6번

32 * 4 * 50 * 50 * 6 = 192만
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

struct State {
    int r, c, dist;
};

std::vector<std::vector<char>> board;
std::vector<std::vector<int>> visited;
std::vector<std::pair<int, int>> goods;

std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};

int N, M;
int visit_cnt = 1;
int exit_r, exit_c;

int bfs(int sr, int sc, int er, int ec) {
    std::queue<State> q;
    q.push({sr, sc, 0});
    visited[sr][sc] = visit_cnt;

    while (!q.empty()) {
        auto [r, c, dist] = q.front();
        q.pop();

        if (r == er && c == ec) {
            return dist;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= M || nc < 0 || nc >= N) { // 입력이 왜..
                continue;
            }

            if (visited[nr][nc] == visit_cnt || board[nr][nc] == '#') {
                continue;
            }

            q.push({nr, nc, dist + 1});
            visited[nr][nc] = visit_cnt;
        }
    }

    return -1;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;

    int start_r, start_c;

    board.assign(M, std::vector<char> (N));
    visited.assign(M, std::vector<int> (N));
    std::string line;
    for (int i = 0; i < M; i++) {
        std::cin >> line;
        for (int j = 0; j < N; j++) {
            board[i][j] = line[j];
            if (board[i][j] == 'X') {
                goods.emplace_back(i, j);
            }
            else if (board[i][j] == 'E') {
                exit_r = i;
                exit_c = j;
            }
            else if (board[i][j] == 'S') {
                start_r = i;
                start_c = j;
            }
        }
    }

    int sz = goods.size();
    if (sz == 0) {
        std::cout << bfs(start_r, start_c, exit_r, exit_c);
        return 0;
    }

    std::vector<int> order(sz);
    for (int i = 0; i < sz; i++) {
        order[i] = i;
    }

    int best = 2e9;
    do {
        int sr = start_r, sc = start_c;
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            auto [goods_r, goods_c] = goods[order[i]];

            ans += bfs(sr, sc, goods_r, goods_c);
            sr = goods_r, sc = goods_c;
            visit_cnt++;
        }

        ans += bfs(sr, sc, exit_r, exit_c);
        best = std::min(best, ans);
        visit_cnt++;
    } while (std::next_permutation(order.begin(), order.end()));

    std::cout << best;

    return 0;
}