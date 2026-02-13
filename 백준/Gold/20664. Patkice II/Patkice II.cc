/*
격자 탐색

정해진 방향으로 가는 것은 비용 0, 그렇지 않은 3방향으로 가는 것은 비용 1

비용이 최소가 되는 경로를 고르면 되고 이때의 경로에 있는 화살표들을 바꾸면 될 듯

0-1 bfs

아니 무슨 역추적을 못해서 시간 초과를 받냐? 진짜 재능이 없네
*/

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <unordered_map>

struct State {
    int r, c, dist;
};

std::vector<std::vector<char>> board;
std::vector<std::vector<int>> dists;
std::vector<std::vector<std::pair<int, int>>> parent;

std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};

std::unordered_map<char, int> chardir_to_intdir = {{'.', -1}, {'^', 0}, {'v', 1}, {'<', 2}, {'>', 3}};
std::unordered_map<int, char> intdir_to_chardir = {{0, '^'}, {1, 'v'}, {2, '<'}, {3, '>'}};

constexpr int INF = 2e9;
int best_dist = INF;
std::vector<int> best_path;

static void bfs(int sr, int sc, int er, int ec, int R, int C) {
    std::deque<State> deq;
    
    // 최초 4방향 자유 이동
    for (int dir = 0; dir < 4; dir++) {
        int nr = sr + dr[dir];
        int nc = sc + dc[dir];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
            continue;
        }

        parent[nr][nc] = {sr, sc};
        dists[nr][nc] = 0;
        deq.push_back({nr, nc, 0});
    }
    dists[sr][sc] = -1; // 시작 지점으로 못 돌아가게

    while (!deq.empty()) {
        auto [r, c, dist] = deq.front();
        deq.pop_front();

        if (dists[r][c] < dist) {
            continue;
        }

        if (r == er && c == ec) {
            if (dist < best_dist) {
                best_dist = dist;
            }
            break;
        }

        int orig_dir = chardir_to_intdir[board[r][c]];

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                continue;
            }

            if (dir == orig_dir) {
                // 방향 유지
                if (dists[nr][nc] > dist) {
                    dists[nr][nc] = dist;
                    parent[nr][nc] = {r, c};
                    deq.push_front({nr, nc, dist});
                }
            }
            else {
                // 방향 변경
                if (dists[nr][nc] > dist + 1) {
                    dists[nr][nc] = dist + 1;
                    parent[nr][nc] = {r, c};
                    deq.push_back({nr, nc, dist + 1});
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int r, s;
    std::cin >> r >> s;
    
    board.assign(r, std::vector<char> (s));
    std::string line;
    int sr, sc, er, ec;
    for (int i = 0; i < r; i++) {
        std::cin >> line;
        for (int j = 0; j < s; j++) {
            board[i][j] = line[j];
            
            if (board[i][j] == 'o') {
                sr = i;
                sc = j;
            }
            else if (board[i][j] == 'x') {
                er = i;
                ec = j;
            }
        }
    }

    dists.assign(r, std::vector<int> (s, INF));
    parent.assign(r, std::vector<std::pair<int, int>> (s));
    bfs(sr, sc, er, ec, r, s);

    // 역추적
    int cr = er;
    int cc = ec;
    while (true) {
        auto& [nr, nc] = parent[cr][cc];

        if (nr == sr && nc == sc) {
            break;
        }

        for (int dir = 0; dir < 4; dir++) {
            if (nr + dr[dir] == cr && nc + dc[dir] == cc) {
                char ch = intdir_to_chardir[dir];
                if (board[nr][nc] != ch) {
                    board[nr][nc] = ch;
                }
                break;
            }
        }

        cr = nr;
        cc = nc;
    }

    std::cout << best_dist << "\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            std::cout << board[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}